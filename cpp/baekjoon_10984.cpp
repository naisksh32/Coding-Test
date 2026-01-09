#include <iostream>
#include <cstdio>
using namespace std;

struct Answer{
    int sum_p;
    float avg_score;
};

Answer cal_score(){
    int n, p=0;
    cin >> n;
    float score=0.0;

    for(int i=0; i<n; i++){
        int k;
        float s;
        cin >> k >> s;

        p += k;
        score += k*s;
    }
    Answer answer;
    answer.sum_p = p;
    answer.avg_score = score/p;

    return answer;
}

int main(){

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        Answer answer = cal_score();

        printf("%d %0.1f\n", answer.sum_p, answer.avg_score);
    }

    return 0;
}