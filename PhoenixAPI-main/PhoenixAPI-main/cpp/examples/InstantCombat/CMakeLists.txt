set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
cmake_minimum_required(VERSION 3.10)

project(InstantCombat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Znajdź potrzebne biblioteki
find_package(nlohmann_json CONFIG REQUIRED)
find_package(inih CONFIG REQUIRED)

# Dodaj pliki źródłowe do projektu
add_executable(InstantCombat main.cpp utils.cpp)

# Dołącz biblioteki do projektu
target_link_libraries(InstantCombat PRIVATE nlohmann_json nlohmann_json::nlohmann_json inih)
