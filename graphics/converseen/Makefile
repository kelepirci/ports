# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	converseen
PORTVERSION=	0.8.3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Converseen/Converseen%200.8/

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Easy to use graphics conversion utility

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libMagick++-6.Q*.so:${PORTSDIR}/graphics/ImageMagick

USES=		cmake gettext iconv tar:bzip2
USE_QT4=	corelib gui linguist_build moc_build qmake_build \
		rcc_build uic_build

post-patch:
	@${REINPLACE_CMD} -e '/^install(FILES converseen.appdata.xml/s|/usr|$${CMAKE_INSTALL_PREFIX}|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/converseen

.include <bsd.port.mk>
