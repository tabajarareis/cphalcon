
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Allows to validate data using custom or built-in validators
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter, Validation, phalcon, filter_validation, phalcon_di_injectable_ce, phalcon_filter_validation_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("combinedFieldsValidators"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("data"), ZEND_ACC_PROTECTED);
	/**
	 * @var object|null
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("entity"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("filters"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("labels"), ZEND_ACC_PROTECTED);
	/**
	 * @var Messages|null
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("messages"), ZEND_ACC_PROTECTED);
	/**
	 * List of validators
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("validators"), ZEND_ACC_PROTECTED);
	/**
	 * Calculated values
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("values"), ZEND_ACC_PROTECTED);
	phalcon_filter_validation_ce->create_object = zephir_init_properties_Phalcon_Filter_Validation;

	zend_class_implements(phalcon_filter_validation_ce, 1, phalcon_filter_validation_validationinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Filter\Validation constructor
 */
PHP_METHOD(Phalcon_Filter_Validation, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validators_param = NULL, _0, _1, _2, _3;
	zval validators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(validators)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &validators_param);
	if (!validators_param) {
		ZEPHIR_INIT_VAR(&validators);
		array_init(&validators);
	} else {
		zephir_get_arrval(&validators, validators_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_8__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&_1, "array_filter", NULL, 17, &validators, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("validators"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_closure_ex(&_2, NULL, phalcon_9__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&_3, "array_filter", NULL, 17, &validators, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedFieldsValidators"), &_3);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("initialize")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a validator to a field
 *
 * @param string|array       $field
 * @param ValidatorInterface $validator
 *
 * @return ValidationInterface
 */
PHP_METHOD(Phalcon_Filter_Validation, add)
{
	zval _0$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub, singleField, *_1$$5, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_0$$4);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_filter_validation_validatorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &validator);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		if (zephir_instance_of_ev(validator, phalcon_filter_validation_abstractcombinedfieldsvalidator_ce)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_create_array(&_0$$4, 2, 0);
			zephir_array_fast_append(&_0$$4, field);
			zephir_array_fast_append(&_0$$4, validator);
			zephir_update_property_array_append(this_ptr, SL("combinedFieldsValidators"), &_0$$4);
		} else {
			zephir_is_iterable(field, 0, "phalcon/Filter/Validation.zep", 120);
			if (Z_TYPE_P(field) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _1$$5)
				{
					ZEPHIR_INIT_NVAR(&singleField);
					ZVAL_COPY(&singleField, _1$$5);
					zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, &singleField);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$5, field, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
					zephir_check_call_status();
						zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, &singleField);
					ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&singleField);
		}
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, field);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "Field must be passed as array of fields or string", "phalcon/Filter/Validation.zep", 126);
		return;
	}
	RETURN_THIS();
}

/**
 * Appends a message to the messages list
 *
 * @param MessageInterface $message
 */
PHP_METHOD(Phalcon_Filter_Validation, appendMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, messages, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_messages_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&messages, &_0);
	if (Z_TYPE_P(&messages) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&messages);
		object_init_ex(&messages, phalcon_messages_messages_ce);
		ZEPHIR_CALL_METHOD(NULL, &messages, "__construct", NULL, 8);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &messages, "appendmessage", NULL, 289, message);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &messages);
	RETURN_THIS();
}

/**
 * Assigns the data to an entity
 * The entity is used to obtain the validation values
 *
 * @param object entity
 * @param array|object data
 */
PHP_METHOD(Phalcon_Filter_Validation, bind)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *entity, entity_sub, *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&data_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(entity)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &entity, &data);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setentity", NULL, 0, entity);
	zephir_check_call_status();
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(data) != IS_OBJECT;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "Data to validate must be an array or object", "phalcon/Filter/Validation.zep", 166);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
	RETURN_THIS();
}

/**
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter_Validation, getData)
{

	RETURN_MEMBER(getThis(), "data");
}

/**
 * Returns the bound entity
 *
 * @return object
 */
