#include <string>
#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;

int solution(vector<int> food_times, ll k) {
    int answer = 0;
    int size = food_times.size();
    int zeroPlate = 0;
    ll n = k/size;
    cout << "k is " << k << " and ";
    cout << "n is " << n << " and ";
    cout << "emptyPlate is " << zeroPlate << '\n';
    cout << "arr : [";
    for(int i=0; i<size-1; ++i){
        cout << food_times[i] << ", ";
    }
    cout << food_times[size-1] << "]\n";
    while(n){
        int i=-1;
        while(++i<size){
            if(food_times[i] == 0) continue;
            if(food_times[i] <= n){
                k-=food_times[i];
                food_times[i] = 0;
                zeroPlate++;
            }else{
                food_times[i]-=n;
                k-=n;
            }
        }
        if(zeroPlate == size) return -1;
        n = k/(size-zeroPlate);
        cout << "k is " << k << " and ";
        cout << "n is " << n << " and ";
        cout << "emptyPlate is " << zeroPlate << '\n';
        cout << "arr : [";
        for(int i=0; i<size-1; ++i){
            cout << food_times[i] << ", ";
        }
        cout << food_times[size-1] << "]\n";
    }
    
    int count=-1;

    for(int i=0; i<size; ++i){
        if(food_times[i] == 0) continue;
        count++;
        if(count == k){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}

int main(){
    cout << solution({20, 90, 52, 80, 74, 112, 134},300) << '\n';
}