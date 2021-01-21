

set(STD_SHARE_PTR_SOURCE_FILES smart_pointer.cpp)
set(STD_SHARE_PTR_HEADER_FILES smart_pointer.hpp)

add_executable(StdSharePtr ${STD_SHARE_PTR_SOURCE_FILES} ${STD_SHARE_PTR_HEADER_FILES})

install(
	FILES ${STD_SHARE_PTR_HEADER_FILES}
	DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)

install(
	TARGETS StdSharePtr
	DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)