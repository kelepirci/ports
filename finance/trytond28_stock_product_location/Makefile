# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_stock_product_location
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_stock_product_location/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_stock_product_location-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Stock Product Location Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_product>=2.8.0:${PORTSDIR}/finance/trytond28_product \
		trytond28_stock>=2.8.2:${PORTSDIR}/finance/trytond28_stock

CONFLICTS=	trytond_stock_product_location-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
