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


LAMBDA_EXPRESSION=${BUILD_DIR}/lambda_expression
if [ -d ${LAMBDA_EXPRESSION} ]; then
	rm -r ${LAMBDA_EXPRESSION}
fi
mkdir -p ${LAMBDA_EXPRESSION}
cd ${LAMBDA_EXPRESSION}

cmake \
	-D CMAKE_CXX_COMPILER=${CXX_COMPILER} \
	-D CMAKE_INSTALL_PREFIX=${INSTALL_DIR} \
	${CPP_ROOT}/src/lambda_expression

cmake --build . --target install -- -j${JOB}