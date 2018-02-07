#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <limits>
#include <ctime>
#include <vector>

using namespace std;

int wordSelect(int listLength){
    srand(time(NULL));
    int wordNum = (rand() % listLength);

  return wordNum;
}

int main()
{
    vector<string> wordlist = {"practice", "test", "words", "add", "more", "dinosaur", "money", "address"};

    char exitCase;
    // random number
    cout << "Press enter to start." << endl;
    cin.ignore(100, '\n');

    int wordNum = wordSelect(wordlist.size());
    string currWord = wordlist.at(wordNum);
    int wordLength = currWord.length();
    char wordArray[wordLength + 1];
    strcpy(wordArray, currWord.c_str());

    int lettersGuessed = 0;
    int wrongGuesses = 0;

    char wordSoFar[wordLength];
    for(int i = 0; i < wordLength; i++) {
      wordSoFar[i] = 95;
    }

    cout << "The initial state is:" << endl;
    for(int i = 0; i < wordLength; i++) {
      cout << wordSoFar[i] << " ";
    }
    cout << '\n';

    // gameplay (guessing letters and printing)
    while((lettersGuessed < wordLength) && (wrongGuesses < 6)) {
      cout << "You have " << 6 - wrongGuesses << " wrong guesses left." << endl;

      cout << "Guess a letter: ";
      int rightThisRound = 0;
      char letterGuess;
      cin >> letterGuess;

      for(int i = 0; i < wordLength; i++) {

        if((wordArray[i] == letterGuess) || (wordArray[i] == letterGuess + 32) ||
          (wordArray[i] == letterGuess - 32)) {
            wordSoFar[i] = wordArray[i];
            cout << wordSoFar[i] << " ";
            lettersGuessed++;
            rightThisRound++;
          }
        else {
            cout << wordSoFar[i] << " ";
        }
      }
      cout << endl;
      if(rightThisRound == 0) {
        wrongGuesses++;
      }
      cout << endl;
    }

    if(lettersGuessed == wordLength) {
      cout << "Congrats, you win!" << endl;
    }
    else {
      cout << "Sorry, you lose! The word was " << currWord << "." << endl;
    }

    cout << "Enter any letter to close." << endl;

    cin >> exitCase;

    return 0;
}


