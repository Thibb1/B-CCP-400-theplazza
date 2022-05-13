cmake_minimum_required(VERSION 3.17)
project(plazza)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -fpermissive)
add_executable(plazza
        src/Main.cpp
        src/Pizza.cpp
        src/Kitchen.cpp
        src/RegexUtils.cpp
        src/Parse.cpp
        src/Encapsulation/ConditionalVariable.cpp
        src/Encapsulation/Mutex.cpp
        src/Encapsulation/Process.cpp
        src/Encapsulation/Thread.cpp
        src/Reception.cpp)
target_include_directories(plazza PUBLIC includes src/Encapsulation)
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES ${PROJECT_SOURCE_DIR}/plazza)
add_custom_command(TARGET plazza POST_BUILD COMMAND cp plazza ${PROJECT_SOURCE_DIR})