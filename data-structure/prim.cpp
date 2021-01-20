#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct comp{
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[2] == b[2]){
            if(a[0] == b[0]){
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        } else {
            return a[2] > b[2];
        }
    }
};

void prim(vector<vector<int>>& spanningTree, vector<vector<int>> edges, int n){
    int start = 0;

    unordered_map<int, vector<vector<int>>> graph;
    vector<bool> selected(n, false);

    for(int i=0; i<edges.size(); i++){
        
        graph[edges[i][0]].push_back(edges[i]);
        graph[edges[i][1]].push_back(edges[i]);
    }

    priority_queue<vector<int>, vector<vector<int>>, comp> pqueue;

    int cnt = 0;

    selected[0] = true;
    for(auto e : graph[start]){
        pqueue.push(e);
    }
    cnt++;


    while(cnt < n && !pqueue.empty()){

        vector<int> min_edge = pqueue.top();
        cout << min_edge[0] << '\t' << min_edge[1] << '\t' << min_edge[2] << '\n';
        pqueue.pop();
        if(!selected[min_edge[0]]){
            
            swap(min_edge[0], min_edge[1]);
            
            spanningTree.push_back(min_edge);
            for(auto e : graph[min_edge[1]]){
                pqueue.push(e);
            }
            selected[min_edge[1]] = true;
            cnt++;
        } else if(!selected[min_edge[1]]){

            spanningTree.push_back(min_edge);
            for(auto e : graph[min_edge[1]]){
                pqueue.push(e);
            }
            selected[min_edge[1]] = true;
            cnt++;
        }
    }

}

int main() {
    int n = 7;
    vector<vector<int>> spanningTree;
    vector<vector<int>> edges{
        {0, 1, 29},
        {1, 2, 16},
        {2, 3, 12},
        {3, 4, 22},
        {4, 5, 27},
        {5, 0, 10},
        {6, 1, 15},
        {6, 3, 18},
        {6, 4, 25}
    };

    prim(spanningTree, edges, n);

    for(int i=0; i<=spanningTree.size(); i++){
        cout << spanningTree[i][0] << " - " << spanningTree[i][1] << " : " << spanningTree[i][2] << '\n';
    }
}

/*
0 - 1 : 29
1 - 2 : 16
1 - 6 : 15
6 - 4 : 25
4 - 5 : 27
4 - 3 : 22
*/