# Created by: squell@alumina.nl
# $FreeBSD$

PORTNAME=	id3mtag
PORTVERSION=	0.78
CATEGORIES=	audio
MASTER_SITES=	http://home.wanadoo.nl/squell/files/
DISTNAME=	id3-${PORTVERSION}

MAINTAINER=	squell@alumina.nl
COMMENT=	Mass tagging utility for audio files

LICENSE=	BSD2CLAUSE

MAKEFILE=	makefile
ALL_TARGET=	build
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/id3 man/man1/id3.1.gz
PORTDOCS=	README CHANGES

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/id3 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/id3.man ${STAGEDIR}${MANPREFIX}/man/man1/id3.1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