PHP_METHOD(Phalcon_Filter_Validation, getEntity)
{

	RETURN_MEMBER(getThis(), "entity");
}

/**
 * Returns all the filters or a specific one
 */
PHP_METHOD(Phalcon_Filter_Validation, getFilters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *field_param = NULL, filters, fieldFilters, _0;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&fieldFilters);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &field_param);
	if (!field_param) {
		ZEPHIR_INIT_VAR(&field);
	} else {
		zephir_get_strval(&field, field_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filters, &_0);
	if (!(!(ZEPHIR_IS_EMPTY(&field)))) {
		RETURN_CCTOR(&filters);
	}
	zephir_memory_observe(&fieldFilters);
	if (!(zephir_array_isset_fetch(&fieldFilters, &filters, &field, 0))) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&fieldFilters);
}

/**
 * Get label for field
 *
 * @param string field
 */
PHP_METHOD(Phalcon_Filter_Validation, getLabel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *field, field_sub, labels, value, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&labels);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &field);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("labels"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&labels, &_0);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_fast_join_str(return_value, SL(", "), field);
		RETURN_MM();
	}
	if (zephir_array_isset_fetch(&value, &labels, field, 1)) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(field, 1, 0);
	RETURN_MM();
}

/**
 * Returns the registered validators
 */
PHP_METHOD(Phalcon_Filter_Validation, getMessages)
{

	RETURN_MEMBER(getThis(), "messages");
}

/**
 * Returns the validators added to the validation
 */
PHP_METHOD(Phalcon_Filter_Validation, getValidators)
{

	RETURN_MEMBER(getThis(), "validators");
}

/**
 * Gets the a value to validate in the object entity source
 *
 * @param mixed $entity
 * @param string $field
 */
PHP_METHOD(Phalcon_Filter_Validation, getValueByEntity)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field, method;
	zval *entity, entity_sub, *field_param = NULL, _0, _1, _2$$5;

	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&method);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(entity)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &entity, &field_param);
	zephir_get_strval(&field, field_param);
	ZEPHIR_INIT_VAR(&_0);
	zephir_camelize(&_0, &field, NULL );
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "get", &_0);
	zephir_get_strval(&method, &_1);
	if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(entity, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(entity, ZEND_STRL("readattribute")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD(entity, "readattribute", NULL, 0, &field);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_isset_property_zval(entity, &field)) {
		zephir_memory_observe(&_2$$5);
		zephir_read_property_zval(&_2$$5, entity, &field, PH_NOISY_CC);
		RETURN_CCTOR(&_2$$5);
	}
	RETURN_MM_NULL();
}

/**
 * Gets the a value to validate in the array/object data source
 *
 * @param mixed $data
 * @param string $field
 */
PHP_METHOD(Phalcon_Filter_Validation, getValueByData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval field;
	zval *data, data_sub, *field_param = NULL, value, values, _0, _1$$5, _2$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&field);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(data)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &data, &field_param);
	zephir_get_strval(&field, field_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&values, &_0);
	zephir_memory_observe(&value);
	if (zephir_array_isset_fetch(&value, &values, &field, 0)) {
		RETURN_CCTOR(&value);
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		if (zephir_array_isset(data, &field)) {
			zephir_array_fetch(&_1$$5, data, &field, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation.zep", 296);
			RETURN_CTOR(&_1$$5);
		}
	}
	if (Z_TYPE_P(data) == IS_OBJECT) {
		if (zephir_isset_property_zval(data, &field)) {
			zephir_memory_observe(&_2$$7);
			zephir_read_property_zval(&_2$$7, data, &field, PH_NOISY_CC);
			RETURN_CCTOR(&_2$$7);
		}
	}
	RETURN_MM_NULL();
}

/**
 * Gets the a value to validate in the array/object data source
 *
 * @param string $field
 */
