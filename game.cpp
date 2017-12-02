#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

//int...
int introNum = 0;

//Strings...
string guess = "";

string p1Name = "Player 1";
string p2Name = "Player 2";

string p1Word = "";
string p2Word = "";

string introCin = "";

//Vectors...
vector < char > alphabetOne;
vector < char > alphabetTwo;

vector < string > p1Words;
vector < string > p2Words;

//Prototypes...
void intro();
void help();
void mainGame();
void NameWordEntry(string &, string &);
bool wordGood(string);

//CONSTANTS...
const int FILESIZE = 501;

//Files
ifstream words;

int main()
{
    //words.open("ComputerWords.txt");

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
    cout << "Tutorial" << endl;
    intro();
}

void mainGame()
{
    NameWordEntry(p1Name, p1Word);
    NameWordEntry(p2Name, p2Word);

}

bool wordGood(string word)
{

    if(word.length() == 4)
    {
        string temp;
        
        words.open("AvailableWords.txt");

        for(int i = 0; i < FILESIZE; i++)
        {
            getline(words, temp);
            
            cout << temp << endl;
            //std::toupper(temp);
            
            if(word[0] == temp[0] && word[1] == temp[1] && word[2] == temp[2] && word[3] == temp[3])
            {
                words.close();
                return true;
            }
        }
        words.close();
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
        cout << word << endl;
        temp = wordGood(word);
    }while(temp == false);

}
