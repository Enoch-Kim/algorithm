#include <iostream>
#include <vector>

using namespace std;

int main() {

    int answer = 0;
    int N, K;

    cin >> N >> K;

    vector<int> valueMap(K+1, 0);

    for(int i=0; i<N; i++){
        int W, V;
        cin >> W >> V;

        for(int w=K; w>0; w--){
            int temp = valueMap[w];
            if(temp && w + W <= K){
                valueMap[w+W] = max(valueMap[w+W], temp + V);
            }
        }

        valueMap[W] = max(valueMap[W], V);
    }

    for(int i=1; i<=K; i++){
        answer = max(answer, valueMap[i]);
    }

    cout << answer << '\n';

    return 0;
}