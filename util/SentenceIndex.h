#ifndef ASSIGNMENT_SENTENCEINDEX_H
#define ASSIGNMENT_SENTENCEINDEX_H


class SentenceIndex {
public:
    SentenceIndex(int sentenceIndex, int wordOfSentenceIndex): sentenceIndex(sentenceIndex),
    wordOfSentenceIndex(wordOfSentenceIndex) {};
    int sentenceIndex;
    int wordOfSentenceIndex;
};


#endif //ASSIGNMENT_SENTENCEINDEX_H
