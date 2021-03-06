# Created by: netchild@FreeBSD.org
# $FreeBSD$

PORTNAME=	skype
PORTVERSION=	4.3.0.37
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	http://download.skype.com/linux/
PKGNAMESUFFIX=	4

MAINTAINER=	xmj@chaot.net
COMMENT=	P2P VoIP software

CONFLICTS=	skype-devel-[0-9]*

OPTIONS_DEFINE=	VIDEO
OPTIONS_DEFAULT=	VIDEO

NO_BUILD=	yes

USES=		desktop-file-utils tar:bzip2
USE_LINUX=	yes
USE_LINUX_APPS+= fontconfig xorglibs qt47 qt47-x11 qt47-webkit libsndfile openssl-compat pulseaudio-libs tcp_wrappers-libs flac libasyncns

RESTRICTED=	Redistribution prohibited.

SKYPEDIR=	share/skype
PORTDOCS=	LICENSE README
PLIST_SUB+=	SKYPEDIR=${SKYPEDIR}
SUB_FILES=	skype.sh
SUB_LIST+=	SKYPEDIR=${SKYPEDIR}

#NVIDIA_GL_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
#NVIDIA_GL_USE=		LINUX_APPS=xorglibs
#NVIDIA_GL_USE_OFF=	LINUX_APPS=dri

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MVIDEO}
RUN_DEPENDS+=	webcamd>0:${PORTSDIR}/multimedia/webcamd
USE_LINUX_APPS+=	libv4l
SUB_LIST+=	VIDEO="LD_PRELOAD=/usr/lib/libv4l/v4l2convert.so "
.else
SUB_LIST+=	VIDEO=""
.endif

do-install:
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/skype.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_48x48.png ${STAGEDIR}${PREFIX}/share/pixmaps/skype.png
	@cd ${WRKSRC}/ && ${MKDIR} ${STAGEDIR}${PREFIX}/${SKYPEDIR} && ${COPYTREE_SHARE} "avatars icons sounds lang" ${STAGEDIR}${PREFIX}/${SKYPEDIR}/

# The binary main program
	@${INSTALL_PROGRAM} ${WRKSRC}/skype ${STAGEDIR}${PREFIX}/${SKYPEDIR}/

# The wrapper for main program
	@${INSTALL_SCRIPT} ${WRKDIR}/skype.sh ${STAGEDIR}${PREFIX}/bin/skype

# Documentation
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
