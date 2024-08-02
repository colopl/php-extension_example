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

#ifndef PHP_EXTENSION_EXAMPLE_H
# define PHP_EXTENSION_EXAMPLE_H

extern zend_module_entry extension_example_module_entry;
# define phpext_extension_example_ptr &extension_example_module_entry

# define PHP_EXTENSION_EXAMPLE_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_EXTENSION_EXAMPLE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_EXTENSION_EXAMPLE_H */
