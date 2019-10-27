# vim: set expandtab shiftwidth=2 softtabstop=2 :

# Minste CMake versjon
cmake_minimum_required(VERSION 3.9)

# Må ha støtte for C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ListTools-NG
project(
  listtools-ng
  LANGUAGES CXX
  VERSION 0.0.1
  HOMEPAGE_URL http://barskern.no/listtools-ng
  DESCRIPTION "Et bibliotek bestående av en headerfil som implementerer en lenket liste")

# Legg til våre filer og eksporterer biblioteket [1]
# TODO: Teste mot en ekstern prosjekt som tar listtools-ng som bibliotek
add_library(listtools-ng INTERFACE)
target_include_directories(listtools-ng INTERFACE listtools-ng.h)

# Inkludert Catch2 test-bibliotek
add_subdirectory(lib/Catch2)
# Legg til test program og inkluder våre lenke til Catch2 [3]
add_subdirectory(tests)

# Generer dokumentasjon vha. Doxygen.  Benytter innebygd Doxygen støtte
# https://cmake.org/cmake/help/latest/module/FindDoxygen.html
find_package(Doxygen)

if(DOXYGEN_FOUND)
  set(DOXYGEN_OUTPUT_LANGUAGE Norwegian)
  set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)
  doxygen_add_docs(
    docs
    ${PROJECT_SOURCE_DIR}/listtools-ng.h
    ${PROJECT_SOURCE_DIR}/README.md
    COMMENT "Genererer API-dokumentasjon for listtools-ng.")
endif(DOXYGEN_FOUND)

# [1] http://mariobadr.com/creating-a-header-only-library-with-cmake.html
# [3] https://github.com/catchorg/Catch2/blob/master/docs/cmake-integration.md
