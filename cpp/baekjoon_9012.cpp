#include <iostream>
#include <stack>
#include <string>
using namespace std;

void func(string q)
{
    stack<char> s;

    for (char c: q)
    {
        if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            if (s.empty())
            {
                cout << "NO" << "\n";
                return;
            }

            s.pop();
        }
    }

    if (s.empty())
    {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() 
{
    int T;
    cin >> T;

    for(int i=0; i<T; i++)
    {
        string q;
        cin >> q;
        func(q);
    }

    return 0;
}