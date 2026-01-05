#include <iostream>
using namespace std;


int main() 
{
    int T;
    cin >> T;

    for(int i=T; i>0; i--)
    {
        for(int j=i; j>0; j--)
        {
            cout << "*";
        }
        
        cout << endl;
    }

    return 0;
}