#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "alphabet.h"

using namespace std;

//int...
int introNum = 0;

int turns = 0;
int p1Turns = 0;
int p2Turns = 0;

//Bool...
bool done = false;

//Strings...
string guess = "";

string p1Name = "Player 1";
string p2Name = "Player 2";

string p1Word = "";
string p2Word = "";

string introCin = "";
string alCin = "";

string p1Pos;
string p1Un;
string p1Prob;

string p2Pos;
string p2Un;
string p2Prob;

//Vectors...
vector < char > alphabetOne;
vector < char > alphabetTwo;

vector < string > p1Words;
vector < string > p2Words;

vector < int > p1Num;
vector < int > p2Num;

//Prototypes...
void intro();
void help();
void mainGame();
void wordEnter();
void NameWordEntry(string &, string &);
void printGame();
void draw();
void Winner(string);
void p1AlphabetEdit();
void p2AlphabetEdit();
void printAlphabet();
bool wordGood(string);
int wordCompare(string);

//CONSTANTS...
const int FILESIZE = 5369;
const int TurnLimit = 20;

//Files...
ifstream words;

//Class...
alphabet p1al;
alphabet p2al;

int main()
{  
    system("clear");
   
    p1al.setStrings(p1Pos, p1Un, p1Prob);
    p1al.setArray(p1al.Letters);

    p2al.setStrings(p2Pos, p2Un, p2Prob);
    p2al.setArray(p2al.Letters);

    turns = 0;

    p1Words.resize(TurnLimit);
    p2Words.resize(TurnLimit);

    p1Num.resize(TurnLimit);
    p2Num.resize(TurnLimit);

    for( int i = 0; i < TurnLimit; i++)
    {
        p1Words[i] = "__________";
        p2Words[i] = "__________";

    }

    cout << "Welcome to Word Game!\n";
    intro();
    return 0;
}

void intro()
{   
    bool loopBreak = false;
    do
    {
        cout << "What would you like to do?\n" << "1) Start a game.\n" << "2) Read the tutorial.\n";
        cin >> introCin;

        if(introCin == "1")
        {
            system("clear");
            mainGame();
            loopBreak = true;
        }
        else if(introCin == "2")
        {
            help();
            loopBreak = true;
        }
        else
        {
            cout << "Please enter the number of what you would like to do.\n";
        }
    }while(loopBreak == false);

}

void help()
{   
    system("clear");
    cout << "Welcome to Word Game!" << endl;
    cout << "Word Game is a word based, deductive logic game in which both players choose a four letter word and try to guess their opponents word before their word is discovered." << endl << endl;
    cout << "Here's how to play." << endl;
    cout << "Input your name and then your four letter word as prompted." << endl;
    cout << "To start the game you will input a four letter word as a guess to what your opponents word is. A number will be shown between 0 and 4 next to your guess." << endl;
    cout << "The number next to the guess is how many letters of your guess are in the word you are trying to discover." << endl;
    cout << "For example if one player's word was MEAN and they're opponent guessed MAKE, the number reported would be 2 because M and E are contained in both words." << endl;
    cout << "If a word has a double letter such as TOOL and the other player guesses SOAK the number reported would be 2 because the O in SOAK matches with both Os in the word TOOL" << endl;
    cout << "You use the number reported to deduce what letters are possible, probable or unlikely to be in your opponents word." << endl; 
    cout << "You can keep track of the letters using the alphabet on the top of the screen." << endl;
    cout << "You only need to select to arrange the alphabet, choose the single letter you would like to move then the number of the section you would like to move it to." << endl;
    cout << "Both players will continue guessing until one player discovers their opponents, or until " << TurnLimit << " rounds have been completed which will result in a draw/tie." << endl;
        
    intro();
}

void mainGame()
{
    string temp;

    NameWordEntry(p1Name, p1Word);
    NameWordEntry(p2Name, p2Word);
    
    printGame();

    do{
        wordEnter();
    }while(!done);


    cout << "Would you like to play again?" << endl << "Yes or No?" << endl;
    cin >> temp;


    if(temp == "yes" || temp == "Yes" || temp == "YES")
    {
        system("g++ game.cpp alphabet.cpp");
        system("./a.out");

    }
}

