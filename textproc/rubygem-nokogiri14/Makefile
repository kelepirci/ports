# $FreeBSD$

PORTNAME=	nokogiri
PORTVERSION=	1.4.7
PKGNAMESUFFIX=	14
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML, XML, SAX, and Reader parser

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USE_GNOME=	libxml2 libxslt
USES=		pkgconfig
CONFIGURE_ARGS=	--use-system-libraries	

PLIST_FILES=	bin/nokogiri14

PORTSCOUT=	limit:^1\.4

post-patch:
	@${MV} ${WRKSRC}/bin/nokogiri ${WRKSRC}/bin/nokogiri14
	@${RM} ${WRKSRC}/bin/nokogiri.orig

.include <bsd.port.mk>
