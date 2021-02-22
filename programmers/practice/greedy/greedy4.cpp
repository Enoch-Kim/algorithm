/*
https://programmers.co.kr/learn/courses/30/lessons/42885
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.rbegin(), people.rend());
    
    int left = 0;
    int right = people.size()-1;
    
    while(left <= right){
        int tempWgt = people[left];
        while(right != left && tempWgt+people[right] <= limit){
            tempWgt += people[right];
            right--;
        }
        left++;
    }
    answer = left;
    
    return answer;
}