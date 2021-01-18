/*
https://programmers.co.kr/learn/courses/30/lessons/42840
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    int one=0, two=0, three=0;
    
    vector<vector<int>> repeats{
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    for(int i=0; i<answers.size(); i++){
        int temp = answers[i];
        if(repeats[0][i%5] == temp){
            one++;
        }
        if(repeats[1][i%8] == temp){
            two++;
        }
        if(repeats[2][i%10] == temp){
            three++;
        }
    }
    
    if(one == two){
        if(one == three){
            return {1, 2, 3};
        } else if(one > three){
            return {1, 2};
        } else {
            return {3};
        }
    } else if(one > two){
        if(one == three){
            return {1, 3};
        } else if(one > three){
            return {1};
        } else {
            return {3};
        }
    } else {
        if(two == three){
            return {2, 3};
        } else if(two > three){
            return {2};
        } else {
            return {3};
        }
    }
    
    return {};
}