PHP_METHOD(Phalcon_Filter_Validation, getValue)
{
	zend_bool isRawFetched = 0, _1$$5, _4$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, entity, method, value, data, filters, fieldFilters, container, filterService, _0, _2$$9, _3$$9, _5$$13, _6$$13;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&entity);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&fieldFilters);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_5$$13);
	ZVAL_UNDEF(&_6$$13);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &field_param);
	zephir_get_strval(&field, field_param);
	isRawFetched = 0;
	zephir_read_property(&_0, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&entity, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_0);
	if (Z_TYPE_P(&entity) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&value, this_ptr, "getvaluebyentity", NULL, 0, &entity, &field);
		zephir_check_call_status();
		if (Z_TYPE_P(&value) == IS_NULL) {
			isRawFetched = 1;
			ZEPHIR_CALL_METHOD(&value, this_ptr, "getvaluebydata", NULL, 0, &data, &field);
			zephir_check_call_status();
		}
	} else {
		_1$$5 = Z_TYPE_P(&data) != IS_ARRAY;
		if (_1$$5) {
			_1$$5 = Z_TYPE_P(&data) != IS_OBJECT;
		}
		if (UNEXPECTED(_1$$5)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "There is no data to validate", "phalcon/Filter/Validation.zep", 333);
			return;
		}
		ZEPHIR_CALL_METHOD(&value, this_ptr, "getvaluebydata", NULL, 0, &data, &field);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filters, &_0);
	zephir_memory_observe(&fieldFilters);
	if (zephir_array_isset_fetch(&fieldFilters, &filters, &field, 0)) {
		if (zephir_is_true(&fieldFilters)) {
			ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&container) == IS_NULL) {
				ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&container) == IS_NULL) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "A dependency injection container is required to access the 'filter' service", "phalcon/Filter/Validation.zep", 354);
					return;
				}
			}
			ZEPHIR_INIT_VAR(&_3$$9);
			ZVAL_STRING(&_3$$9, "filter");
			ZEPHIR_CALL_METHOD(&_2$$9, &container, "getshared", NULL, 0, &_3$$9);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filterService, &_2$$9);
			if (UNEXPECTED(Z_TYPE_P(&filterService) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "Returned 'filter' service is invalid", "phalcon/Filter/Validation.zep", 361);
				return;
			}
			ZEPHIR_CALL_METHOD(&_2$$9, &filterService, "sanitize", NULL, 0, &value, &fieldFilters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_2$$9);
			_4$$9 = Z_TYPE_P(&entity) == IS_OBJECT;
			if (_4$$9) {
				_4$$9 = isRawFetched == 0;
			}
			if (_4$$9) {
				ZEPHIR_INIT_VAR(&_5$$13);
				zephir_camelize(&_5$$13, &field, NULL );
				ZEPHIR_INIT_VAR(&method);
				ZEPHIR_CONCAT_SV(&method, "set", &_5$$13);
				ZEPHIR_CALL_FUNCTION(&_6$$13, "property_exists", NULL, 290, &entity, &field);
				zephir_check_call_status();
				if ((zephir_method_exists(&entity, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, &entity, &method, NULL, 0, &value);
					zephir_check_call_status();
				} else if ((zephir_method_exists_ex(&entity, ZEND_STRL("writeattribute")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(NULL, &entity, "writeattribute", NULL, 0, &field, &value);
					zephir_check_call_status();
				} else if (zephir_is_true(&_6$$13)) {
					zephir_update_property_zval_zval(&entity, &field, &value);
				}
			}
			RETURN_CCTOR(&value);
		}
	}
	if (Z_TYPE_P(&entity) != IS_OBJECT) {
		zephir_update_property_array(this_ptr, SL("values"), &field, &value);
	}
	RETURN_CCTOR(&value);
}

/**
 * Alias of `add` method
 *
 * @param string|array       $field
 * @param ValidatorInterface $validator
 *
 * @return ValidationInterface
 */
PHP_METHOD(Phalcon_Filter_Validation, rule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_filter_validation_validatorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &validator);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, field, validator);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds the validators to a field
 */
