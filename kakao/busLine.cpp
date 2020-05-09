#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    sort(timetable.begin(), timetable.end());
    string answer = "";
    vector<vector<int>> nthTime(n, vector<int>(0));

    int first = 9 * 60;
    

    for(int i=0; i<timetable.size(); ++i)
    {
        int temp = (timetable[i][0]-'0')*600 + (timetable[i][1]-'0')*60 + (timetable[i][3]-'0')*10 + (timetable[i][4]-'0');
        int time = n;
        for(int j=0; j<n; j++){
            if(temp <= first + j*t){
                time = j;
                break;
            }
        }
        while(time < n && nthTime[time].size() >= m) time++;
        if(time >= n) continue;
        nthTime[time].push_back(temp);
    }
    int curTime = 0;
    if(nthTime[n-1].size() < m){
        curTime = first + (n-1) * t;
    }else{
        curTime = nthTime[n-1].back() - 1;
    }
    answer += curTime/600 + '0';
    curTime -= (curTime/600)*600;
    answer += curTime/60 + '0';
    curTime -= (curTime/60)*60;
    answer += ':';
    answer += curTime/10 + '0';
    curTime -= (curTime/10)*10;
    answer += curTime + '0';
    
    return answer;
}