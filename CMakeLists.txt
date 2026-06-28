cmake_minimum_required(VERSION 3.14)
project(project-entropy VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Clang CONFIG REQUIRED)

if(CINDEX_VERSION_MINOR LESS 60)
    message(FATAL_ERROR
        "libclang version too old (CINDEX_VERSION_MINOR=${CINDEX_VERSION_MINOR}). "
        "Set LLVM_ROOT to your LLVM 17+ install and reconfigure.")
endif()

include(FetchContent)

FetchContent_Declare(cli11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG        v2.4.2
)
FetchContent_Declare(nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3
)
FetchContent_Declare(catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.6.0
)

FetchContent_MakeAvailable(cli11 nlohmann_json catch2)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
