# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	libtre
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://laurikari.net/tre/ \
		LOCAL/bf
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tre-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Python interface for the tre regular expressions library

LIB_DEPENDS=	libtre.so:${PORTSDIR}/textproc/libtre

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE
USES=	tar:bzip2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python

CFLAGS+=	-I${LOCALBASE}/include/ -L${LOCALBASE}/lib/

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-Wuninitialized -ffast-math -finline-functions \
		-fomit-frame-pointer -fexpensive-optimizations \
		-fforce-mem -fforce-addr -O3
.endif

.include <bsd.port.mk>
