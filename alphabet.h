#ifndef _ALPHABET_H_
#define _ALPHABET_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class alphabet
{
    private:
        string possible;// = " A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
        string unlikely;// = "                                                    "; 
        string probable;// = "                                                    ";

        vector < char > Letters;

        int letterNum;

    public:
        void letterArrange(string, char);
        void setArray();
        void printAlphabet();
        void setStrings();
};

#endif
