# Assignment

## Overview of the solution:

*Assumptions:* 
1. I've assumed there are no special characters in the input
2. Sentence matching has to preserve the relative ordering of the words as given in input

I've used interfaces for Input/Output/Grouping algorithm which use single responsibility and 
strategy for choosing grouping algorithm at runtime.

Class Flow is:

#### Main method -> Driver -> ProcessingService -> Input -> ProcessingService -> GroupingAlgorithm -> 
ProcessingService -> Output ####

#### Algorithm ####
The solution uses hashmap based approach for solving.
Hashmap has sentence as the key(omitting a single word at a time) which maps to a vector of pair of 
two 
values.

First value of the pair: the index of the mapped line
in the file. Second: the index of word omitted from he line.


Eg: a line from file

*01-01-2012 19:45:00 Naomi is getting into the car*

We generate a linked list from a given sentence omitting a single word. Why linked list? Because 
it has contant insertion/deletion time for an entry which will help us later when we remove a 
word at a time from a line to generate key for a hashmap.

Eg. for example for above line from file would generate six hashmap entries

Map: 
1. is getting into the car (omitting 1st word)
2. Naomi getting into the car (omitting 2nd word)
3. ... so on... for all the lines

Each key in the hashmap, maps to list of {lineIndex, wordIndexInLine} pair.

Eg for above hashmap:

1. [is getting into the car] -> {{0 (line index in original file, 0 (index of the word omitted, 
   here it's 0}}
2. [Naomi getting into the car] -> {{1 (line index is now 1, 1 (the word omitted had index 1}}


If another line anywhere in the file matches any entry in the above map, we add the {lineIndex, 
wordIndex) pair to the map key.

Eg: in above example if some line arrives (assume line number 3) which is: 

*"John is getting into the car"*

Here omitting the first word we get -> "is getting into the car". This matches the first entry 
from the map above. Hence, we'll add this line index to the map , and it becomes:

[is getting into the car] -> {{0, 0}, {2,0}}

In this way after we iterate over all the lines in the file, we'll have all the lines which have 
one changed word will map to the same key in the map. And later we can generate the output 
required from the map value viz. line index and the word changed.

## How to run?

1. It's a CMAKE C++ project created on Windows. I've used CLion IDE to make it. It can be directly 
   imported 
   on CLion. 
   However, any IDE with C++ and CMake support will be able to open it. Make sure to install C++ 
   compiler 
   as well eg. MinGW on Windows. No extra setup/libraries required as only language built-in 
   features have been used.

2. I've added sample input and output files, so they can be used directly. These are in */files* 
   directory in root.

## Other Questions
### 1. What can you say about the complexity of your code? ###

    
    ### Time Complexity ###
    
    Let,
    
    N: Total lines in the file
    
    W: Max words in a line
    
    HashMap: Each entry in map takes O(1) amortized time to search/update etc where N are number of 
    entries in the map. Here I'm using list as the key of the hashmap, hence, complexity will
    become O(1) * (time taken by hashmap to generate hash for the the key, which here is O(no. of 
    words in a line(W))) as each key in hashmap has list of O(W) words.
    
    Total complexity: N * W * W

    As, when we are processing each line, we are omitting one word at a time. Hence, we iterate over 
    each line W times (=> N * W). And, each operation over hashmap is O(W). Hence, O(N * W * W) 
    total complexity.

    It can be improved by using a better hash function. Because of limited time I've used this 
    approach.

    ### Space Complexity ###

    Extra storage used is Hashmap, complexity: O(N * W)

### 2. How will your algorithm scale? ###
    

    2.1 Time wise, algorithm with scale linearly with no. of input lines and quadratically with no.
    of words used in a line

    2.2 Space wise, algorithm will scale linearly w.r.t input

    2.3 Input/Output wise, I've used interfaces which can be implemented to support various other
    input/output sources, following the Single Responsibility and Open/Closed Solid principle.

    2.4 Support for any grouping algorithm can be made, as I've used strategy pattern to select
    any algorithm. Interface "util/GroupingAlgorithm" can be implemented to implement any other 
    algorithm for grouping the sentences, following the Single Responsibility and Open/Closed Solid 
    principle.


### 3. If you had two weeks to do this task, what would you have done differently? What would be better? ###


    3.1 Start with UML/Class diagrams to better understand/communicate the system. 

    3.2 Make algorithm more optimal by using better hashing function.

    3.3 Adding Unit test cases.

    3.4 Adding better Exception Handling.

    3.5 Use Test Driven Development.

    3.6 Add better logging.

    3.7 Add support for multiple files.

    3.8 Add multiple input/output sources.

    3.9 If time permitted, I'd have researched if we can add support for files larger than memory 
    and using multithreading to solve the problem.


