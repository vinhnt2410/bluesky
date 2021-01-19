#!/bin/bash

CPP_ROOT=$(realpath ..)
echo ${CPP_ROOT}

C_COMPILER=/usr/bin/gcc
CXX_COMPILER=/usr/bin/g++
JOB=4


BUILD_DIR=${CPP_ROOT}/build
INSTALL_DIR=${CPP_ROOT}/install/x86-gnu-linux
if [ -d ${INSTALL_DIR} ]; then
	rm -r ${INSTALL_DIR}
fi
mkdir -p ${INSTALL_DIR}


PROJECT_BUILD_DIR=${BUILD_DIR}
if [ -d ${BUILD_DIR} ]; then
	rm -r ${BUILD_DIR}
fi
mkdir -p ${PROJECT_BUILD_DIR}
cd ${PROJECT_BUILD_DIR}

cmake \
	-D CMAKE_CXX_COMPILER=${CXX_COMPILER} \
	-D CMAKE_INSTALL_PREFIX=${INSTALL_DIR} \
	${CPP_ROOT}

cmake --build . --target install -- -j${JOB}