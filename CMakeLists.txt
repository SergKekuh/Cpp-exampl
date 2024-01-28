cmake_minimum_required(VERSION 3.28.1)


set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

#get googletest
include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG release-1.12.0
)
FetchContent_GetProperties(googletest)



# googletest_POPULATED
# googletest_SOURCE_DIR
# googletest_BUILD_DIR

if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

configure_file(version.h.in version.h)
add_library(hellow_Lib STATIC lib.cpp)

add_executable(hellow_App main.cpp)
target_link_libraries(hellow_App 
    hellow_Lib
)

add_executable(test_version test_version.cpp)
target_link_libraries(test_version 
    hellow_Lib
    gtest_main
    gmock_main
)
set_target_properties(hellow_App hellow_Lib test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(hellow_Lib
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(hellow_App PRIVATE
        /W4
    )
    target_compile_options(hellow_Lib PRIVATE
        /W4
    )
    target_compile_options(test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(hellow_App PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(hellow_Lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


install(TARGETS hellow_App RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT serg.kekuh@google.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
