PHP_INCLUDES=$(shell php-config --includes)
PHP_PREFIX=$(shell php-config --prefix)

embed_sapi_basic_example: embed_sapi_basic_example.c
	@mkdir -p bin
	@gcc $(PHP_INCLUDES) -L$(PHP_PREFIX)/lib embed_sapi_basic_example.c -lphp -Wl,-rpath=$(PHP_PREFIX)/lib -o bin/embed_sapi_basic

embed_sapi_exec_script_example: embed_sapi_exec_script_example.c
	@mkdir -p bin
	@gcc $(PHP_INCLUDES) -L$(PHP_PREFIX)/lib embed_sapi_exec_script_example.c -lphp -Wl,-rpath=$(PHP_PREFIX)/lib -o bin/embed_sapi_exec_script

embed_sapi_func_call_example: embed_sapi_func_call_example.c
	@mkdir -p bin
	@gcc $(PHP_INCLUDES) -L$(PHP_PREFIX)/lib embed_sapi_func_call_example.c -lphp -Wl,-rpath=$(PHP_PREFIX)/lib -o bin/embed_sapi_func_call

embed_sapi_ini_defaults_example: embed_sapi_ini_defaults_example.c
	@mkdir -p bin
	@gcc $(PHP_INCLUDES) -L$(PHP_PREFIX)/lib embed_sapi_ini_defaults_example.c -lphp -Wl,-rpath=$(PHP_PREFIX)/lib -o bin/embed_sapi_ini_defaults

examples: embed_sapi_basic_example embed_sapi_exec_script_example  embed_sapi_func_call_example  embed_sapi_ini_defaults_example
all: examples