PHP_METHOD(Phalcon_Filter_Validation, rules)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval validators;
	zval *field, field_sub, *validators_param = NULL, validator, *_0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&validators);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_ARRAY(validators)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &validators_param);
	ZEPHIR_OBS_COPY_OR_DUP(&validators, validators_param);
	zephir_is_iterable(&validators, 0, "phalcon/Filter/Validation.zep", 419);
	if (Z_TYPE_P(&validators) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _0)
		{
			ZEPHIR_INIT_NVAR(&validator);
			ZVAL_COPY(&validator, _0);
			if (zephir_instance_of_ev(&validator, phalcon_filter_validation_validatorinterface_ce)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_2, 0, field, &validator);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &validators, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_instance_of_ev(&validator, phalcon_filter_validation_validatorinterface_ce)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_2, 0, field, &validator);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&validator);
	RETURN_THIS();
}

/**
 * Sets the bound entity
 *
 * @param object entity
 */
PHP_METHOD(Phalcon_Filter_Validation, setEntity)
{
	zval *entity, entity_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(entity)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &entity);
	if (UNEXPECTED(Z_TYPE_P(entity) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_filter_validation_exception_ce, "Entity must be an object", "phalcon/Filter/Validation.zep", 430);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("entity"), entity);
}

/**
 * Adds filters to the field
 *
 * @param string field
 * @param array|string filters
 */
PHP_METHOD(Phalcon_Filter_Validation, setFilters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *filters, filters_sub, singleField, *_0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &filters);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, 0, "phalcon/Filter/Validation.zep", 450);
		if (Z_TYPE_P(field) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _0$$3);
				zephir_update_property_array(this_ptr, SL("filters"), &singleField, filters);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, field, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
				zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("filters"), &singleField, filters);
				ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array(this_ptr, SL("filters"), field, filters);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "Field must be passed as array of fields or string.", "phalcon/Filter/Validation.zep", 455);
		return;
	}
	RETURN_THIS();
}

/**
 * Adds labels for fields
 */
PHP_METHOD(Phalcon_Filter_Validation, setLabels)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *labels_param = NULL;
	zval labels;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&labels);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(labels)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &labels_param);
	ZEPHIR_OBS_COPY_OR_DUP(&labels, labels_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("labels"), &labels);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Filter_Validation, setValidators)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *validators_param = NULL;
	zval validators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(validators)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &validators_param);
	zephir_get_arrval(&validators, validators_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("validators"), &validators);
	RETURN_THIS();
}

/**
 * Validate a set of data according to a set of rules
 *
 * @param array|object data
 * @param object entity
 *
 * @return Messages|false
 */
