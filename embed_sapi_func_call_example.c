#include <main/php.h>
#include <ext/standard/php_var.h>
#include <sapi/embed/php_embed.h>

int main(int argc, char **argv)
{
	PHP_EMBED_START_BLOCK(argc, argv)

	zval retval = {0};
	zend_fcall_info fci = {0};
	zend_fcall_info_cache fci_cache = {0};

	zend_string *func_name = zend_string_init(ZEND_STRL("mt_rand"), 0);
	ZVAL_STR(&fci.function_name, func_name);

	fci.size = sizeof fci;
	fci.retval = &retval;

	if (zend_call_function(&fci, &fci_cache) == SUCCESS) {
		php_var_dump(&retval, 1);
	}

	zend_string_release(func_name);

	PHP_EMBED_END_BLOCK()
}
