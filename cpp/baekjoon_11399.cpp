#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal_min(vector<int> arr)
{
    int answer = 0;

    int arr_len = arr.size();
    sort(arr.begin(), arr.end());

    for(int i=0; i<=arr_len; i++)
    {
        for(int j=0; j<i; j++)
        {
            answer += arr[j];
        }
    }

    return answer;
}

int main() 
{
    int N;
    cin >> N;
    vector<int> stop_min(N);

    for (int i=0; i<N; i++)
    {
        cin >> stop_min[i];
    }

    cout << cal_min(stop_min) << endl;

    return 0;
}