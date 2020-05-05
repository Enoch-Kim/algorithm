#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<double,int> a, pair<double,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first > b.first;
    }
}

vector<int> solution(int N, vector<int> stages) {
    unordered_map<int, int> totalMap; 
    unordered_map<int, int> failMap;
    vector<pair<double,int>> rateArr;
    vector<int> answer;
    for(int i=0; i<stages.size(); i++){
        int temp = stages[i];
        if(temp <= N){
            failMap[temp]++;
            totalMap[temp]++;
        }

        for(int i=temp-1; i>0; --i){
            totalMap[i]++;
        }
    }
    for(int i=N; i>0; --i){
        totalMap[i];
    }
    for(auto i:totalMap){
        if(i.second && failMap[i.first])
            rateArr.push_back(make_pair(double(failMap[i.first])/double(i.second), i.first));
        else
            rateArr.push_back(make_pair(0.0,i.first));
    }
    sort(rateArr.begin(), rateArr.end(), compare);
    for(auto i : rateArr){
        answer.push_back(i.second);
    }
    return answer;
}

int main(){

    vector<int> s = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
    for (auto i : s)
        cout << i << " ";
    cout <<'\n';
}