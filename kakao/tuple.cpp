#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, vector<int> v){
    os << '[';
    for(int i=0; i<v.size()-1; ++i)
        os << v[i] << ", ";
    os << v.back() << ']' << '\n';
    return os;
}


vector<int> solution(string s) {
    vector<int> ans;
    unordered_map<int,vector<int>*> tMap;
    int curSize=0, maxSize=0, curNum=0;
    vector<int>* vPtr;
    for(int i=1; i<s.length()-1; ++i){
        switch(s[i]){
            case '{' :
                vPtr = new vector<int>;
                curSize=0;
                break;
            case ',' :
                if(s[i+1] == '{') break;
                vPtr -> push_back(curNum);
                curNum = 0;
                curSize++;
                break;
            case '}' :
                curSize++;
                maxSize = max(maxSize, curSize);
                vPtr -> push_back(curNum);
                curNum = 0;
                tMap[curSize] = vPtr;
                break;
            default :
                curNum*=10;
                curNum+=s[i]-'0';
                break;
        }
    }
    unordered_map<int,bool> nMap;
    for(int i=1; i<=maxSize; ++i){
        for(int j=0; j<i; j++){
            int cur = tMap[i]->at(j);
            if(!nMap[cur]){
                ans.push_back(cur);
                nMap[cur] = true;
                delete tMap[i];
                break;
            }
        }
    }
    return ans;
}

int main() {
    cout << solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}

// 2: 22