##########################################################################################
# ┌──────────────────────────────────────────────────────────────────────────────────────┐
# │                                                                                      │
# │      CMake build script                                                              │
# │  * * * * * * * * * * * * *                                                           │
# │                                                                                      │
# └──────────────────────────────────────────────────────────────────────────────────────┘
##########################################################################################
##########################################################################################
cmake_minimum_required(VERSION 3.12.3 FATAL_ERROR)



##########################################################################################
# ┌──────────────────────────────────────────────────────────────────────────────────────┐
# │  CMake check build type                                                              │
# └──────────────────────────────────────────────────────────────────────────────────────┘
##########################################################################################
option(CMAKE_BUILD_TYPE "Setting build type to release build" OFF)
option(CMAKE_BUILD_TYPE "Setting build type to debug build"   ON )
option(BUILD_TESTING    "Setting build type to debug build"   ON )



##########################################################################################
# ┌──────────────────────────────────────────────────────────────────────────────────────┐
# │  CMake check build type                                                              │
# └──────────────────────────────────────────────────────────────────────────────────────┘
##########################################################################################
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()
#end

project(CMakeProject 
    VERSION 1.0.2 
    LANGUAGES CXX
    DESCRIPTION "Simple general purpose CMake project written for C++ programmers." 
    HOMEPAGE_URL "https://github.com/sqdfarts/cmake-project-cxx"
)


##########################################################################################
# ┌──────────────────────────────────────────────────────────────────────────────────────┐
# │  CMake include modules                                                               │
# └──────────────────────────────────────────────────────────────────────────────────────┘
##########################################################################################
# This helps CMake with GNU install paths
include(GNUInstallDirs)

# This helps CMake with config files
include(CMakePackageConfigHelpers)

# Enable tests as long as BUILD_TESTING is ON
include(CTest)

# Enable LTO on Release builds
include(CheckIPOSupported)



##########################################################################################
# ┌──────────────────────────────────────────────────────────────────────────────────────┐
# │  RPATH set paths support                                                             │
# │  This assumes exe vs lib is <prefix>/<bindir>/exe vs <prefix>/<libdir>/lib		 │
# └──────────────────────────────────────────────────────────────────────────────────────┘
##########################################################################################
if(APPLE)
    set(CMAKE_INSTALL_RPATH "@loader_path/../${CMAKE_INSTALL_LIBDIR}")
else()
    set(CMAKE_INSTALL_RPATH "\$ORIGIN/../${CMAKE_INSTALL_LIBDIR}")
endif()

# Don't worry about .dll .def files or __declspec macros
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


##########################################################################################
# ┌──────────────────────────────────────────────────────────────────────────────────────┐
# │  CTest setting up support                                                            │
# └──────────────────────────────────────────────────────────────────────────────────────┘
##########################################################################################
check_ipo_supported(RESULT ipo_supported)
if(ipo_supported)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
endif()

# Enable running and testing on Windows under Debug
# To test other configs, just `install' to a local dir before testing
if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
endif()


##########################################################################################
# ┌──────────────────────────────────────────────────────────────────────────────────────┐
# │  CMake adding sub directories                                                        │
# └──────────────────────────────────────────────────────────────────────────────────────┘
##########################################################################################
add_subdirectory(external)
# add_subdirectory(utils   )
add_subdirectory(source)

if(BUILD_TESTING)
    add_subdirectory(test)

endif()



##########################################################################################
# ┌──────────────────────────────────────────────────────────────────────────────────────┐
# │  CMake install executable /CPack config file                                         │
# └──────────────────────────────────────────────────────────────────────────────────────┘
##########################################################################################
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/installation/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}/"
)


install(FILES "${CMAKE_CURRENT_BINARY_DIR}/installation/${PROJECT_NAME}Config.cmake"
    COMPONENT Development
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)


# Write and install a version file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/installation/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION "${PROJECT_VERSION}"
    COMPATIBILITY "ExactVersion"
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/installation/${PROJECT_NAME}ConfigVersion.cmake"
    COMPONENT Development
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}/"
)



##########################################################################################
# ┌──────────────────────────────────────────────────────────────────────────────────────┐
# │  CPack setting up support                                                            │
# └──────────────────────────────────────────────────────────────────────────────────────┘
##########################################################################################
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}"                                )
set(CPACK_PACKAGE_VENDOR "Squid Developer labs"                         )
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Simple CMake project in C++."    )
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md")
set(CPACK_RESOURCE_FILE_README  "${CMAKE_CURRENT_SOURCE_DIR}/README.md" )



##########################################################################################
# ┌──────────────────────────────────────────────────────────────────────────────────────┐
# │  CPack include module                                                                │
# └──────────────────────────────────────────────────────────────────────────────────────┘
##########################################################################################
include(CPack)

