#ifndef ASSIGNMENT_PROCESSINGSERVICE_H
#define ASSIGNMENT_PROCESSINGSERVICE_H


#include "../input/Input.h"
#include "../util/GroupingAlgorithm.h"
#include "../output/Output.h"

class ProcessingService {
public:
    static void generateMatchingSentences(Input *input, Output *output, GroupingAlgorithm *
    groupingAlgorithm);
};


#endif //ASSIGNMENT_PROCESSINGSERVICE_H
