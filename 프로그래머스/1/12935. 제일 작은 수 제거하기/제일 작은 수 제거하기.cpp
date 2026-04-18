#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int point = 0;
    int min = arr[0];
    
    if(arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }
    
    else {
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] < min) {
                min = arr[i];
                point = i;
            }
        }
        
        arr.erase(arr.begin() + point, arr.begin() + point + 1);
    }
    
    answer = arr;
    
    return answer;
}