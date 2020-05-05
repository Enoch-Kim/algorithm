#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcul(int size, int budget){
    vector<int> v(size);
    int count = 0;
    for(int i=0; i< size; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    int i = 0;
    for(int i=0; i<size; ++i){
        budget -= v[i];
        if(budget < 0) break;
        ++count;
    }
    
    return count;
}

int main(){
    int testNum = 0,
        size = 0, budget = 0,
        result = 0;
    cin >> testNum;
    for(int i=0; i<testNum; ++i){
        cin >> size >> budget;
        result = calcul(size, budget);
        cout << "Case #" << i+1 << ": " << result << '\n';
    }
}