PHP_METHOD(Phalcon_Filter_Validation, validate)
{
	zend_bool _4$$7;
	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, __$null, combinedFieldsValidators, field, scope, status, validator, validatorData, validators, _0, _1, _2, *_5, _6, *_30, _31, _3$$5, *_9$$9, _10$$9, _11$$10, _13$$10, _14$$13, _15$$13, _16$$15, _17$$15, _18$$18, _19$$18, *_20$$20, _21$$20, _22$$21, _23$$21, _24$$24, _25$$24, _26$$26, _27$$26, _28$$29, _29$$29, _32$$31, _33$$31, _34$$35, _35$$35, _36$$37, _37$$37, _38$$41, _39$$41, _40$$43;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&combinedFieldsValidators);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&scope);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&validatorData);
	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_21$$20);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$24);
	ZVAL_UNDEF(&_25$$24);
	ZVAL_UNDEF(&_26$$26);
	ZVAL_UNDEF(&_27$$26);
	ZVAL_UNDEF(&_28$$29);
	ZVAL_UNDEF(&_29$$29);
	ZVAL_UNDEF(&_32$$31);
	ZVAL_UNDEF(&_33$$31);
	ZVAL_UNDEF(&_34$$35);
	ZVAL_UNDEF(&_35$$35);
	ZVAL_UNDEF(&_36$$37);
	ZVAL_UNDEF(&_37$$37);
	ZVAL_UNDEF(&_38$$41);
	ZVAL_UNDEF(&_39$$41);
	ZVAL_UNDEF(&_40$$43);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_ZVAL_OR_NULL(entity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &data, &entity);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!entity) {
		entity = &entity_sub;
		entity = &__$null;
	}
	zephir_memory_observe(&validatorData);
	zephir_read_property(&validatorData, this_ptr, ZEND_STRL("validators"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("combinedFieldsValidators"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&combinedFieldsValidators, &_0);
	if (UNEXPECTED(Z_TYPE_P(&validatorData) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "There are no validators to validate", "phalcon/Filter/Validation.zep", 493);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("values"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 8);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &_2);
	if (Z_TYPE_P(entity) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setentity", NULL, 0, entity);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("beforevalidation")) == SUCCESS)) {
		zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&status, this_ptr, "beforevalidation", NULL, 0, data, entity, &_3$$5);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
			RETURN_CCTOR(&status);
		}
	}
	if (Z_TYPE_P(data) != IS_NULL) {
		_4$$7 = Z_TYPE_P(data) != IS_ARRAY;
		if (_4$$7) {
			_4$$7 = Z_TYPE_P(data) != IS_OBJECT;
		}
		if (UNEXPECTED(_4$$7)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "Invalid data to validate", "phalcon/Filter/Validation.zep", 523);
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
	}
	zephir_is_iterable(&validatorData, 0, "phalcon/Filter/Validation.zep", 554);
	if (Z_TYPE_P(&validatorData) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&validatorData), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&field, _8);
			} else {
				ZVAL_LONG(&field, _7);
			}
			ZEPHIR_INIT_NVAR(&validators);
			ZVAL_COPY(&validators, _5);
			zephir_is_iterable(&validators, 0, "phalcon/Filter/Validation.zep", 552);
			if (Z_TYPE_P(&validators) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _9$$9)
				{
					ZEPHIR_INIT_NVAR(&validator);
					ZVAL_COPY(&validator, _9$$9);
					if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "One of the validators is not valid", "phalcon/Filter/Validation.zep", 532);
						return;
					}
					ZEPHIR_CALL_METHOD(&_11$$10, this_ptr, "prechecking", &_12, 0, &field, &validator);
					zephir_check_call_status();
					if (zephir_is_true(&_11$$10)) {
						continue;
					}
					ZEPHIR_CALL_METHOD(&_13$$10, &validator, "validate", NULL, 0, this_ptr, &field);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_13$$10)) {
						ZEPHIR_INIT_NVAR(&_15$$13);
						ZVAL_STRING(&_15$$13, "cancelOnFail");
						ZEPHIR_CALL_METHOD(&_14$$13, &validator, "getoption", NULL, 0, &_15$$13);
						zephir_check_call_status();
						if (zephir_is_true(&_14$$13)) {
							break;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_10$$9, &validators, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
					zephir_check_call_status();
						if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "One of the validators is not valid", "phalcon/Filter/Validation.zep", 532);
							return;
						}
						ZEPHIR_CALL_METHOD(&_16$$15, this_ptr, "prechecking", &_12, 0, &field, &validator);
						zephir_check_call_status();
						if (zephir_is_true(&_16$$15)) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_17$$15, &validator, "validate", NULL, 0, this_ptr, &field);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_17$$15)) {
							ZEPHIR_INIT_NVAR(&_19$$18);
							ZVAL_STRING(&_19$$18, "cancelOnFail");
							ZEPHIR_CALL_METHOD(&_18$$18, &validator, "getoption", NULL, 0, &_19$$18);
							zephir_check_call_status();
							if (zephir_is_true(&_18$$18)) {
								break;
							}
						}
					ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&validator);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &validatorData, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &validatorData, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &validatorData, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&validators, &validatorData, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&validators, 0, "phalcon/Filter/Validation.zep", 552);
				if (Z_TYPE_P(&validators) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _20$$20)
					{
						ZEPHIR_INIT_NVAR(&validator);
						ZVAL_COPY(&validator, _20$$20);
						if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "One of the validators is not valid", "phalcon/Filter/Validation.zep", 532);
							return;
						}
						ZEPHIR_CALL_METHOD(&_22$$21, this_ptr, "prechecking", &_12, 0, &field, &validator);
						zephir_check_call_status();
						if (zephir_is_true(&_22$$21)) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_23$$21, &validator, "validate", NULL, 0, this_ptr, &field);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_23$$21)) {
							ZEPHIR_INIT_NVAR(&_25$$24);
							ZVAL_STRING(&_25$$24, "cancelOnFail");
							ZEPHIR_CALL_METHOD(&_24$$24, &validator, "getoption", NULL, 0, &_25$$24);
							zephir_check_call_status();
							if (zephir_is_true(&_24$$24)) {
								break;
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_21$$20, &validators, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_21$$20)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
						zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "One of the validators is not valid", "phalcon/Filter/Validation.zep", 532);
								return;
							}
							ZEPHIR_CALL_METHOD(&_26$$26, this_ptr, "prechecking", &_12, 0, &field, &validator);
							zephir_check_call_status();
							if (zephir_is_true(&_26$$26)) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_27$$26, &validator, "validate", NULL, 0, this_ptr, &field);
							zephir_check_call_status();
							if (ZEPHIR_IS_FALSE_IDENTICAL(&_27$$26)) {
								ZEPHIR_INIT_NVAR(&_29$$29);
								ZVAL_STRING(&_29$$29, "cancelOnFail");
								ZEPHIR_CALL_METHOD(&_28$$29, &validator, "getoption", NULL, 0, &_29$$29);
								zephir_check_call_status();
								if (zephir_is_true(&_28$$29)) {
									break;
								}
							}
						ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&validator);
			ZEPHIR_CALL_METHOD(NULL, &validatorData, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&validators);
	ZEPHIR_INIT_NVAR(&field);
	zephir_is_iterable(&combinedFieldsValidators, 0, "phalcon/Filter/Validation.zep", 587);
	if (Z_TYPE_P(&combinedFieldsValidators) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&combinedFieldsValidators), _30)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _30);
			if (UNEXPECTED(Z_TYPE_P(&scope) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "The validator scope is not valid", "phalcon/Filter/Validation.zep", 556);
				return;
			}
			ZEPHIR_OBS_NVAR(&field);
			zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/Filter/Validation.zep", 559);
			ZEPHIR_OBS_NVAR(&validator);
			zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/Filter/Validation.zep", 560);
			if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "One of the validators is not valid", "phalcon/Filter/Validation.zep", 563);
				return;
			}
			ZEPHIR_CALL_METHOD(&_32$$31, this_ptr, "prechecking", &_12, 0, &field, &validator);
			zephir_check_call_status();
			if (zephir_is_true(&_32$$31)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_33$$31, &validator, "validate", NULL, 0, this_ptr, &field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_33$$31)) {
				ZEPHIR_INIT_NVAR(&_35$$35);
				ZVAL_STRING(&_35$$35, "cancelOnFail");
				ZEPHIR_CALL_METHOD(&_34$$35, &validator, "getoption", NULL, 0, &_35$$35);
				zephir_check_call_status();
				if (zephir_is_true(&_34$$35)) {
					break;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &combinedFieldsValidators, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_31, &combinedFieldsValidators, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_31)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scope, &combinedFieldsValidators, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&scope) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "The validator scope is not valid", "phalcon/Filter/Validation.zep", 556);
					return;
				}
				ZEPHIR_OBS_NVAR(&field);
				zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/Filter/Validation.zep", 559);
				ZEPHIR_OBS_NVAR(&validator);
				zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/Filter/Validation.zep", 560);
				if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_validation_exception_ce, "One of the validators is not valid", "phalcon/Filter/Validation.zep", 563);
					return;
				}
				ZEPHIR_CALL_METHOD(&_36$$37, this_ptr, "prechecking", &_12, 0, &field, &validator);
				zephir_check_call_status();
				if (zephir_is_true(&_36$$37)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_37$$37, &validator, "validate", NULL, 0, this_ptr, &field);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_37$$37)) {
					ZEPHIR_INIT_NVAR(&_39$$41);
					ZVAL_STRING(&_39$$41, "cancelOnFail");
					ZEPHIR_CALL_METHOD(&_38$$41, &validator, "getoption", NULL, 0, &_39$$41);
					zephir_check_call_status();
					if (zephir_is_true(&_38$$41)) {
						break;
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &combinedFieldsValidators, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&scope);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("aftervalidation")) == SUCCESS)) {
		zephir_read_property(&_40$$43, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, data, entity, &_40$$43);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "messages");
}

