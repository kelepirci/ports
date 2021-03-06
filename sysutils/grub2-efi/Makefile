# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	grub2-efi
PORTVERSION=	2.02
PORTREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/
DISTNAME=	grub-${PORTVERSION}_4
WRKSRC=		${WRKDIR}/grub-${PORTVERSION}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Multiboot EFI boot loader

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/mformat:${PORTSDIR}/emulators/mtools \
		${LOCALBASE}/bin/grub-mkrescue:${PORTSDIR}/sysutils/grub2-pcbsd
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		help2man:${PORTSDIR}/misc/help2man

SSP_UNSAFE=	yes
USE_GCC=	yes
USE_AUTOTOOLS=	automake aclocal autoconf
ACLOCAL_ARGS=	-Im4
GNU_CONFIGURE=	yes
USES=		bison gettext gmake python tar:xz
ONLY_FOR_ARCHS=	amd64
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--with-platform=efi --disable-werror --localedir=${PREFIX}/share/locale --disable-grub-mkfont
CONFIGURE_ENV=	CPP="${CC} -E" \
		LEX=${LOCALBASE}/bin/flex

.include <bsd.port.pre.mk>

post-patch:
	@${LN} -s ${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf ${WRKSRC}
	@${TOUCH} -t 200001010000 ${WRKSRC}/Makefile.util.def

pre-configure:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' ${WRKSRC}/autogen.sh
	cd ${WRKSRC} && ./autogen.sh

post-configure:
	@${LN} -sfh /usr/include/machine /usr/include/sys /usr/include/x86 ${WRKSRC}/grub-core

do-install:
	@cd ${WRKSRC}/grub-core && gmake install DESTDIR=${STAGEDIR}

.include <bsd.port.post.mk>

RUN_DEPENDS:=	${RUN_DEPENDS:Ngcc*}
