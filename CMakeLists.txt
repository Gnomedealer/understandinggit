cmake_minimum_required(VERSION 3.20)
project(IntroComSciStuff VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug)
endif()

option(INTRO_SANITIZE "Build with AddressSanitizer and UBSan (catches memory bugs)" OFF)

# Shared settings: strict warnings, optional sanitizers.
add_library(intro_options INTERFACE)
if(MSVC)
  target_compile_options(intro_options INTERFACE /W4 /permissive-)
else()
  target_compile_options(intro_options INTERFACE -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
  if(INTRO_SANITIZE)
    target_compile_options(intro_options INTERFACE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(intro_options INTERFACE -fsanitize=address,undefined)
  endif()
endif()

# Reusable code lives in a library so the app and the tests can both use it.
add_library(intro src/mathutils.cpp)
target_include_directories(intro PUBLIC include)
target_link_libraries(intro PUBLIC intro_options)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE intro)

# Every labs/<name>.cpp becomes its own program called <name>.
file(GLOB LAB_SOURCES CONFIGURE_DEPENDS labs/*.cpp)
foreach(lab_source ${LAB_SOURCES})
  get_filename_component(lab_name ${lab_source} NAME_WE)
  add_executable(${lab_name} ${lab_source})
  target_link_libraries(${lab_name} PRIVATE intro)
  set_target_properties(${lab_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/labs)
endforeach()

include(CTest)
if(BUILD_TESTING)
  add_executable(test_mathutils tests/test_mathutils.cpp)
  target_link_libraries(test_mathutils PRIVATE intro)
  add_test(NAME mathutils COMMAND test_mathutils)
endif()
