file(GLOB_RECURSE srcs CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(nanobench STATIC)
target_sources(nanobench PUBLIC FILE_SET CXX_MODULES FILES ${srcs})
target_include_directories(nanobench PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
include(GNUInstallDirs)
install(
    TARGETS nanobench
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    CXX_MODULES_BMI DESTINATION ${CMAKE_INSTALL_LIBDIR}/cxx/bmi
)
configure_file(${CMAKE_SOURCE_DIR}/packaging/nanobench.pc.in nanobench.pc @ONLY)
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/nanobench.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
