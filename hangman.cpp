/* hangman.cpp */
#include <iostream>
// #include <string>
#include <fstream>
#include <set>
using namespace std;

class WelcomeMessage
{

public:
    static void showWelcomeMessage()
    {
        cout << R"(
______            _ _     _          _     _   _          
|  _  \          ( | |   | |        | |   | | | |         
| | | |___  _ __ |/| |_  | |     ___| |_  | |_| |__   ___ 
| | | / _ \| '_ \  | __| | |    / _ | __| | __| '_ \ / _ \
| |/ | (_) | | | | | |_  | |___|  __| |_  | |_| | | |  __/
|___/ \___/|_| |_|  \__| \_____/\___|\__|  \__|_| |_|\___|
______                           _   _                ___                      _ 
| ___ \                         | | | |              / _ \                    | |
| |_/ /_   _ _ __  _ __  _   _  | |_| | ___  _ __   / /_\ __      ____ _ _   _| |
| ___ | | | | '_ \| '_ \| | | | |  _  |/ _ \| '_ \  |  _  \ \ /\ / / _` | | | | |
| |_/ | |_| | | | | | | | |_| | | | | | (_) | |_) | | | | |\ V  V | (_| | |_| |_|
\____/ \__,_|_| |_|_| |_|\__, | \_| |_/\___/| .__/  \_| |_/ \_/\_/ \__,_|\__, (_)
                          __/ |             | |                           __/ |  
                         |___/              |_|                          |___/   
)" << endl;
    }
};

// The GetWord class has a static method for fetching a random word from the wordList.txt file
class GetRandomWord
{
public:
    static string getRandomWord()
    {
        ifstream file("wordList.txt");

        if (!file.is_open())
        {
            cerr << "Failed to open the file." << endl;
        }

        srand(time(nullptr));
        int randomIndex = rand() % 7773;
        string line;
        string word;
        int index = 0;
        while (getline(file, line))
        {
            if (index == randomIndex)
            {
                word = line;
                // cout << "Random word: " << word << endl;
                break;
            }
            index++;
        }
        file.close();
        return word;
    }
};

// The bunny class. Holds all relevant fields/methods of the game state
class Bunny
{
private:
    string word;
    int hits = 0;
    int misses = 0;
    int wordLength = 0;

public:
    string workingWord;

    // Bunny class constructor
    Bunny(string)
    {
        // Get the random word for this Bunny instance
        word = GetRandomWord::getRandomWord();

        misses = 0;
        for (int i = 0; i < word.length(); i++)
        {
            workingWord += "_";
            workingWord += " ";
            wordLength++;
        }
    }

    string getWord()
    {
        return word;
    }

    string getWorkingWord()
    {
        return workingWord;
    }

    int getHits()
    {
        return hits;
    }
    int getMisses()
    {
        return misses;
    }

    int getWordLength()
    {
        return wordLength;
    }

    // Method to check if game has been lost
    bool gameLost()
    {
        if (misses > 6)
        {
            return true;
        }
        return false;
    }

    // Method to check if game has been won
    bool gameWon()
    {
        if (hits >= wordLength)
        {
            return true;
        }
        return false;
    }

