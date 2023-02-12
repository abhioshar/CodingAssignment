cmake_minimum_required(VERSION 3.24)
project(assignment)

set(CMAKE_CXX_STANDARD 17)

add_executable(assignment main.cpp driver/Driver.cpp driver/Driver.h input/Input.h input/FileInput.cpp input/FileInput.h output/Output.h output/FileOutput.cpp output/FileOutput.h service/ProcessingService.cpp service/ProcessingService.h util/GroupingAlgorithm.h util/HashmapGroupingAlgorithm.cpp util/HashmapGroupingAlgorithm.h util/SentenceIndex.h)
