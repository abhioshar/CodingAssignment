#ifndef ASSIGNMENT_HASHMAPGROUPINGALGORITHM_H
#define ASSIGNMENT_HASHMAPGROUPINGALGORITHM_H


#include "GroupingAlgorithm.h"

class HashmapGroupingAlgorithm : public GroupingAlgorithm {
public:
    std::vector<std::string>
    groupSentences(std::vector<std::vector<std::string>> &sentences) override;

};


#endif //ASSIGNMENT_HASHMAPGROUPINGALGORITHM_H
