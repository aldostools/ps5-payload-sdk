/*
 * generic krb5-types.h for cross compiling, assume system is posix/sus
 */

/* $FreeBSD: releng/11.4/kerberos5/include/krb5-types.h 233294 2012-03-22 08:48:42Z stas $ */

#ifndef __krb5_types_h__
#define __krb5_types_h__

#include <inttypes.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef socklen_t krb5_socklen_t;
#include <unistd.h>
typedef ssize_t krb5_ssize_t;

#if !defined(__has_extension)
#define __has_extension(x) 0
#endif

#define KRB5TYPES_REQUIRE_GNUC(m,n,p) \
    (((__GNUC__ * 10000) + (__GNUC_MINOR__ * 100) + __GNUC_PATCHLEVEL__) >= \
     (((m) * 10000) + ((n) * 100) + (p)))


#ifndef HEIMDAL_DEPRECATED
#if __has_extension(deprecated) || KRB5TYPES_REQUIRE_GNUC(3,1,0)
#define HEIMDAL_DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER) && (_MSC_VER>1200)
#define HEIMDAL_DEPRECATED __declspec(deprecated)
#else
#define HEIMDAL_DEPRECATED
#endif
#endif

#ifndef HEIMDAL_PRINTF_ATTRIBUTE
#if __has_extension(format) || KRB5TYPES_REQUIRE_GNUC(3,1,0)
#define HEIMDAL_PRINTF_ATTRIBUTE(x) __attribute__((format x))
#else
#define HEIMDAL_PRINTF_ATTRIBUTE(x)
#endif
#endif

#ifndef HEIMDAL_NORETURN_ATTRIBUTE
#if __has_extension(noreturn) || KRB5TYPES_REQUIRE_GNUC(3,1,0)
#define HEIMDAL_NORETURN_ATTRIBUTE __attribute__((noreturn))
#else
#define HEIMDAL_NORETURN_ATTRIBUTE
#endif
#endif

#ifndef HEIMDAL_UNUSED_ATTRIBUTE
#if __has_extension(unused) || KRB5TYPES_REQUIRE_GNUC(3,1,0)
#define HEIMDAL_UNUSED_ATTRIBUTE __attribute__((unused))
#else
#define HEIMDAL_UNUSED_ATTRIBUTE
#endif
#endif

typedef int krb5_socket_t;

#endif /* __krb5_types_h__ */
