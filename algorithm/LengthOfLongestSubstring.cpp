/*
    2020-03-10 LeetCode
    AddTwoNumbers
    https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution1 {        // first 56ms... 7%...
public:
    static const int CHAR_SIZE = 256;
    
    int lengthOfLongestSubstring(string s) {
        int size = s.size(),
            *keyPtr = new int[CHAR_SIZE]{},
            maxLength = 0, count = 0, accumulate = 0;
        for(int i=0; i < size; ++i){
            int current = keyPtr[s[i]];
            if(current){
                maxLength = max(maxLength, count);
                count = 0;
                delete[] keyPtr;
                keyPtr = new int[CHAR_SIZE]{};
                for(int j = current; j < i; ++j){
                    ++count;
                    keyPtr[s[j]] = j+1;
                }
            }
            ++count;
            keyPtr[s[i]] = i+1;
        }
        maxLength = max(maxLength, count);
        return maxLength;
    }
};

class Solution2 {    // second 8ms 94.66%
public:
    static const int CHAR_SIZE = 256;
    
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, size = s.length(), countStart = 0, sublength = 0;
        int *keyPtr = new int[CHAR_SIZE]{};
        for(int i = 0; i < size; ++i){
            int current = keyPtr[s[i]];
            if(current && current > countStart){
                maxLength = max(maxLength, sublength);
                sublength = i - current;    // current = index + 1
                countStart = current;
            }
            ++sublength;
            keyPtr[s[i]] = i + 1;
        }
        maxLength = max(maxLength, sublength);
        return maxLength;
    }
};

class Solution {           // 4ms ~ 8ms 99.19% / 100% memory -> it depends on server condition
public:
    
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, size = s.length(), countStart = 0;
        int *keyPtr = new int[128]{};
        for(int i = 0; i < size; ++i){
            int current = keyPtr[s[i]];
            if(current && current > countStart){
                maxLength = max(maxLength, i - countStart);
                countStart = current;
            }
            keyPtr[s[i]] = i + 1;
        }
        maxLength = max(maxLength, size - countStart);
        return maxLength;
    }
};
// 9:18

int main() {
    string s = "abcabcbb";
    Solution S;
    int maxNum = S.lengthOfLongestSubstring(s);
    cout << maxNum << endl;
    cout << int(' ');
}