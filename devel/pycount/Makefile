# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	pycount
PORTVERSION=	0.0.6
CATEGORIES=	devel python
MASTER_SITES=	http://python.net/crew/gherman/playground/pycount/ \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.py
EXTRACT_SUFX=	#
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Initial effort to Python code metrics

USES=		dos2unix
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTFILES} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
