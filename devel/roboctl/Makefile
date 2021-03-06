# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	roboctl
PORTVERSION=	0.3.8
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	API and tools for communicating with Lego and Vex robots

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libgamepad.a:${PORTSDIR}/devel/libgamepad

MAKE_ENV=	EXTRALIBS=-lbluetooth
MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}
MAKE_JOBS_UNSAFE=	yes

USES=		tar:xz

OPTIONS_DEFINE=	CUTECOM
CUTECOM_DESC=	Install cutecom for Vex debugging

CUTECOM_RUN_DEPENDS=	cutecom:${PORTSDIR}/comms/cutecom

pre-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} depend)

post-install:
	(cd ${WRKSRC}/Commands/NXTRemote; ${MAKE})
	${INSTALL_PROGRAM} ${WRKSRC}/Commands/NXTRemote/nxtremote ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/lego_bluetooth_config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Commands/NXTRemote/nxtremote.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
