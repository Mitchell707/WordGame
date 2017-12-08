#include <iostream>
#include "alphabet.h"

using namespace std;

alphabet alph;

void alphabet::setStrings()
{
    alph.possible = " A B C D E F G H I K L M N O P Q R S T U V W X Y Z";
    alph.unlikely = "                                                  ";
    alph.probable = "                                                  ";
}

void alphabet::setArray()
{   
    alph.Letters.resize(25);

    alph.Letters[0] = 'A';
    alph.Letters[1] = 'B';
    alph.Letters[2] = 'C';
    alph.Letters[3] = 'D';
    alph.Letters[4] = 'E';
    alph.Letters[5] = 'F';
    alph.Letters[6] = 'G';
    alph.Letters[7] = 'H';  
    alph.Letters[8] = 'I';
    alph.Letters[9] = 'J';
    alph.Letters[10] = 'K';
    alph.Letters[11] = 'L';
    alph.Letters[12] = 'M';
    alph.Letters[13] = 'N';
    alph.Letters[14] = 'O';
    alph.Letters[15] = 'P';
    alph.Letters[16] = 'Q';
    alph.Letters[17] = 'R';
    alph.Letters[18] = 'S';
    alph.Letters[19] = 'T';
    alph.Letters[20] = 'U';
    alph.Letters[21] = 'V';
    alph.Letters[22] = 'W';
    alph.Letters[23] = 'X';
    alph.Letters[24] = 'Y';
    alph.Letters[25] = 'Z';

}

void alphabet::letterArrange(string section, char lett)
{
    for(int i = 0; i < 26; i++)
    {
        if(alph.Letters[i] = lett)
        {
            alph.letterNum = i;
        }
    }
    
    alph.possible[alph.letterNum * 2] = ' ';
    alph.unlikely[alph.letterNum * 2] = ' ';
    alph.probable[alph.letterNum * 2] = ' ';

    if(section == "1")
    {
        alph.possible[alph.letterNum * 2] = alph.Letters[alph.letterNum];
    }
    else if(section == "2")
    {
        alph.unlikely[alph.letterNum * 2] = alph.Letters[alph.letterNum];
    }
    else if(section == "3")
    {
        alph.probable[alph.letterNum * 2] = alph.Letters[alph.letterNum];
    }
}

void alphabet::printAlphabet()
{
    cout << "Possible:" << alph.possible << endl << "Unlikely:" << alph.unlikely << endl << "Probable:" << alph.probable << endl;

}
