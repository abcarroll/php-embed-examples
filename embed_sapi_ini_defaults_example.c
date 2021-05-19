#include <sapi/embed/php_embed.h>

/* This callback is invoked as soon as the configuration hash table is
 * allocated so any INI settings added via this callback will have the lowest
 * precedence and will allow INI files to overwrite them.
 */
static void example_ini_defaults(HashTable *configuration_hash)
{
	zval ini_value;
	ZVAL_NEW_STR(&ini_value, zend_string_init(ZEND_STRL("Embed SAPI error:"), /* persistent */ 1));
	zend_hash_str_update(configuration_hash, ZEND_STRL("error_prepend_string"), &ini_value);
}

int main(int argc, char **argv)
{
	php_embed_module.ini_defaults = example_ini_defaults;

	PHP_EMBED_START_BLOCK(argc, argv)

	zval retval;

	/* Generates an error by accessing an undefined variable '$a'. */
	if (zend_eval_stringl(ZEND_STRL("var_dump($a);"), &retval, "example") == FAILURE) {
		php_printf("Failed to eval PHP.\n");
	}

	PHP_EMBED_END_BLOCK()
}
