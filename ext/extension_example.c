/*
  +----------------------------------------------------------------------+
  | COLOPL Extension Example.                                            |
  +----------------------------------------------------------------------+
  | Copyright (c) COLOPL, Inc.                                           |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | info@colopl.co.jp so we can mail you a copy immediately.             |
  +----------------------------------------------------------------------+
  | Author: Go Kudo <g-kudo@colopl.co.jp>                                |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"

#include "php_extension_example.h"
#include "extension_example_arginfo.h"

#include "sodium.h"

#include <sodium/version.h>

ZEND_FUNCTION(Colopl_ExtensionExample_get_sodium_version)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING(sodium_version_string());
}

PHP_MINIT_FUNCTION(extension_example)
{
	if (register_sodium_class() == NULL) {
		return FAILURE;
	}

	return SUCCESS;
}

PHP_RINIT_FUNCTION(extension_example)
{
#if defined(ZTS) && defined(COMPILE_DL_EXTENSION_EXAMPLE)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}

PHP_MINFO_FUNCTION(extension_example)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "extension_example support", "enabled");
	php_info_print_table_end();
}

zend_module_entry extension_example_module_entry = {
	STANDARD_MODULE_HEADER,
	"extension_example",
	ext_functions,
	PHP_MINIT(extension_example),
	NULL,
	PHP_RINIT(extension_example),
	NULL,
	PHP_MINFO(extension_example),
	PHP_EXTENSION_EXAMPLE_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_EXTENSION_EXAMPLE
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(extension_example)
#endif
