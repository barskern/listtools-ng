# vim: set expandtab shiftwidth=2 softtabstop=2 :
# Minste CMake versjon
cmake_minimum_required(VERSION 3.5)

# Må ha støtte for C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ListTools-NG
project (listtools-ng LANGUAGES CXX VERSION 0.0.1)

# Legg til våre filer og eksporterer biblioteket [1]
# TODO: Teste mot en ekstern prosjekt som tar listtools-ng som bibliotek
add_library(listtools-ng INTERFACE)
target_include_directories(listtools-ng INTERFACE listtools-ng.h)


# Inkludert Catch2 test-bibliotek
add_subdirectory(lib/Catch2)
# Legg til test program og inkluder våre lenke til Catch2 [3]
add_subdirectory(tests)


# Lage dokumentasjon [2]
option(BUILD_DOC "Build documentation" OFF)

if (BUILD_DOC)

  find_package(Doxygen)

  if (DOXYGEN_FOUND)
    set(DOXYGEN_CONF ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)

    message("Doxygen build started")

    add_custom_target( doc_doxygen ALL
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONF}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Generating API documentation with Doxygen"
      VERBATIM )
  else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
  endif (DOXYGEN_FOUND)

endif (BUILD_DOC)

# [1] http://mariobadr.com/creating-a-header-only-library-with-cmake.html
# [2] https://vicrucann.github.io/tutorials/quick-cmake-doxygen/
# [3] https://github.com/catchorg/Catch2/blob/master/docs/cmake-integration.md
