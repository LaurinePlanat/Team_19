project(FastaReader)

set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")
add_executable (FastaReader src/test_fasta.cpp src/fastareader.cpp)
