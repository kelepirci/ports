# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	driconf
PORTVERSION=	0.9.1
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/d/${PORTNAME}
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig.tar.gz

MAINTAINER=	lichray@gmail.com
COMMENT=	Configuration program for DRI drivers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

USE_GL=		glut
USE_PYTHON=	yes
NO_BUILD=	yes
USES=		gettext
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFODIR=	${STAGEDIR}${PREFIX}/lib/driconf

pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/driconf* ${WRKSRC}/setup.*

.include <bsd.port.mk>
