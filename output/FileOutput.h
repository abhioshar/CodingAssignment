#ifndef ASSIGNMENT_FILEOUTPUT_H
#define ASSIGNMENT_FILEOUTPUT_H


#include "Output.h"

class FileOutput: public Output {
public:
    void write(std::vector<std::string> vector1) override;

};


#endif //ASSIGNMENT_FILEOUTPUT_H