void wordEnter()
{
    string player;
    //string temp;

    if(turns % 2 == 0)
    {
        player = p1Name;        
        
    }
    else
    {
        player = p2Name;

    }
    
    if(turns > (TurnLimit * 2) - 3)
    {
        cout << player << ", this is your last chance to guess your opponents word." << endl << "Enter your final guess." << endl;
    }
    else
    {
        cout << player << ", enter your guess for your oppenents word." << endl;
    }

    cin >> guess;

    for(int i = 0; i < guess.length(); i++)
    {
        guess[i] = toupper(guess[i]);
    
    }
    
    if(wordGood(guess))
    {
        if(turns % 2 == 0)
        {
            p1Words[p1Turns] = guess;
            p1Num[p1Turns] = wordCompare(guess);
            
            p1Turns++;
        }
        else
        {
            p2Words[p2Turns] = guess;
            p2Num[p2Turns] = wordCompare(guess);
            p2Turns++;
        }
        
        if(!done)
        {
            printGame();
        }
        
        if(!done)
        {
        
        bool loop = true;

            do{
                do{
            
                    cout << "Would you like to edit your alphabet?" << endl;
                    cout << "(Y)es or (N)o" << endl;
                    cin >> alCin;

                }while(alCin != "Y" && alCin != "y" && alCin != "N" && alCin != "n");

                if(alCin == "Y" || alCin == "y")
                {
                    if(turns % 2 == 0)
                    {
                        p1AlphabetEdit();
                    }
                    else
                    {
                        p2AlphabetEdit(); 
                    }

                    printGame();

                }
                else
                {
                    loop = false;
                }

            }while(loop);
        }

        turns++;

        if(!done)
        {
            printGame();
        }

        if(turns == (TurnLimit * 2))
        {
            draw();
        }
    }
    else
    {
        wordEnter();
    }
}
       
void p1AlphabetEdit()
{
    char toChange;
    string section;
    bool temp = false;

    do{
        cout << "What letter would you like to move" << endl;
        cin >> toChange;
        
        toChange = toupper(toChange);
        
        for(int i = 0; i < p1al.Letters.size(); i++)
        {
            if(toChange == p1al.Letters[i])
            {
                temp = true;
                p1al.letterNum = i;
            }
        }

        if(!temp)
        {
            cout << "Please enter a letter." << endl;
        }
         
    }while(!temp);

    do{
        cout << "Enter the number of the section would you like to move " << toChange << "?" << endl;
        cout << "1) Possible" << endl << "2) Unlikely" << endl << "3) Probable" << endl;
        cin >> section;
    
    }while(section != "1" && section != "2" && section != "3");
    
    p1al.letterArrange(section, toChange, p1al.Letters, p1Pos, p1Un, p1Prob);
    printGame();
}

void p2AlphabetEdit()
{
    char toChange;
    string section;
    bool temp = false;

    do{
        cout << "What letter would you like to move" << endl;
        cin >> toChange;

        toChange = toupper(toChange);

        for(int i = 0; i < p2al.Letters.size(); i++)
        {
            if(toChange == p2al.Letters[i])
            {
               temp = true;
               p2al.letterNum = 1;
            }                                                                                   
        }  

        if(!temp)
        {
            cout << "Please enter a letter." << endl;
        }

    }while(!temp);
   
   do{
        cout << "Enter the number of the section would you like to move " << toChange << "?" << endl;
        cout << "1) Possible" << endl << "2) Unlikely" << endl << "3) Probable" << endl;
       
        cin >> section;
   
   }while(section != "1" && section != "2" && section != "3");

    p2al.letterArrange(section, toChange, p2al.Letters, p2Pos, p2Un, p2Prob);
    
    printGame();    
}

