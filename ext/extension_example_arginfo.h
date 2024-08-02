/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: cbf7e268ff41ce479965e7d1674cfee0c96213ea */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Colopl_ExtensionExample_get_sodium_version, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Colopl_ExtensionExample_Sodium_generate arginfo_Colopl_ExtensionExample_get_sodium_version

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Colopl_ExtensionExample_Sodium_getCallCount, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(Colopl_ExtensionExample_get_sodium_version);
ZEND_METHOD(Colopl_ExtensionExample_Sodium, generate);
ZEND_METHOD(Colopl_ExtensionExample_Sodium, getCallCount);


static const zend_function_entry ext_functions[] = {
	ZEND_NS_FALIAS("Colopl\\ExtensionExample", get_sodium_version, Colopl_ExtensionExample_get_sodium_version, arginfo_Colopl_ExtensionExample_get_sodium_version)
	ZEND_FE_END
};


static const zend_function_entry class_Colopl_ExtensionExample_Sodium_methods[] = {
	ZEND_ME(Colopl_ExtensionExample_Sodium, generate, arginfo_class_Colopl_ExtensionExample_Sodium_generate, ZEND_ACC_PUBLIC)
	ZEND_ME(Colopl_ExtensionExample_Sodium, getCallCount, arginfo_class_Colopl_ExtensionExample_Sodium_getCallCount, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Colopl_ExtensionExample_Sodium(zend_class_entry *class_entry_Random_Engine)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Colopl\\ExtensionExample", "Sodium", class_Colopl_ExtensionExample_Sodium_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_NOT_SERIALIZABLE;
	zend_class_implements(class_entry, 1, class_entry_Random_Engine);

	return class_entry;
}
