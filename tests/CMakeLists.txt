add_executable(
  PolygonTest
  "${PROJECT_SOURCE_DIR}/src/Polygon.cpp" "${PROJECT_SOURCE_DIR}/src/Point.cpp"
  "${PROJECT_SOURCE_DIR}/src/Segment.cpp" PolygonTest.cpp)

target_include_directories(PolygonTest PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(PolygonTest PRIVATE GTest::GTest GTest::Main
                                          GTest::gtest_main)

gtest_discover_tests(PolygonTest)

write_basic_package_version_file(
  PolygonTestConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

install(
  TARGETS PolygonTest
  EXPORT PolygonTest_Targets
  INCLUDES
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