    // Method to show relevant bunny graphic
    void show()
    {
        if (gameLost())
        {
            cout << R"(




























                
            \|/ \|/       \|/                   \|/                     \|/          \|/
   \|/                        \|/   \|/                 \|/     \|/             \|/     
            )" << endl
                 << endl;
        }
        else if (gameWon())
        {
            cout << R"(



















                                                                
                                              ████                              
                                            ██░░░░██                            
                                          ██░░░░░░░░██                          
                                          ██░░░░░░░░██                          
                                        ██░░░░░░░░░░░░██                        
                                        ██░░░░░░░░░░░░██                        
                                        ██░░░░░░░░░░░░██                        
                                          ██░░░░░░░░██                          
                                            ████████                            
            \|/ \|/       \|/                   \|/                     \|/          \|/
   \|/                        \|/   \|/                 \|/     \|/             \|/     
            )" << endl
                 << endl;
        }
        else
        {
            switch (misses)
            {
            case 0:
                cout << R"(




























                
            \|/ \|/       \|/                   \|/                     \|/          \|/
   \|/                        \|/   \|/                 \|/     \|/             \|/     
            )" << endl
                     << endl;
                break;
            case 1:
                cout << R"(




                                                                          
                                                ██████████████                          
                                                  ████████████████                      
                                              ██████████████████████                    
                                                ██████████████████████                  
                                                  ████████    ████████                  
                                              ████████████    ██████████                
                                              ██████████████████████████                
                                            ████████████████████████████                
                                              ████████████████████████                  
                                                ████████████████████                    
                                                  ████████████████                      
                                                    ████████████                        












            \|/ \|/       \|/                   \|/                     \|/          \|/
   \|/                        \|/   \|/                 \|/     \|/             \|/     
            )" << endl
                     << endl;
                break;
            case 2:
                cout << R"(




                              ██████████████                                   
                            ██████████████████  ██████████████                          
                          ██████          ██████  ████████████████                      
                          ██████              ██████████████████████                    
                            ██████              ██████████████████████                  
                            ████████████████████  ████████    ████████                  
                              ████████████████████████████    ██████████                
                                  ██████████  ██████████████████████████                
                                            ████████████████████████████                
                                              ████████████████████████                  
                                                ████████████████████                    
                                                  ████████████████                      
                                                    ████████████                        












            \|/ \|/       \|/                   \|/                     \|/          \|/
   \|/                        \|/   \|/                 \|/     \|/             \|/     
            )" << endl
                     << endl;
                break;
            case 3:
                cout << R"(
                                ██████████████                                          
                              ██████████████████                                        
                              ████████████████████                                      
                              ████          ████████                                    
                              ██████████████  ████████                                  
                            ██████████████████  ██████████████                          
                          ██████          ██████  ████████████████                      
                          ██████              ██████████████████████                    
                            ██████              ██████████████████████                  
                            ████████████████████  ████████    ████████                  
                              ████████████████████████████    ██████████                
                                  ██████████  ██████████████████████████                
                                            ████████████████████████████                
                                              ████████████████████████                  
                                                ████████████████████                    
                                                  ████████████████                      
                                                    ████████████                        












            \|/ \|/       \|/                   \|/                     \|/          \|/
   \|/                        \|/   \|/                 \|/     \|/             \|/     
            )" << endl
                     << endl;
                break;
            case 4:
                cout << R"(
                                ██████████████                                          
                              ██████████████████                                        
                              ████████████████████                                      
                              ████          ████████                                    
                              ██████████████  ████████                                  
                            ██████████████████  ██████████████                          
                          ██████          ██████  ████████████████                      
                          ██████              ██████████████████████                    
                            ██████              ██████████████████████                  
                            ████████████████████  ████████    ████████                  
                              ████████████████████████████    ██████████                
                                  ██████████  ██████████████████████████                
                                            ████████████████████████████                
                                              ████████████████████████                  
                                    ████████████████████████████████                    
                                ████████████████  ████████████████                      
                            ██████████████████████  ████████████                        
                          ████████████████████████████      ██████                      
                          ████████████████████████████████████████                      
                        ██████████████████████████████████████████                      
                      ██████████████████    ██████████████████████                      
                      ██████████████████████  ████████████████████                      
                  ████  ████████████████████  ██████████████████                        
                ████  ████████████████████████                                      
                ████  ████████████████████████                                    
                ██████  ████████████████████                                        
                  ██████  ████████████████                                        
                          ████████████                                          
                              ██████████                                                
            \|/ \|/       \|/                   \|/                     \|/          \|/
   \|/                        \|/   \|/                 \|/     \|/             \|/     
            )" << endl
                     << endl;
                break;
            case 5:
                cout << R"(
                                ██████████████                                          
                              ██████████████████                                        
                              ████████████████████                                      
                              ████          ████████                                    
                              ██████████████  ████████                                  
                            ██████████████████  ██████████████                          
                          ██████          ██████  ████████████████                      
                          ██████              ██████████████████████                    
                            ██████              ██████████████████████                  
                            ████████████████████  ████████    ████████                  
                              ████████████████████████████    ██████████                
                                  ██████████  ██████████████████████████                
                                            ████████████████████████████                
                                              ████████████████████████                  
                                    ████████████████████████████████                    
                                ████████████████  ████████████████                      
                            ██████████████████████  ████████████                        
                          ████████████████████████████      ██████                      
                          ████████████████████████████████████████                      
                        ██████████████████████████████████████████                      
                      ██████████████████    ██████████████████████                      
                      ██████████████████████  ████████████████████                      
                  ████  ████████████████████  ██████████████████                        
                ████  ████████████████████████            ████                          
                ████  ████████████████████████          ██████                          
                ██████  ████████████████████                ████                        
                  ██████  ████████████████                  ██████                      
                          ████████████                    ████████                      
                              ██████████                                                
            \|/ \|/       \|/                   \|/                     \|/          \|/
   \|/                        \|/   \|/                 \|/     \|/             \|/     
            )" << endl
                     << endl;
                break;
            case 6:
                cout << R"(
                                ██████████████                                          
                              ██████████████████                                        
                              ████████████████████                                      
                              ████          ████████                                    
                              ██████████████  ████████                                  
                            ██████████████████  ██████████████                          
                          ██████          ██████  ████████████████                      
                          ██████              ██████████████████████                    
                            ██████              ██████████████████████                  
                            ████████████████████  ████████    ████████                  
                              ████████████████████████████    ██████████                
                                  ██████████  ██████████████████████████                
                                            ████████████████████████████                
                                              ████████████████████████                  
                                    ████████████████████████████████                    
                                ████████████████  ████████████████                      
                            ██████████████████████  ████████████                        
                          ████████████████████████████      ██████                      
                          ████████████████████████████████████████                      
                        ██████████████████████████████████████████                      
                      ██████████████████    ██████████████████████                      
                      ██████████████████████  ████████████████████                      
                  ████  ████████████████████  ██████████████████                        
                ████  ████████████████████████  ████████  ████                          
                ████  ████████████████████████  ██████  ██████                          
                ██████  ████████████████████  ████████████  ████                        
                  ██████  ████████████████  ██████████████████████                      
                          ████████████  ██████  ████████  ████████                      
                              ██████████          ████████                              
            \|/ \|/       \|/                   \|/                     \|/          \|/
   \|/                        \|/   \|/                 \|/     \|/             \|/     
            )" << endl
                     << endl;
                break;
            case 7:
                cout << R"(



























                                
                                                              
            \|/ \|/       \|/                   \|/                     \|/          \|/
   \|/                        \|/   \|/                 \|/     \|/             \|/     
            )" << endl
                     << endl;
                break;

            default:
                break;
            }
        }

        cout << workingWord << endl
             << endl;
    }

    // Method to guess a character
    void guess(char guess)
    {
        bool hit = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == guess)
            {
                workingWord[2 * i] = guess;
                hits++;
                hit = true;
            }
        }
        misses = (hit) ? misses : misses + 1;
    }
};

