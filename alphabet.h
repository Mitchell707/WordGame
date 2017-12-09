#ifndef _ALPHABET_H_
#define _ALPHABET_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class alphabet
{
    private:

    public:
        int letterNum;

        string possible;// = " A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
        string unlikely;// = "                                                    "; 
        string probable;// = "                                                    ";

        vector < char > Letters;

        void letterArrange(string, char, vector<char>, string&, string&, string&);
        void setArray(vector<char> &);
        void setStrings(string &, string &, string &);
};

#endif
