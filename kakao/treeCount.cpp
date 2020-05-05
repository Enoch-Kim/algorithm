#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare1(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    int size = nodeinfo.size();
    vector<vector<int>> tree(size,vector<int>(3));
    for(int i=0; i<size;++i){
        tree[i][0] = nodeinfo[i][0];
        tree[i][1] = nodeinfo[i][1];
        tree[i][2] = i+1;
    }
    sort(tree.begin(), tree.end(), compare1);
    int backward = 0;
    stack<vector<int>> st;
    while(backward<size){
        if(backward == size-1){
            while(!st.empty()){
                if(st.top()[1]>tree[size-1][1]) break;
                answer[1].push_back(st.top()[2]);
                st.pop();
            }
            answer[1].push_back(tree[size-1][2]);
            while(!st.empty()){
                answer[1].push_back(st.top()[2]);
                st.pop();
            }
            backward++;
        }else{
            if(tree[backward][1] > tree[backward+1][1]){
                st.push(tree[backward]);
            }else{
                answer[1].push_back(tree[backward][2]);
                while(!st.empty()){
                    if(st.top()[1]>tree[backward+1][1]) break;
                    answer[1].push_back(st.top()[2]);
                    st.pop();
                }
            }
            backward++;
        }
        
    }
    deque<int> dq;
    int forward = size-1;
    while(forward >= 0){
        if(forward == 0){
            while(!st.empty()){
                if(st.top()[1]>tree[0][1]) break;
                dq.push_front(st.top()[2]);
                st.pop();
            }
            dq.push_front(tree[0][2]);
            while(!st.empty()){
                dq.push_front(st.top()[2]);
                st.pop();
            }
            forward--;
        }else{
            if(tree[forward][1] > tree[forward-1][1]){
                st.push(tree[forward]);
            }else{
                dq.push_front(tree[forward][2]);
                while(!st.empty()){
                    if(st.top()[1]>tree[forward-1][1]) break;
                    dq.push_front(st.top()[2]);
                    st.pop();
                }
            }
            forward--;
        }
    }
    for(int i=0; i<size; i++){
        answer[0].push_back(dq[i]);
    }

    return answer;
}

int main() {
    vector<vector<int>> v{{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};
    vector<vector<int>> ans = solution(v);
    for(int i=0; i<ans[0].size(); i++){
        cout << ans[0][i] << "   ";
    }
    cout << '\n';
    for(int i=0; i<ans[1].size(); i++){
        cout << ans[1][i] << "   ";
    }
    cout << '\n';
}