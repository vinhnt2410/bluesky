

set(SRC_FILES lambda_expression.cpp)
set(HEADER_FILES lambda_expression.hpp)

add_executable(LambdaExpression ${SRC_FILES} ${HEADER_FILES})

install(
	FILES ${HEADER_FILES}
	DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)

install(
	TARGETS LambdaExpression
	DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)