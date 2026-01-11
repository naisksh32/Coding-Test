#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> num_list(N);

    for(int n=0; n<N; n++){
        int num;
        cin >> num;
        num_list[n] = num;
    }

    int answer=0;
    for(int i=0; i<num_list.size(); i++){
        int target_num = num_list[i], answer_cnt=0;

        for(int n=1; n<=target_num; n++){
            if(target_num%n == 0){
                answer_cnt++;
            }
        }

        if(answer_cnt == 2){
            answer++;
        }
    }

    cout << answer;

    return 0;
}