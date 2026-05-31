include(CTest)
include(Catch)

add_executable(test_sanity test_sanity.cpp)
target_link_libraries(test_sanity PRIVATE Catch2::Catch2WithMain)
catch_discover_tests(test_sanity)

add_executable(test_types test_types.cpp)
target_link_libraries(test_types PRIVATE entropy_core Catch2::Catch2WithMain)
catch_discover_tests(test_types)
