if((CANDB__WITH_TESTS OR CANDB__WITH_COVERAGE))
    set(INSTALL BUILD_GMOCK OFF CACHE BOOL "")
    set(INSTALL GTEST OFF CACHE BOOL "")
    add_subdirectory(gtest)
endif((CANDB__WITH_TESTS OR CANDB__WITH_COVERAGE))

if(CANDB__WITH_TOOLS)
    add_subdirectory(termcolor)
    set(CXXOPTS_BUILD_EXAMPLES OFF CACHE BOOL "")
    set(CXXOPTS_BUILD_TESTS OFF CACHE BOOL "")
    add_subdirectory(cxxopts)
endif(CANDB__WITH_TOOLS)

add_library(cpp-peglib INTERFACE)
target_include_directories(cpp-peglib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/cpp-peglib)

if (CANDB__TRAVIS_BUILD)
    add_library(${LIBSPDLOG} INTERFACE)
    target_include_directories(${LIBSPDLOG} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include)
endif (CANDB__TRAVIS_BUILD )

add_library(expected INTERFACE)
target_include_directories(expected INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/expected)
add_library(tl::expected ALIAS expected)