/**
 * Internal validations, if it returns true, then skip the current validator
 *
 * @param array|string $field
 * @param ValidatorInterface $validator
 */
PHP_METHOD(Phalcon_Filter_Validation, preChecking)
{
	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub, __$false, singleField, allowEmpty, emptyValue, value, *_0$$3, _1$$3, _2$$4, _4$$6, _5$$8, _6$$8, *_7$$11, _8$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&allowEmpty);
	ZVAL_UNDEF(&emptyValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&results);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_filter_validation_validatorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &validator);
	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, 0, "phalcon/Filter/Validation.zep", 615);
		if (Z_TYPE_P(field) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _0$$3);
				ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "prechecking", &_3, 291, &singleField, validator);
				zephir_check_call_status();
				zephir_array_append(&results, &_2$$4, PH_SEPARATE, "phalcon/Filter/Validation.zep", 607);
				if (zephir_fast_in_array(&__$false, &results)) {
					RETURN_MM_BOOL(0);
				}
				RETURN_MM_BOOL(1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, field, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "prechecking", &_3, 291, &singleField, validator);
					zephir_check_call_status();
					zephir_array_append(&results, &_4$$6, PH_SEPARATE, "phalcon/Filter/Validation.zep", 607);
					if (zephir_fast_in_array(&__$false, &results)) {
						RETURN_MM_BOOL(0);
					}
					RETURN_MM_BOOL(1);
				ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else {
		ZEPHIR_INIT_VAR(&_5$$8);
		ZVAL_STRING(&_5$$8, "allowEmpty");
		ZVAL_BOOL(&_6$$8, 0);
		ZEPHIR_CALL_METHOD(&allowEmpty, validator, "getoption", NULL, 0, &_5$$8, &_6$$8);
		zephir_check_call_status();
		if (zephir_is_true(&allowEmpty)) {
			if ((zephir_method_exists_ex(validator, ZEND_STRL("isallowempty")) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_METHOD(validator, "isallowempty", NULL, 0, this_ptr, field);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, field);
			zephir_check_call_status();
			if (Z_TYPE_P(&allowEmpty) == IS_ARRAY) {
				zephir_is_iterable(&allowEmpty, 0, "phalcon/Filter/Validation.zep", 632);
				if (Z_TYPE_P(&allowEmpty) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&allowEmpty), _7$$11)
					{
						ZEPHIR_INIT_NVAR(&emptyValue);
						ZVAL_COPY(&emptyValue, _7$$11);
						if (ZEPHIR_IS_IDENTICAL(&emptyValue, &value)) {
							RETURN_MM_BOOL(1);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &allowEmpty, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_8$$11, &allowEmpty, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_8$$11)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&emptyValue, &allowEmpty, "current", NULL, 0);
						zephir_check_call_status();
							if (ZEPHIR_IS_IDENTICAL(&emptyValue, &value)) {
								RETURN_MM_BOOL(1);
							}
						ZEPHIR_CALL_METHOD(NULL, &allowEmpty, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&emptyValue);
				RETURN_MM_BOOL(0);
			}
			RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(&value));
		}
	}
	RETURN_MM_BOOL(0);
}

zend_object *zephir_init_properties_Phalcon_Filter_Validation(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("values"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("validators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("validators"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("labels"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("labels"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("filters"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("combinedFieldsValidators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("combinedFieldsValidators"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

