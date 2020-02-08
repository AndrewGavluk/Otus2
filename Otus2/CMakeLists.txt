cmake_minimum_required (VERSION 3.2)



if($ENV{TRAVIS_BUILD_NUMBER})
 project(02_homework VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER}).0
else()
 project(02_homework VERSION 1.1.999)
endif()

# linking Boost unit test framework
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(GTest REQUIRED)


configure_file (Config.h.in Config.h)

# 1. Main
add_executable(OtusParser Main.cpp)
# 2. add lib
add_library(QuaterByteAdress QuaterByteAdress.cpp)
# 3. add test
add_executable(Otus1BoostTest BoostTest.cpp)
# 4. add gtest
add_executable(Otus1GoogleTest GoogleTest.cpp)

set_target_properties(OtusParser QuaterByteAdress Otus1BoostTest Otus1GoogleTest PROPERTIES
    CXX_STANDARD 14 
	CXX_STANDARD_REQUIRED ON
)# 2. include lib
target_include_directories(QuaterByteAdress
	PRIVATE "${CMAKE_BINARY_DIR}")
# 3. add test
set_target_properties(Otus1BoostTest Otus1GoogleTest 
	PROPERTIES 
	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)


# 2. link lib
target_link_libraries (OtusParser PRIVATE QuaterByteAdress)

# 3. add test
target_link_libraries(Otus1BoostTest
    ${Boost_LIBRARIES}
    QuaterByteAdress
)

# 4 . gtest 
target_link_libraries(Otus1GoogleTest ${GTEST_LIBRARIES} QuaterByteAdress)

# set target compile options
if (MSVC)
	target_compile_options(OtusParser		PRIVATE /W4)
	target_compile_options(QuaterByteAdress PRIVATE /W4)
	target_compile_options(Otus1BoostTest	PRIVATE /W4)
	target_compile_options(Otus1GoogleTest	PRIVATE /W4)
	else ()  
	target_compile_options(OtusParser			PRIVATE -Wall -Wextra -pedantic -Werror)
	target_compile_options(QuaterByteAdress	PRIVATE -Wall -Wextra -pedantic -Werror)
	target_compile_options(Otus1BoostTest	PRIVATE -Wall -Wextra -pedantic -Werror)
	target_compile_options(Otus1GoogleTest	PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS OtusParser RUNTIME DESTINATION bin)

# set cpack parametrs
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT gavl.andr96@gmail.com)

include(CPack)
enable_testing()

# 3. add test
 #add_test(Otus1BoostTest Otus1BoostTest)