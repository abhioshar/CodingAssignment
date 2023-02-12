//
#ifndef ASSIGNMENT_GROUPINGALGORITHM_H
#define ASSIGNMENT_GROUPINGALGORITHM_H

#include <string>
#include <vector>

class GroupingAlgorithm {
public:
    virtual std::vector<std::string>
    groupSentences(std::vector<std::vector<std::string>> &sentences) = 0;
};


#endif //ASSIGNMENT_GROUPINGALGORITHM_H