void printAlphabet()
{
    if(turns % 2 == 0)
    {
        cout << "Possible:" << p1Pos << endl;
        cout << "Unlikely:" << p1Un << endl;
        cout << "Probable:" << p1Prob << endl;

    }
    else
    {
        cout << "Possible:" << p2Pos << endl;
        cout << "Unlikely:" << p2Un << endl;
        cout << "Probable:" << p2Prob << endl;
    }

    cout << endl;

}

void printGame()
{
    system("clear");

    if(turns % 2 == 0)
    {
        printAlphabet();

    }
    else
    {
        printAlphabet();

    }

    cout << p1Name;
        for(int i = 0; i < 10 - p1Name.length(); i++)
        {
            cout << " ";

        }

        cout << "|";

        for(int i = 0; i < 10 - p2Name.length(); i++)
        {
            cout << " ";

        }
        
        cout << p2Name << endl;
        
        cout << "==========|==========" << endl;

        for( int i = 0; i < TurnLimit; i++)
        {
            if(p1Words[i] != "__________")
            {
                cout << " " << p1Words[i] << " - " << p1Num[i] << " |";
            }
            else
            {
                cout << p1Words[i] << "|";
            }
            
            if(p2Words[i] != "__________")
            {   
                cout << " " << p2Words[i] << " - " << p2Num[i] << " " << endl;
            
            }
            else
            {
                cout << p2Words[i] << endl;
            
            }
        }
        
        cout << endl;

}

void draw()
{
    cout << "The game has concluded in a draw." << endl << endl;
    cout << p1Name << ": " << p1Word << endl;
    cout << p2Name << ": " << p2Word << endl << endl;
    
    done = true;

}

int wordCompare(string guess)
{
    int matched = 0;

    if(turns % 2 == 0)
    {
        for(int i = 0; i < 4; i++)
        {
            if(guess[i] == p2Word[0] || guess[i] == p2Word[1] || guess[i] == p2Word[2] || guess[i] == p2Word[3])
            {
                matched++;

            }
        }
        
        if(guess[0] == p2Word[0] && guess[1] == p2Word[1] && guess[2] == p2Word[2] && guess[3] == p2Word[3])
        {
             Winner(p1Name);
        }
        
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            if(guess[i] == p1Word[0] || guess[i] == p1Word[1] || guess[i] == p1Word[2] || guess[i] == p1Word[3])
            {
                matched++;

            }
        }

        if(guess[0] == p1Word[0] && guess[1] == p1Word[1] && guess[2] == p1Word[2] && guess[3] == p1Word[3])
        {
            Winner(p2Name);

        }
    }

    return matched;

}

void Winner(string winner)
{
    //string response;
    cout << "Congratulations " << winner << ", you have won!" << endl << endl;
    cout << p1Name << ": " << p1Word << endl;
    cout << p2Name << ": " << p2Word << endl << endl;

    done = true;
}

bool wordGood(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = toupper(word[i]);
    } 

    if(word.length() == 4)
    {
        string temp;
        
        words.open("WordGamePossibleWords.txt");

        for(int i = 0; i < FILESIZE; i++)
        {
            getline(words, temp);
                    
            if(word[0] == temp[0] && word[1] == temp[1] && word[2] == temp[2] && word[3] == temp[3])
            {
                words.close();
                return true;
            }
        }
        words.close();
        cout << "Word not found in Word Game Library." << endl;
        return false;
    }
    else
    {
        cout << "Your word was not four letters." << endl;
        return false;
    }
}

void NameWordEntry(string & name, string & word)
{
    system("clear");
    bool temp = false;
    cout << name << ", enter your name.\n";
    cin >> name;

    do{
        cout << name << ", enter your secret four letter word.\n";
        cin >> word;

        for(int i = 0; i < word.length(); i++)
        {
            word[i] = toupper(word[i]);
        }
        
        temp = wordGood(word);
        
    }while(temp == false);

    if(name.length() > 10)
    {
        string temp = name;
        name = "";
        name.resize(10);

        for(int i = 0; i < 10; i++)
        {
            name[i] = temp[i];

        }
    }
    system("clear");
}
