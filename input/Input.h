#ifndef ASSIGNMENT_INPUT_H
#define ASSIGNMENT_INPUT_H

#include <string>
#include <vector>

class Input {
public:
    virtual std::vector<std::vector<std::string>> getInput() = 0;
};


#endif //ASSIGNMENT_INPUT_H
