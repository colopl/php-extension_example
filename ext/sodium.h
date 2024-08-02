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

#ifndef SODIUM_H
# define SODIUM_H

# include "php.h"
# include "ext/random/php_random.h"

# include <sodium.h>

extern PHPAPI const php_random_algo extension_example_algo_sodium;

zend_class_entry *register_sodium_class();

#endif	/* SODIUM_H */
