#ifndef NAME
#define NAME
#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Name
{
    public:
        Name(string);
        ~Name();
        void print();
        bool replace(int,int);

    private:
        string name;
        short names_no;
        string* names;
        void divide();
        string trim(string);
};


#endif // NAME
