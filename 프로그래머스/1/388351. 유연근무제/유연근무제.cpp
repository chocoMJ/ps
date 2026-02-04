#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0; i < schedules.size(); i++){
        bool bSuccess = true;
        
        int limit;
        if(schedules[i] % 100 < 50) limit = schedules[i] + 10;
        else limit = schedules[i] + 50;
        
        for(int day = 0; day < 7; day++)
        {
            int currentDay = (startday + day) % 7;
            if(currentDay == 0) currentDay = 7;
            
            if(currentDay == 6 || currentDay == 7){
                continue;
            }
            
            if(timelogs[i][day] > limit){
                bSuccess = false;
                break;
            }
        }
        
        if(bSuccess) answer++;
    }
    
    return answer;
}