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

#include "php.h"
#include "ext/random/php_random.h"

#include "php_extension_example.h"
#include "extension_example_arginfo.h"

#include "sodium.h"

#include <sodium.h>
#include <sodium/randombytes.h>

static zend_object_handlers sodium_object_handlers;
static zend_class_entry *sodium_ce;

static uint64_t generate(php_random_status *status) {
	uint64_t buf;
	
	randombytes_buf(&buf, sizeof(uint64_t));

	return buf;
}

static zend_long range(php_random_status *status, zend_long min, zend_long max) {
	return php_random_range(&extension_example_algo_sodium, status, min, max);
}

PHPAPI const php_random_algo extension_example_algo_sodium = {
	sizeof(zend_ulong),
	sizeof(zend_long),
	NULL,
	generate,
	range,
	NULL,
	NULL
};

static zend_object *sodium_create_object(zend_class_entry *ce) {
	php_random_engine *engine = php_random_engine_common_init(ce, &sodium_object_handlers, &extension_example_algo_sodium);

	(*(zend_long *)engine->status) = 0;

	return &engine->std;
}

zend_class_entry *register_sodium_class() {
	sodium_ce = register_class_Colopl_ExtensionExample_Sodium(random_ce_Random_Engine);
	sodium_ce->create_object = sodium_create_object;
	memcpy(&sodium_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	sodium_object_handlers.offset = XtOffsetOf(php_random_engine, std);
	sodium_object_handlers.free_obj = php_random_engine_common_free_object;
	sodium_object_handlers.clone_obj = NULL; /* Can't clonable */

	return sodium_ce;
}

ZEND_METHOD(Colopl_ExtensionExample_Sodium, generate)
{
	php_random_engine *engine = Z_RANDOM_ENGINE_P(ZEND_THIS);
	uint64_t generated;
	zend_string *bytes;

	ZEND_PARSE_PARAMETERS_NONE();

	generated = engine->algo->generate(NULL);
	(*(zend_long *) engine->status)++;
	bytes = zend_string_alloc(engine->algo->generate_size, false);
	for (size_t i = 0; i < engine->algo->generate_size; i++) {
		ZSTR_VAL(bytes)[i] = (generated >> (i * 8) & 0xff);
	}
	ZSTR_VAL(bytes)[engine->algo->generate_size] = '\0';

	RETURN_STR(bytes);
}

ZEND_METHOD(Colopl_ExtensionExample_Sodium, getCallCount)
{
	php_random_engine *engine = Z_RANDOM_ENGINE_P(ZEND_THIS);

	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((*(zend_long *) engine->status));
}
