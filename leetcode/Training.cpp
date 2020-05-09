#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcul(int size, int target){
    if(size == 1) return 0;
    
    vector<int> v(size);
    for(int i=0; i< size; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    int i = 0, sum = 0, result = 0;
    for(int j=0; j < target - 1; ++j)
        sum += v[target - 1] - v[j];
    result = sum;
    while(i + target < size){
        sum += ((v[i+target] - v[i + target - 1]) * (target - 1));
        sum -= v[i + target - 1] - v[i];
        result = min(result, sum);
        ++i;
    }
    return result;
}

int main(){
    int testNum = 0,
        size = 0, target = 0,
        result = 0;
    cin >> testNum;
    for(int i=0; i<testNum; ++i){
        cin >> size >> target;
        result = calcul(size, target);
        cout << "Case #" << i+1 << ": " << result << '\n';
    }
}