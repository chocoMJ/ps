#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> signals) {
    int answer = 0;
    vector<int> sums;
    int sum = 1;
    
    for(int i = 0; i < signals.size(); i++) {
        int a = signals[i][0] + signals[i][1] + signals[i][2];
        sums.push_back(a);
        
        sum *= a;
    }
    
    for(int i = 2; i < sum; i++) {
        int flag = true;
        
        for(int row = 0; row < signals.size(); row++) {
            int seq = i % sums[row];
            int start = signals[row][0] + 1;
            int end = signals[row][0] + signals[row][1];
            
            if(seq < start || seq > end) {
                flag = false;
                break;
            }
        }
        
        if(flag) {
            answer = i;
            break;
        }
    }
    
    if(answer == 0) answer = -1;
    
    return answer;
}