class Main
{
private:
    bool playAgain = true;
    bool playAnswerGiven;
    bool userHasGivenInput = false;
    string answer;
    bool playing;
    string userInput;
    string word;
    set<char> guessed;

public:
    int run()
    {
        WelcomeMessage::showWelcomeMessage();
        while (playAgain)
        {
            // Initializations
            guessed.clear();
            playing = true;
            playAnswerGiven = false;
            Bunny bunny = Bunny("siberia");

            // Main game loop
            while (playing)
            {
                bunny.show();
                cout << "Guessed: ";

                for (char letter : guessed)
                {
                    cout << letter << ", ";
                }
                cout << endl;
                cout << "Misses remaining: " << (7 - bunny.getMisses()) << "/7" << endl;

                // Loop to accept user input
                userHasGivenInput = false;
                while (!userHasGivenInput)
                {
                    cout << "Guess a Letter: ";
                    cin >> userInput;
                    cout << endl;
                    if (userInput.length() > 1 || !isalpha(userInput[0]))
                    {
                        cout << "Whoops! Only enter single letters." << endl;
                    }
                    else if (guessed.find(tolower(userInput[0])) != guessed.end())
                    {
                        cout << "The letter " << static_cast<char>(tolower(userInput[0])) << " has already been guessed." << endl;
                    }
                    else
                    {
                        guessed.insert(tolower(userInput[0]));
                        bunny.guess(tolower(userInput[0]));
                        userHasGivenInput = true;
                    }
                }

                // Checking game status after round.
                if (bunny.gameWon())
                {
                    bunny.show();
                    cout << endl
                         << endl
                         << "You win! The bunny has left you an egg!" << endl;
                    playing = false;
                }
                else if (bunny.gameLost())
                {
                    bunny.show();
                    cout << "The word was: " << bunny.getWord() << endl;
                    cout << endl
                         << endl
                         << "Oh no, you let the bunny hop away!" << endl;
                    playing = false;
                }

                cout << endl
                     << endl
                     << endl;
            }

            // Loop to accept user input on whether or not to play another round
            while (playAnswerGiven == false)
            {
                cout << "Play again? (y/n): ";
                cin >> answer;
                if (answer == "n")
                {
                    playAgain = false;
                    playAnswerGiven = true;
                }
                else if (answer == "y")
                {
                    playAgain = true;
                    playAnswerGiven = true;
                }
                else
                {
                    cout << "Please answer either \"y\" or \"n\"";
                }
                cout << endl
                     << endl
                     << endl;
            }
        }

        return 0;
    }
};

// The main method
int main()
{
    Main game;
    game.run();
    return 0;
}