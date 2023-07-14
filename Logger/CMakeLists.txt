project(Logger)
set(CMAKE_MINIMUM_REQUIRED_VERSION 3.6)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "/home/tony/Qt/6.2.7/gcc_64")
set(CMAKE_AUTOMOC ON)
find_package(Qt6 COMPONENTS Quick DBus REQUIRED)
list(APPEND SOURCES LogStreamer/LogStreamer.cpp
                    Highlight/Color.cpp
                    )
add_library(Logger SHARED "${SOURCES}")
target_include_directories(Logger INTERFACE "${PROJECT_SOURCE_DIR}/LogStreamer")
target_link_libraries(Logger PRIVATE Qt6::DBus)
set_target_properties(Logger
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../../../Delivery/libraries
)