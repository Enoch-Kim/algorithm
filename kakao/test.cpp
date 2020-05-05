#include <iostream>
#include<string>
#include <unordered_map>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 1;
    unordered_map<int,int> sMap;
    while(s.length()>1){
        int i=0;
        int j=1;
        int barrier=0;
        bool count = false;
        stack<pair<int,int>> st;
        while(j<s.length()){
            if(s[i] == s[j]){
                count=true;
                i--;
                j++;
                while(i>=barrier && j<s.length() && s[i] == s[j]){
                    i--;
                    j++;
                }
                st.push(make_pair(i,j));
                barrier = j-1;
                i=j+1;
                j=i+1;
                continue;
            }
            i++;
            j++;
        }
        if(count == 0) break;
        while(!st.empty()){
            pair<int,int> idx = st.top();
            st.pop();
            s.erase(i+1, j-i+1);
        }
    }
    if(s.length() == 0) answer=1;

    return answer;
}
int main(){}