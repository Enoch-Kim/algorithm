/*
https://programmers.co.kr/learn/courses/30/lessons/42627
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compStart(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

struct compareJob {
    bool operator() (vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int doneCnt = 0;
    int time = 0;
    
    priority_queue<vector<int>, vector<vector<int>>, compareJob> jobHeap;
    
    // sort by start time
    sort(jobs.begin(), jobs.end(), compStart);
    
    // start at first time
    time = jobs[0][0];
    int idx = 0;
    int size = jobs.size();
    
    while(doneCnt != size){
        while(idx != size  && jobs[idx][0] <= time){
            jobHeap.push(jobs[idx]);
            idx++;
        }
        
        // if no job at time, shift to next job's start time
        if(jobHeap.empty()){
            time = jobs[idx][0];
            continue;
        }
        
        vector<int> temp = jobHeap.top();
        jobHeap.pop();
        
        time += temp[1];
        answer += time - temp[0];
        
        doneCnt++;
    }
    
    
    return answer/size;
}