#ifndef ASSIGNMENT_OUTPUT_H
#define ASSIGNMENT_OUTPUT_H
#include <vector>
#include <string>

class Output {
public:
    virtual void write(std::vector<std::string>) = 0;
};


#endif //ASSIGNMENT_OUTPUT_H
