# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	soci
PORTVERSION=	3.2.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	The C++ Database Access Library

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		cmake zip
CMAKE_ARGS+=	-DWITH_ORACLE:BOOL=OFF
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE ODBC BOOST FIREBIRD
BOOST_DESC=	Enable support for additional types using Boost
OPTIONS_DEFAULT=MYSQL PGSQL SQLITE ODBC BOOST FIREBIRD
OPTIONS_SUB=	yes

MYSQL_USE=	MYSQL=yes
MYSQL_CMAKE_ON=	-DWITH_MYSQL:BOOL=ON
MYSQL_CMAKE_OFF=	-DWITH_MYSQL:BOOL=OFF

PGSQL_USES=	pgsql
PGSQL_CMAKE_ON=	-DWITH_POSTGRESQL:BOOL=ON
PGSQL_CMAKE_OFF=	-DWITH_POSTGRESQL:BOOL=OFF

SQLITE_USE=	SQLITE=yes
SQLITE_CMAKE_ON=	-DWITH_SQLITE3:BOOL=ON
SQLITE_CMAKE_OFF=	-DWITH_SQLITE3:BOOL=OFF

ODBC_LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC
ODBC_CMAKE_ON=	-DODBC_LIBRARY:FILE_PATH=${LOCALBASE}/lib/libodbc.so \
		-DWITH_ODBC:BOOL=ON
ODBC_CMAKE_OFF=	-DWITH_ODBC:BOOL=OFF

BOOST_LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs
BOOST_CMAKE_ON=	-DWITH_BOOST:BOOL=ON
BOOST_CMAKE_OFF=	-DWITH_BOOST:BOOL=OFF

FIREBIRD_USE=	FIREBIRD=yes
FIREBIRD_CMAKE_ARGS_ON=	-DWITH_FIREBIRD:BOOL=ON
FIREBIRD_CMAKE_ARGS_OFF=	-DWITH_FIREBIRD:BOOL=OFF

.include <bsd.port.mk>
