# Created by: KIMURA Yasuhiro <yasu@utahime.org>
# $FreeBSD$

PORTNAME=	git-modes
PORTVERSION=	20140314
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yasu@utahime.org
COMMENT=	GNU Emacs modes for Git-related files

LICENSE=	GPLv3

RUN_DEPENDS=	git>0:${PORTSDIR}/devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	magit
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	42e989c

USES=		gmake
USE_EMACS=	yes
PORTDOCS=	CONTRIBUTING.md README.md

ALL_TARGET=	lisp

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
PLIST_SUB=	ELISPDIR=${ELISPDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_MAN} ${WRKSRC}/CONTRIBUTING.md ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
