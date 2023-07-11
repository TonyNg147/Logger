project(COlor)
cmake_minimum_required(VERSION 3.6)
set(CXX_STANDARD_REQUIRED 14)
list(APPEND SOURCES Highlight/Color.cpp 
                    LogStreamer/LogStreamer.cpp
                    main.cpp)
add_executable(COLOR ${SOURCES})
