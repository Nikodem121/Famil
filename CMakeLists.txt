cmake_minimum_required(VERSION 3.16)
project(Famil)

set(CMAKE_CXX_STANDARD 17)

# Add main exe file
add_executable(Famil famil.cpp)

# Add subfolders
add_subdirectory(inc)
add_subdirectory(source)

include(FetchContent)

# Sprawdzamy czy SFML już znalezione (czyli find_package działało)
find_package(SFML 2.5 COMPONENTS graphics window system QUIET)

if(NOT SFML_FOUND)
    message(STATUS "SFML nie znaleziono systemowo — pobieram do Utilities!")

    FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        2.6.x
    )

    FetchContent_MakeAvailable(sfml)
endif()
message(${CMAKE_CURRENT_BINARY_DIR}/_deps/sfml-build/lib)
add_custom_command(TARGET Famil POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_BINARY_DIR}/_deps/sfml-build/lib/Debug/sfml-graphics-d-2.dll"
    "${CMAKE_CURRENT_BINARY_DIR}/_deps/sfml-build/lib/Debug/sfml-system-d-2.dll"
    "${CMAKE_CURRENT_BINARY_DIR}/_deps/sfml-build/lib/Debug/sfml-window-d-2.dll"
    $<TARGET_FILE_DIR:Famil>
)

target_link_libraries(Famil sfml-graphics sfml-window sfml-system)
