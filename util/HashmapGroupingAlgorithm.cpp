#include <list>
#include <map>
#include <algorithm>
#include "HashmapGroupingAlgorithm.h"
#include "SentenceIndex.h"

std::vector<std::string>
HashmapGroupingAlgorithm::groupSentences(std::vector<std::vector<std::string>> &sentences) {

    std::vector<std::string> outputLines;
    std::map<std::list<std::string>, std::vector<SentenceIndex>> sentenceToIndicesMap;

    for (int i = 0; i < sentences.size(); ++i) {
        auto line = sentences[i];
        std::list<std::string> listOfWords;
        for (auto wordInLine: line) {
            // Make comparison case-insensitive
            transform(wordInLine.begin(), wordInLine.end(), wordInLine.begin(), ::tolower);
            listOfWords.push_back((wordInLine));
        }

        // Clear any dates in the beginning of each line
        listOfWords.pop_front();
        listOfWords.pop_front();

        auto listOfWordsIterator = listOfWords.begin();

        // Omit each word one by one from listOfWords and map the generated list to its
        // index in the given sentences vector
        //
        // Also, map the position of the word which is omitted (this will become the changing word
        // as required in the output
        for (int j = 0; j < listOfWords.size(); ++j) {
            std::string currWord = *listOfWordsIterator;
            listOfWordsIterator = listOfWords.erase(listOfWordsIterator);
            sentenceToIndicesMap[listOfWords].emplace_back(i, j);
            listOfWordsIterator = listOfWords.insert(listOfWordsIterator, currWord);
            listOfWordsIterator++;
        }
    }

    for (auto &hashedLine: sentenceToIndicesMap) {
        std::string changingLine = "The changing word was: ";

        // No lines are as same as this one
        if ((hashedLine.second).size() <= 1) continue;

        for (auto &hashedPair: hashedLine.second) {
            std::string outputLine;
            int sentenceIndex = hashedPair.sentenceIndex;
            int wordIndex = hashedPair.wordOfSentenceIndex;

            for (const auto &word: sentences[sentenceIndex]) {
                outputLine += word + " ";
            }

            changingLine += sentences[sentenceIndex][wordIndex + 2] + ", ";
            outputLines.push_back(outputLine);
        }

        changingLine = changingLine.substr(0, changingLine.size() - 2);
        outputLines.push_back(changingLine);
    }

    return outputLines;
}
