# Inkluder våre og lenke til Catch2 [1]
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Legg till testfilene
add_executable(ListTests list_test.cpp option_test.cpp)

# Lenke filene opp mot Catch2
target_link_libraries(ListTests Catch)

# [1] https://github.com/catchorg/Catch2/blob/master/docs/cmake-integration.md
