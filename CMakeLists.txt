cmake_minimum_required(VERSION 3.28.1)

project(stone)

#get googletest
include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG release-1.12.0
)
FetchContent_GetProperties(googletest)



if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()


add_library(stone_Lib STATIC stonewt.cpp)

add_executable(stone_App stonewt.h stone.cpp)
target_link_libraries(stone_App 
    stone_Lib
)


add_executable(stone_Test gtest_stone.cpp)
target_link_libraries(stone_Test 
    stone_Lib
    gtest_main
    gmock_main
)
set_target_properties(stone_App stone_Lib stone_Test PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(stone_Lib
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(stone_App PRIVATE
        /W4
    )
    target_compile_options(stone_Lib PRIVATE
        /W4
    )
    target_compile_options(stone_Test PRIVATE
        /W4
    )
else ()
    target_compile_options(stone_App PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(stone_Lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(stone_Test PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


install(TARGETS stone_App RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT serg.kekuh@google.com)

include(CPack)

enable_testing()

add_test(stone_Test stone_Test)
