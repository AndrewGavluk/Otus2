cmake_minimum_required (VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
	project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	project(ip_filter VERSION 1.1.99)
endif()

add_subdirectory (${PROJECT_SOURCE_DIR}/lib)
add_subdirectory (${PROJECT_SOURCE_DIR}/src)
#add_subdirectory (${PROJECT_SOURCE_DIR}/test)
