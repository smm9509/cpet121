//	===============================================================
//  Filename:		main.cpp
//	Title:			hangman_extracredit
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-18
//  Description:    2022S_dp4_Hangman
//                  define the main function
//	===============================================================

// Template Header Comment for File:
//	===============================================================
//   Filename:
//   Title:          hangman_extracredit
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-21
//   Description:
//	===============================================================

// Template Header Comment for Function:
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name:
//	Input:
//	Output:
//	Purpose:
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "hangman.h"
#include <cassert>
#include <string>

using namespace std;

int main()
{
    // main loop

    bool playAgain = true;

    while (playAgain)
    {
        string word = randWord();
        log(string("the chosen word is " + word + ".\n"));
        int lettercount = 0;
        for (size_t i = 0; i < word.size(); ++i)
        {
            word.insert(i, " ");
            ++i; // skip inserted space
        }
        for (int i = 0; i < word.size(); ++i)
        {
            assert(isalpha(word.at(i)) || word.at(i) == ' ');
            if (isalpha(word.at(i)))
            {
                lettercount++;
            }
        }
        printf("The word has %d letters.\n", lettercount);

        // loop for one game

        bool playing = true;
        unsigned int losses = 0;
        string guessedLetters = "";

        while (playing)
        {
            // clear the screen a bit
            const int REFRESH_BREAK_SIZE = 5;
            for (int i = 0; i < REFRESH_BREAK_SIZE; ++i)
            {
                print("");
            }

            printGallows(losses);

            // create a string with *s where the player hasn't
            // guessed and letters that the player has guessed,
            // in the shape of the word
            string playerProgress = convertToStars(word);
            for (int i = 0; i < guessedLetters.size(); i++)
            {
                /*targetedReplace(
                    word,
                    playerProgress,
                    string(1, guessedLetters.at(i)),
                    string(1, guessedLetters.at(i))
                );*/
                //need to modify targetedReplace ;-;
                //modified version: replaces with the piece from
                //the workarea instead of with the replace string.
                {
                    const string& find = 
                        string(1, guessedLetters.at(i));
                    string& workArea = playerProgress;
                    const string& places = lowerString(word);

                    assert(places.size() == workArea.size());
                    size_t index = 0;
                    while (true//there is a break statement inside
                    ) 
                    {
                        //find a substring to replace
                        index = places.find(find, index);
                        //if nothing found, stop.
                        if (index == string::npos)
                        {
                            break;
                        }

                        //replace what was found
                        workArea.replace(
                            index, 
                            find.size(), 
                            word.substr(index, find.size())
                        );
                        
                        //advance the index to not replace the same thing over and over again
                        index += find.size();
                    }
                }
            }
            dispayWord(playerProgress);
            //count number of unfound words
            int numStars = 0;
            replaceAll(playerProgress, "*", "", numStars);
            if(numStars == 0)
            {
                log("\nThe user successfully found the word.");
                print("Congratulations! You won!");
                print("ENTER anything to continue."); userInput();
                break;
            }
            if(losses == 8)
            {
                log("\nThe user failed to find the word.");
                print("Sorry, you've lost. :(");
                int temp;
                print("The test word was " + 
                    replaceAll(word, " ", "", temp));
                print("\nENTER anything to continue."); userInput();
                break;
            }
            bool validguess = false;
            while(!validguess)
            {
                print("guess a letter: ");
                char guess = tolower(userInput());

                // find if it's in the string of guesses
                int timesGuessedBefore = 0;
                replaceAll(
                    guessedLetters,
                    string(1, guess),
                    " ",
                    timesGuessedBefore
                );
            
                switch (timesGuessedBefore)
                {
                    case 0:
                    {
                        validguess = true;
                        guessedLetters.push_back(guess);
                        // look for the guess in the word
                        int occurancesInWord = 0;
                        replaceAll(
                            lowerString(word),
                            string(1, guess),
                            " ",
                            occurancesInWord
                        );
                        //check if the letter exists in the word
                        if (occurancesInWord == 0)
                        { //if not, the player looses.
                            losses++;
                            log(string(
                                "The character " +
                                string(1, guess) +
                                " was not found! "
                                "The error count is " +
                                to_string(losses) +
                                "."));
                            // now just go back to the start of the loop
                            // and re-print the gallows with worse status

                        }
                        else
                        { //if yes, the player wins
                            log(string(
                                "The character " +
                                string(1, guess) +
                                " was found!"));
                            // now just go back to the start of the loop
                            // and re-print the word with the letter revealed
                        }
                    }
                        break;
                    case 1:
                        validguess = false;
                        print("You've already guessed that letter.");
                        print(
                            "You've guessed the letters - " +
                            guessedLetters +
                            " - so far.");
                        break;

                    default:
                        exit(123); // shouldn't be more than one occurance
                }
            }
        }

        bool validAnswer = false;
        while (!validAnswer)
        {
            print("Would you like to play again? [y/n]");
            char answer = userInput();
            if (tolower(answer) == 'y' || tolower(answer) == 'n')
            {
                validAnswer = true;
            }
            else
            {
                print("Bad answer. Please answer [y/n].");
            }
            playAgain = tolower(answer) == 'y';
        }
    }

    return 0;
}