/*
https://programmers.co.kr/learn/courses/30/lessons/43162
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visitMap(computers.size(), false);
    
    for(int i=0; i<computers.size(); i++){
        if(visitMap[i]) continue;
        
        vector<int> st(0);
        st.push_back(i);
        
        while(st.size()){
            int temp = st.back();
            st.pop_back();

            visitMap[temp] = true;
            
            for(int idx=0; idx<computers[temp].size(); idx++){
                if(idx == temp || !computers[temp][idx]) continue;
                
                if(visitMap[idx]){
                    continue;
                } else {
                    st.push_back(idx);
                }
            }
        }
        answer++;
    }
    
    
    return answer;
}