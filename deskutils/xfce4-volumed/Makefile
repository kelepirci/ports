# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD$

PORTNAME=	xfce4-volumed
PORTVERSION=	0.1.13
PORTREVISION=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Volume management daemon for the Xfce desktop

LICENSE=	GPLv3

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify \
		libkeybinder.so:${PORTSDIR}/x11/keybinder

USES=		pkgconfig gmake tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_GSTREAMER=	yes
USE_XFCE=	configenv xfconf

.include <bsd.port.mk>
