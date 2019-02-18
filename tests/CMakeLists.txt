# Legg till testfilene
add_executable(ListTests list_test.cpp option_test.cpp)

# Lenke filene opp mot Catch2
target_link_libraries(ListTests Catch2::Catch2)

# Legg til støtte for bruk av CTest
include(CTest)
include(${CMAKE_SOURCE_DIR}/lib/Catch2/contrib/Catch.cmake)
catch_discover_tests(ListTests)
