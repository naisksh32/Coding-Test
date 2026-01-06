#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ten_search(vector<vector<int>>& m, int power)
{
    int n = m[0].size();
    int max_cnt = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int cnt = 0;
            cnt += m[i][j];

            for (int k=1; k<power; k++)
            {
                if (i-k >= 0)
                {
                    cnt += m[i-k][j];
                }
                if (i+k < n)
                {
                    cnt += m[i+k][j];
                }
                if (j-k >= 0)
                {
                    cnt += m[i][j-k];
                }
                if (j+k < n)
                {
                    cnt += m[i][j+k];
                }
            }

            if (max_cnt < cnt)
            {
                max_cnt = cnt;
            }

        }
    }

    return max_cnt;
}

int cross_search(vector<vector<int>>& m, int power)
{
    int n = m[0].size();
    int max_cnt = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int cnt = 0;
            cnt += m[i][j];

            for (int k=1; k<power; k++)
            {
                if (i-k>=0 && j-k>=0)
                {
                    cnt += m[i-k][j-k];
                }
                if (i-k>=0 && j+k<n)
                {
                    cnt += m[i-k][j+k];
                }
                if (i+k<n && j-k>=0)
                {
                    cnt += m[i+k][j-k];
                }
                if (i+k<n && j+k<n)
                {
                    cnt += m[i+k][j+k];
                }
            }

            if (max_cnt < cnt)
            {
                max_cnt = cnt;
            }

        }
    }

    return max_cnt;
}

int main() 
{
    int T;
    cin >> T;

    for(int test=0; test<T; test++)
    {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(N));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int ten = ten_search(matrix, M);
        int cross = cross_search(matrix, M);

        cout << "#" << (test+1) << " " << max(ten, cross) << endl;
    }

    return 0;
}