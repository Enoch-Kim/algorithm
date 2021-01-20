#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Kruskal{
    
    public:
        Kruskal(int n, vector<vector<int>> edges)
        : n(n), edges(edges), setPtrs(vector<int>(n, -1)), spanningTree(vector<vector<int>>(0)) {
            sort(this -> edges.begin(), this -> edges.end(), compareFunc);
        }

        static bool compareFunc(vector<int>& edge1, vector<int>& edge2){
            if(edge1[2] == edge2[2]){
                if(edge1[0] == edge2[0]){
                    return edge1[1] < edge2[1];
                } else {
                    return edge1[0] < edge2[0];
                }
            }
            return edge1[2] < edge2[2];
        }

        void GetMinimumSpanningTree(){
            int cnt = 0;

            int i=0;
            while(cnt < n-1){
                vector<int>& e = edges[i];
                if(unionFind(e[0], e[1])){
                    cnt++;
                    spanningTree.push_back(e);
                }
                i++;
            }
        }

        void PrintTree(){
            for(int i=0; i<=spanningTree.size(); i++){
                cout << spanningTree[i][0] << " - " << spanningTree[i][1] << " : " << spanningTree[i][2] << '\n';
            }
        }

    private:

        int findRoot(int a){
            while(setPtrs[a] != -1){
                a = setPtrs[a];
            }

            return a;
        }

        bool unionFind(int a, int b) {
            int rootA = findRoot(a);
            int rootB = findRoot(b);

            if(rootA != rootB){
                setPtrs[rootA] = rootB;
                return true;
            }
            return false;
        }

        int n;  // vertics count
        vector<vector<int>> edges;  // [node A, node B, weight]
        vector<int> setPtrs;
        vector<vector<int>> spanningTree;
};

int main() {
    int n = 7;
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
    Kruskal mst = Kruskal(n, edges);

    mst.GetMinimumSpanningTree();
    mst.PrintTree();
}