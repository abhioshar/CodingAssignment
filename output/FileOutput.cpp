#include "FileOutput.h"
#include <iostream>
#include <fstream>

void FileOutput::write(std::vector<std::string> vector1) {
    std::cout<<"Started writing file output...\n";
    std::fstream outputFile;
    outputFile.open("../files/output.txt", std::ios::out);
    if (!outputFile) {
        throw std::ios::failure( "Error opening the output file!" ) ;
    }
    if (outputFile.is_open()) {
        for (const auto &sentence: vector1) {
            outputFile << sentence << "\n";
        }
        outputFile.close();
    }

    std::cout<<"File output written successfully\n";
}
