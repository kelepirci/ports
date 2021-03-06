# Created by: kuriyama
# $FreeBSD$

PORTNAME=	openjade
PORTVERSION=	1.3.3p1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.3.3
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/-pre/}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Object-oriented SGML/XML parser toolkit and DSSSL engine

LIB_DEPENDS=	libosp.so:${PORTSDIR}/textproc/opensp
RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USES=		gettext gmake libtool perl5
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog \
		--datadir=${DATADIR}
INSTALL_TARGET=	install install-man
MAKE_ENV=	STRIP="${STRIP}"
PLIST_SUB=	XMLCATMGR=${XMLCATMGR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr

DATADIR=	${PREFIX}/share/sgml/openjade

post-patch:
	@${REINPLACE_CMD} -e 's|<iostream.h>|<iostream>|' ${WRKSRC}/style/MultiLineInlineNote.cxx

post-install:
	@${CAT} ${PLIST} | \
		${SED} ${PLIST_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} | \
		${AWK} '/^@comment INSTALL_DATA:/ \
			{printf "if ! ${GREP} -q \"%s\" ${PLIST}; then ${ECHO_CMD} \"%s\" >> %s; fi;  %s %s/%s %s/%s\n", \
			$$4, $$4, "${TMPPLIST}", "${INSTALL_DATA}", \
			"${WRKSRC}", $$3, "${STAGEDIR}${PREFIX}", $$4}' | \
		${SH}

.include <bsd.port.mk>
