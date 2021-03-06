# Created by: ports
# $FreeBSD$

PORTNAME=	tnftpd
PORTVERSION=	20130325
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/tnftp/

MAINTAINER=	cejkar@fit.vutbr.cz
COMMENT=	Enhanced ftp server from NetBSD

USES=		libtool
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal automake
AUTOMAKE_ARGS=	--add-missing
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal

PLIST_FILES=	libexec/tnftpd \
				man/man5/ftpd.conf.5.gz man/man5/ftpusers.5.gz man/man8/tnftpd.8.gz
PORTDOCS=	ChangeLog NEWS README THANKS COPYING
PORTEXAMPLES=	ftpd.conf ftpusers

OPTIONS_DEFINE=	DOCS EXAMPLES
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900007
CFLAGS+=	-DSUPPORT_UTMPX
.else
CFLAGS+=	-DSUPPORT_UTMP
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/tnftpd ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/src/ftpd.conf.man ${STAGEDIR}${PREFIX}/man/man5/ftpd.conf.5
	${INSTALL_MAN} ${WRKSRC}/src/ftpusers.man ${STAGEDIR}${PREFIX}/man/man5/ftpusers.5
	${INSTALL_MAN} ${WRKSRC}/src/tnftpd.man ${STAGEDIR}${PREFIX}/man/man8/tnftpd.8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.post.mk>
