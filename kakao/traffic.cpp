#include <string>
#include <vector>
#include <iostream>
using namespace std;
double getTime(string time){
    double res=0.;
    res += (double(time[0]-'0')-0.001)*36000.;
    res += (double(time[1]-'0')-0.001)*3600.;
    res += (double(time[3]-'0')-0.001)*600.;
    res += (double(time[4]-'0')-0.001)*60.;
    res += (double(time[6]-'0')-0.001)*10.;
    res += (double(time[7]-'0')-0.001);
    res += (double(time[9]-'0')-0.001)*0.1;
    res += (double(time[10]-'0')-0.001)*0.01;
    res += (double(time[11]-'0')-0.001)*0.001;
    return res;
}
bool compareLeft(double time, double left, double right){
    return ((time >= left && time <= right) || (time+1. >= left && time+0.999 <= right)) || ((time+0.999 >= left && time <= left) || (time+1. >= right && time <= right));
}



int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<double,double>> times;
    for(int i=0; i<lines.size(); ++i){
        string temp = lines[i].substr(11, lines[i].size()-11);
        double time = getTime(temp);
        temp = temp.substr(13, temp.size()-14);
        double distance = 0;
        cout << temp << '\n';
        int dotIdx = temp.find_first_of('.');
        if(dotIdx == string::npos){
            for(int j=0; j<temp.size(); j++){
                distance *= 10.;
                distance += double(temp[j] - '0');
            }
            distance -= 0.001;
        }else{
            for(int j=0; j<dotIdx; j++){
                distance *= 10.;
                distance += double(temp[j] - '0');
            }
            double lower = 1.;
            for(int j=dotIdx+1; j<temp.size(); j++){
                lower *= 0.1;
                distance += double(temp[j] - '0')*lower;
            }
            distance -= 0.001;
        }
        cout << time << "  " << distance << "  " << time - distance << '\n';
        times.push_back(make_pair(time-distance, time));
    }
    for(int i=0; i<times.size(); i++){
        int count1 = 0;
        int count2 = 0;
        cout << times[i].first << " " << times[i].second << "\n";
        for(int j=0; j<times.size(); j++){
            if(compareLeft(times[i].first, times[j].first, times[j].second)){
                count1++;
            }
            if(compareLeft(times[i].second, times[j].first, times[j].second)){
                count2++;
            }
        }
        
        count1 = max(count1, count2);
        
        answer = max(answer, count1);
    }
    return answer;
}