# $FreeBSD$

PORTNAME=	ktp-text-ui
PORTVERSION=	${KTP_VERSION}
PORTREVISION=	3
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE chat window application

LIB_DEPENDS=	libtelepathy-qt4.so:${PORTSDIR}/net-im/telepathy-qt4 \
		libtelepathy-logger-qt4.so:${PORTSDIR}/net-im/telepathy-logger-qt4 \
		libktpcommoninternalsprivate.so:${PORTSDIR}/net-im/ktp-common-internals
RUN_DEPENDS=	${KDE4_PREFIX}/bin/ktp-contactlist:${PORTSDIR}/net-im/ktp-contact-list

USE_KDE4=	kdehier kdeprefix kdelibs automoc4
#USE_KDE4+=	kdepimlibs
USE_QT4=	corelib webkit xml \
		moc_build qmake_build rcc_build uic_build
USES=		cmake gettext tar:bzip2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
