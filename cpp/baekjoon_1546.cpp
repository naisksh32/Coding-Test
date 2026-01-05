#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int T;
    cin >> T;

    vector<float> grade(T);
    for(int i=0; i<T; i++)
    {
        cin >> grade[i];
    }

    float max_score = 0;
    for(float a: grade)
    {
        if (max_score < a)
        {
            max_score = a;
        }
    }

    float sum_score = 0;
    for(int i=0; i<T; i++)
    {
        sum_score += (grade[i]/max_score)*100;
    }

    cout << sum_score/T << endl;

    return 0;
}