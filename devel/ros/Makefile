# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ros
PORTVERSION=	1.4.10
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://code.ros.org/svn/release/download/stacks/${STACKNAME}/${STACKNAME}-${PORTVERSION}/
DIST_SUBDIR=	ros

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot Operating System - core utilities

LICENSE=	BSD3CLAUSE

STACKNAME=	${PORTNAME:S/ros-//}

CFLAGS+=	-I${LOCALBASE}/include
LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libgtest.so:${PORTSDIR}/devel/googletest
# we need cmake and gmake for the build, but the build is triggered by make
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		bash:${PORTSDIR}/shells/bash \
		chrpath:${PORTSDIR}/devel/chrpath \
		cmake:${PORTSDIR}/devel/cmake \
		gmake:${PORTSDIR}/devel/gmake
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		bash:${PORTSDIR}/shells/bash \
		cmake:${PORTSDIR}/devel/cmake \
		gmake:${PORTSDIR}/devel/gmake \
		sudo:${PORTSDIR}/security/sudo \
		wget:${PORTSDIR}/ftp/wget
USE_PYTHON=	2
USE_LDCONFIG=	yes
USES=		pkgconfig shebangfix tar:bzip2
SHEBANG_FILES=	core/mk/make_pydev_project.py

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		PATH=${PATH}:${WRKSRC}/bin \
		PYTHONPATH=${WRKSRC}/core/roslib/src \
		ROS_BOOST_ROOT=${LOCALBASE} \
		ROS_PACKAGE_PATH= \
		ROS_ROOT=${WRKSRC}
ALL_TARGET=

SUB_FILES=	pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE} \
		PREFIX=${PREFIX}

PORTDOCS=	AUTHORS README

post-patch:
	${GREP} -l -r "^#! /usr/bin/env python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -E -e "s|^#! /usr/bin/env python$$|#!/usr/bin/env python2|;"
	${GREP} -l -r "^#!/usr/bin/env python$$" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -E -e "s|^#!/usr/bin/env python$$|#!/usr/bin/env python2|;"
	# fix path to bash
	${GREP} -l -r "^#\!/bin/bash" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -E -e "s|#!/bin/bash|#!${LOCALBASE}/bin/bash|"
	# temporarily alter how ROS is built for the port build
	${REINPLACE_CMD} -E -e "s|rosmake --rosdep-install|bin/rosmake --no-rosdep --disable-logging -i -a|" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|COMMAND python|COMMAND python2|' \
		${WRKSRC}/core/rosbuild/public.cmake \
		${WRKSRC}/core/rosbuild/private.cmake

post-build:
	# restore original ROS Makefile
	${MV} ${WRKSRC}/Makefile.bak ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/ros/ros/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/ros/stacks

.for f in rospack rosstack
	${LOCALBASE}/bin/chrpath -d ${WRKSRC}/bin/${f}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/ros/ros/bin
	(cd ${STAGEDIR}${PREFIX} && ${LN} -s ros/ros/bin/${f} bin/${f})
.endfor
.for f in rosbag rosboost-cfg rosclean rosconfig roscore roscreate-pkg \
    roscreate-stack rosdep rosgraph roslaunch roslaunch-deps roslaunch-logs \
    rosmake rosmaster rosmsg rosnode rosparam rosrun rosservice rossrv \
    rostest rostopic rosversion roswtf rxbag rxconsole rxdeps rxgraph \
    rxloggerlevel rxplot
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/ros/ros/bin
	(cd ${STAGEDIR}${PREFIX} && ${LN} -s ros/ros/bin/${f} bin/${f})
.endfor
	${INSTALL_DATA} ${WRKSRC}/bin/rospack_nosubdirs ${STAGEDIR}${PREFIX}/ros/ros/bin

.for f in CMakeLists.txt Makefile rosdep.yaml stack.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/ros/ros
.endfor
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in config core test tools
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig -type f | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${PREFIX}/ros/ros)
.endfor
# strip and symlink libraries to PREFIX/lib
.for f in core/roslib/lib/libroslib.so tools/rospack/lib/librospack.so \
    tools/rospack/lib/librosstack.so
	${CHMOD} 0755 ${STAGEDIR}${PREFIX}/ros/ros/${f}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/ros/ros/${f}
	${LOCALBASE}/bin/chrpath -d ${STAGEDIR}${PREFIX}/ros/ros/${f}
	(cd ${STAGEDIR}${PREFIX} && ${LN} -s ros/ros/${f} lib)
.endfor
# make scripts executable
.for f in core/mk/make_pydev_project.py \
    core/rosbuild/bin/check_same_directories.py \
    core/rosbuild/bin/download_checkmd5.py core/rosbuild/bin/makestackdist \
    core/rosbuild/bin/package_source.py core/rosbuild/bin/roscheck \
    core/rosbuild/bin/rosgcov core/rosbuild/bin/rosgcov_summarize \
    core/rosbuild/bin/rosmakeall core/rosbuild/bin/rosmakeall_osx \
    core/rosbuild/bin/rosmakeall_stackdist core/rosbuild/bin/rossvnignore \
    core/rosbuild/bin/rostar core/rosbuild/tests/count_cores.py \
    core/roslib/scripts/gendeps core/roslib/scripts/pythontest \
    test/test_roslib/test/fake_node.py \
    test/test_rosmake/test/test_parallel_build.py \
    test/test_rosmake/test/test_rosmake_commandline.py \
    test/test_rospack/test/rosbar/scripts/genmsg_bar \
    test/test_rospack/test/rosfoo/scripts/genmsg_foo \
    test/test_rospack/test/utest_rosstack.py tools/rosdep/scripts/rosdep \
    tools/rosemacs/poll-rosnode tools/rosemacs/poll-rostopic \
    tools/rospack/markstack tools/rospack/rosalldeps tools/rospack/rosallpkgs \
    tools/rospack/roscachesvncert tools/rospack/rospack_lite.py \
    tools/rospack/rossearch tools/rosunit/scripts/check_test_ran.py \
    tools/rosunit/scripts/clean_junit_xml.py \
    tools/rosunit/scripts/pycoverage_to_html.py \
    tools/rosunit/scripts/summarize_results.py \
    tools/rosunit/scripts/test_results_dir.py
	${CHMOD} 0555 ${STAGEDIR}${PREFIX}/ros/ros/${f}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

post-install:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O -mcompileall ros/ros/)
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -mcompileall ros/ros/)

.include <bsd.port.mk>
