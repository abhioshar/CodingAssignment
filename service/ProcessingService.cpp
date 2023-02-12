#include <string>
#include <vector>
#include "ProcessingService.h"
#include "../input/FileInput.h"
#include "../util/HashmapGroupingAlgorithm.h"
#include "../output/FileOutput.h"

using namespace std;

void ProcessingService::generateMatchingSentences(Input *input,
                                                  Output *output,
                                                  GroupingAlgorithm *groupingAlgorithm
) {
    // Get input from any source provided by the Driver
    vector<vector<string >> sent = input->getInput();

    // Use strategy to apply any algorithm provided by the Driver to solve the problem
    auto outputSentences = groupingAlgorithm->groupSentences(sent);

    // Write to any output provided by the Driver
    output->write(outputSentences);
}
