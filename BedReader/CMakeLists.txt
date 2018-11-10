project(FastaReader)

set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")
add_executable (BedReader src/main.cpp src/BEDreader.cpp)
