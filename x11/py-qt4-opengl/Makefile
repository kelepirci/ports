# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	opengl
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11 devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, QtOpenGL module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${PKGNAMEPREFIX}gui>=${PYQT4_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui

CONFIGURE_ARGS=	--enable QtOpenGL
PYQT4_DIST=	yes
USE_QT4=	moc_build opengl qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtOpenGL API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${QSCIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2.so:${PORTSDIR}/devel/qscintilla2
DEBUG_CONFIGURE_ON=	--debug --trace

.include "${.CURDIR}/../../devel/py-qt4/bsd.pyqt.mk"
.include <bsd.port.mk>
