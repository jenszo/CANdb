if (CANdb_FOUND)
    return()
endif(CANdb_FOUND)

add_definitions(-DFMT_HEADER_ONLY)
find_package(spdlog 1.4.2 REQUIRED)

set (CANDB_VERSION ${CANDB_VERSION_MAJOR}${CANDB_VERSION_MINOR}0)
set (CANdb_LIB "CANdb")

# Requiring CXX14 Standard as the API exchanges stl types rather than pod types
# Does this work when importing? At least, imported targets cannot set compile features
# such as target_compile_features(lib PUBLIC cxx_alias_templates)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CANdb_DIR}/include)
link_directories(${CANdb_DIR}/lib)

add_library(${CANdb_LIB} STATIC IMPORTED)

set_target_properties(${CANdb_LIB} PROPERTIES
    IMPORTED_LOCATION_DEBUG ${CANdb_DIR}/lib/lib${CANdb_LIB}d.a
    IMPORTED_LOCATION_RELEASE ${CANdb_DIR}/lib/lib${CANdb_LIB}.a
    IMPORTED_LOCATION_RELWITHDEBINFO ${CANdb_DIR}/lib/lib${CANdb_LIB}.a
)
