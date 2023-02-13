#include <fstream>
#include <iostream>
#include <sstream>
#include "FileInput.h"

std::vector<std::vector<std::string>> FileInput::getInput() {
    std::cout<<"Started getting file input...\n";
    std::ifstream inputFile;
    std::vector<std::vector<std::string>> inputFileSentences;
    inputFile.open("../files/PrivateInvestigator.txt", std::ios::in);

    if (!inputFile) {
        throw std::ios::failure( "Error opening the input file!" ) ;
    }

    if (inputFile.is_open()) {
        std::string sentence;
        while (getline(inputFile, sentence)) {
            std::vector<std::string> line;
            std::istringstream streamLine(sentence);
            std::string word;

            while (getline(streamLine, word, ' ')) {
                line.push_back(word);
            }
            inputFileSentences.push_back(line);
        }
        inputFile.close();
    }

    std::cout<<"Returning file input...\n";
    return inputFileSentences;
}
