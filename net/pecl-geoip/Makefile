# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	geoip
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Map IP address to geographic places

LIB_DEPENDS=	libGeoIP.so:${PORTSDIR}/net/GeoIP

USE_PHP=	yes
USE_PHPEXT=	yes

post-patch:
	${REINPLACE_CMD} -e 's/-ldl//g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
