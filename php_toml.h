/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: yukeyong87@gmail.com                                         |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_TOML_H
#define PHP_TOML_H

extern zend_module_entry toml_module_entry;
#define phpext_toml_ptr &toml_module_entry

#define PHP_TOML_VERSION "0.1.2" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_TOML_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_TOML_API __attribute__ ((visibility("default")))
#else
#	define PHP_TOML_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:
*/

ZEND_BEGIN_MODULE_GLOBALS(toml)
	zend_bool  cache_enable;
ZEND_END_MODULE_GLOBALS(toml)


#define TOML_DEBUG 0

static zval toml_parse_item_value(char *item_value, size_t max_len, int line);
static zval toml_parse_item_array(char *item_value, size_t max_len, int line);
static zval* get_array_last_item(zval *stack);
static void toml_parse_str(char *raw_str, size_t len, zval *result, zval **group, zend_bool *top_is_array_table, int line);
static zend_uchar toml_is_numeric(char *str, zend_long *lval, double  *dval);
static void parse_toml(zend_string *toml_contents, zval *return_value);

static void toml_zval_copy(zval *zv, zval *rv, zend_bool persistent);
static void toml_hash_init(zval *zv, uint32_t size, zend_bool persistent);
static void toml_hash_copy(HashTable *target, HashTable *source, zend_bool persistent);
static void toml_file_copy_containers(zval *val, zend_string *key, long file_mtime);

static void toml_copy_val(zval *pElement);

/* Always refer to the globals in your function as TOML_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define TOML_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(toml, v)

#if defined(ZTS) && defined(COMPILE_DL_TOML)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif	/* PHP_TOML_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
