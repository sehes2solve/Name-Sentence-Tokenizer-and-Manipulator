#include "Name.h"

Name::Name(string n):names_no(1)
{
    n = trim(n);
    short last_space_index = 0;
    if(n.size() == 0)
    {
        name = "Invalid Input Or Empty Field";
        divide();
    }
    else
    {
        for(short i = 0;i < 2;i++)
        {
            last_space_index = n.find(" ",last_space_index + 1);
            if(last_space_index == -1)
            {
                if(i == 0)
                {
                    name = n + ' ' + n + ' ' + n;
                    divide();
                    return;
                }
                else
                {
                    short sec_name_index = n.find(" ",0);
                    name = n + ' ' + n.substr(sec_name_index + 1,n.length()-sec_name_index);
                    divide();
                    return;
                }
            }
        }
        name = n;
        divide();
    }
}
string Name::trim(string word)
{
    string res;
    bool Is_space = false;
    for(unsigned int i = 0;i < word.size();i++)
    {
        if(word[i] == ' ')
        {
            if(!(i == 0 || i == word.size()-1 || Is_space))
                res+= word[i];
            Is_space = true;
        }
        else if((word[i] >= 'A' && word[i] <= 'Z' ) || (word[i] >= 'a' && word[i] <= 'z'))
        {
            res += word[i];
            Is_space = false;
        }
    }
    return res;
}
void Name::divide()
{
    for(unsigned int i = 0;i < name.size();i++)
    {
        if(name[i] == ' ')
            names_no++;
    }
    names = new string[names_no];
    stringstream ss(name);
    string temp;
    for(short i = 0 ;ss >> temp;i++)
        names[i] = temp;
}
void Name::print()
{
    for(short i = 0 ;i < names_no;i++)
        cout << i+1 << ") " << names[i] << '\n';
}
bool Name::replace(int i,int j)
{
    if(i < 1 || j < 1 || i > names_no + 1 || j > names_no +1)
        return false;
    else
    {
        swap(names[i-1],names[j-1]);
        name = names[0];
        for(short i = 1;i < names_no;i++)
            name += ' ' + names[i];
        return true;
    }
}
Name::~Name()
{
    //dtor
}
