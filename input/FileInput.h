#ifndef ASSIGNMENT_FILEINPUT_H
#define ASSIGNMENT_FILEINPUT_H


#include "Input.h"

class FileInput: public Input {
public:
    std::vector<std::vector<std::string>> getInput() override;
};


#endif //ASSIGNMENT_FILEINPUT_H
