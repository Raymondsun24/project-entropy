add_library(entropy_core STATIC entropy_core.cpp)

target_include_directories(entropy_core
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${LLVM_INCLUDE_DIRS}
)

target_link_libraries(entropy_core
    PUBLIC
        libclang
        nlohmann_json::nlohmann_json
)

add_executable(entropy main.cpp)

target_link_libraries(entropy
    PRIVATE
        entropy_core
        CLI11::CLI11
)
