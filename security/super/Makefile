# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	super
PORTVERSION=	3.30.0
PORTREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	ftp://ftp.ucolick.org/pub/users/will/ \
		http://www.ucolick.org/~will/RUE/super/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allow others to run commands as root

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|\.\/mkdir_p -p755|mkdir -p -m 755|g' \
		-e '/sysconfdir/ s|super\.tab|&.sample|' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/super ${STAGEDIR}${PREFIX}/bin/setuid
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/sample.tab ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/sample.cdmount ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
