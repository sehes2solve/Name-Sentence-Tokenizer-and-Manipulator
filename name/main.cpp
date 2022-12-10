#include <iostream>
#include "Name.h"

using namespace std;


int main()
{
    string input;
    int i,j;
    for( int k = 0; k < 5; k++ )
    {
        cout << "Enter Name : " ;
        getline(cin,input);
        Name name(input);
        name.print();
        cout << "Enter Replace Index : "; cin >> i >> j;
        cout << name.replace(i,j) << endl;
        name.print();
        cin.ignore();

        system( "Pause" ); system( "CLS" );

    }
    return 0;
}
