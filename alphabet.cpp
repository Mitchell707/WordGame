#include <iostream>
#include <vector>
#include "alphabet.h"

using namespace std;

alphabet alph;

void alphabet::setStrings(string & pos, string & un, string & prob)
{
    pos = " A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    un = "                                                    ";
    prob = "                                                    ";
}

void alphabet::setArray(vector<char> & arr)
{
    arr.resize(26);

    arr[0] = 'A';
    arr[1] = 'B';
    arr[2] = 'C';
    arr[3] = 'D';
    arr[4] = 'E';
    arr[5] = 'F';
    arr[6] = 'G';
    arr[7] = 'H';  
    arr[8] = 'I';
    arr[9] = 'J';
    arr[10] = 'K';
    arr[11] = 'L';
    arr[12] = 'M';
    arr[13] = 'N';
    arr[14] = 'O';
    arr[15] = 'P';
    arr[16] = 'Q';
    arr[17] = 'R';
    arr[18] = 'S';
    arr[19] = 'T';
    arr[20] = 'U';
    arr[21] = 'V';
    arr[22] = 'W';
    arr[23] = 'X';
    arr[24] = 'Y';
    arr[25] = 'Z';

}

void alphabet::letterArrange(string section, char lett, vector<char> arr, string & pos, string & un, string & prob)
{
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] == lett)
        {
            alph.letterNum = i;

        }
    }
   
    pos[(alph.letterNum * 2) + 1] = ' ';
    un[(alph.letterNum * 2) + 1] = ' ';
    prob[(alph.letterNum * 2) + 1] = ' ';

 
    if(section == "1")
    {
        pos[(alph.letterNum * 2) + 1] = arr[alph.letterNum];
    }
    else if(section == "2")
    {
        un[(alph.letterNum * 2) + 1] = arr[alph.letterNum];
    }
    else if(section == "3")
    {
        prob[(alph.letterNum * 2) + 1] = arr[alph.letterNum];
    }
}
