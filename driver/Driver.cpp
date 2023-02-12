#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include "Driver.h"
#include "../service/ProcessingService.h"
#include "../input/FileInput.h"
#include "../output/FileOutput.h"
#include "../util/HashmapGroupingAlgorithm.h"

using namespace std;

void Driver::beginProgramExecution() {
    try {
        // Input/Output/GroupingAlgorithm can be of user's choice here
        Input *fileInput = new FileInput();
        Output *fileOutput = new FileOutput();
        GroupingAlgorithm *hashmapGroupingAlgorithm = new HashmapGroupingAlgorithm();

        ProcessingService::generateMatchingSentences(fileInput, fileOutput,
                                                     hashmapGroupingAlgorithm);
    } catch (std::exception& ex) {
        std::cerr<<"Exception occurred: "<<ex.what()<<"\n";
    } catch (...) {
        std::cerr<<"Exception caught while trying to perform program execution!\n";
    }
}
