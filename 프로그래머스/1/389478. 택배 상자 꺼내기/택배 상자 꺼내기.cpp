#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    
    
    int answer = 0;
    
    if(w == 1)
    {
        return n - num + 1;
    }
    
    int floor = ((num - 1) / w) + 1;
    int max_floor = ((n - 1) / w) + 1;
    int dif_floor = max_floor - floor;
    int remaining = n % w;
    int seq = 0;
    
    if(n % w == 0) remaining = w;
    
    if(floor % 2 == 0)
    {
        seq = w - (num % w) + 1;
        if(seq == w + 1) seq = 1;
    }
    else
    {
        seq = num % w;
        if(seq == 0) seq = w;
    }
    
    if(max_floor % 2 == 0)
    {
        if(seq + remaining > w)
            answer = dif_floor + 1;
        else
            answer = dif_floor;
    }
    
    else
    {
        answer = dif_floor + 1;
        if(seq > remaining)
            answer--;
    }
    
    return answer;
}