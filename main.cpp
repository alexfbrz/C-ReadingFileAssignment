

#include <cstdlib>
#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <string> 
#include <ctype.h>

using namespace std;


//Will be used to print the map later.
template <class T, class tP>
void PrintMap(map<T, tP> map)
{
    typename std::map<T, tP>::iterator iterator;
    for (iterator = map.begin(); iterator != map.end(); iterator++)
        cout << iterator->first << ": " << iterator->second << endl;
}


int main() {
    
    static const char* fileName = "MyFile.txt";

    // Will store the word and count.
    map<string, int> wordCount;


    {
        // Open the file
        ifstream fileStream(fileName);

        // Checks if the file is opened
        if (fileStream.is_open())
            while (fileStream.good())
            {
                // Stores the words in the file in a local variable.
                string word;
                fileStream >> word;

                //Check to see if the word has already been added 
                if (wordCount.find(word) == wordCount.end()) // For the first time we see a word 
                {
                    wordCount[word] = 1; // Initializes a count to 1
                }
                else // For subsequent times we see a word 
                {
                    wordCount[word]++; // Increments a count
                }
            }
        else  // If the file didn't open
        {
            cerr << "Couldn't open the file." << endl;
            return EXIT_FAILURE;
        }

        // Print the wordMap and count
        PrintMap(wordCount);
    }

    return EXIT_SUCCESS;

    return 0;
}

