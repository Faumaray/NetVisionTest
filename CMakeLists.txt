cmake_minimum_required(VERSION 3.25)

project("NetVisionTest" VERSION 1.0.0)

include(GNUInstallDirs)
include(InstallRequiredSystemLibraries)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE source_list "${PROJECT_SOURCE_DIR}/src/**/*.cpp"
     "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${source_list})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME}
                           PRIVATE "${PROJECT_SOURCE_DIR}/include")

find_package(GTest REQUIRED)

add_subdirectory(tests)

write_basic_package_version_file(
  ${PROJECT_NAME}ConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}_Targets
  INCLUDES
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
