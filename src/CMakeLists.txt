cmake_minimum_required(VERSION 3.2)

add_executable(ip_filter main.cpp)
set_target_properties(ip_filter PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQIRED ON)
target_link_libraries(ip_filter PRIVATE libL1)

if(MSVC)
	target_compile_options(ip_filter PRIVATE /W4)
else()
	target_compile_options(ip_filter PRIVATE -Wall -Wextra -Werror)
endif()

install(TARGETS ip_filter RUNTIME DESTINATION bin)




