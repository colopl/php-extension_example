dnl config.m4 for extension_example extension

PHP_ARG_WITH([extension_example], [for extension_example support], [AS_HELP_STRING([--with-extension_example]), [Include extension_example support]])

if test "${PHP_EXTENSION_EXAMPLE}" != "no"; then
  dnl check for required libraries and headers
  AC_CHECK_LIB([sodium], [sodium_version_string], [], [
    AC_MSG_ERROR([Required library sodium not found. Please install libsodium library])
  ])

  AC_CHECK_HEADER([sodium.h], [], [
    AC_MSG_ERROR([Required header sodium.h not found. Please install libsodium library])
  ])

  PHP_ADD_INCLUDE("/usr/local/include")
  PHP_ADD_LIBRARY_WITH_PATH(sodium, "/usr/local/lib", EXTENSION_EXAMPLE_SHARED_LIBADD)

  PHP_SUBST(EXTENSION_EXAMPLE_SHARED_LIBADD)
  PHP_SUBST(EXTENSION_EXAMPLE_LIBS)

  PHP_NEW_EXTENSION(extension_example, extension_example.c sodium.c, $ext_shared)
fi
