/*
    2020-03-10 LeetCode
    AddTwoNumbers
    https://leetcode.com/problems/add-two-numbers/submissions/
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


struct ListNode {
    ListNode() : val(0), next(NULL){}
    ListNode(int x) : val(x), next(NULL) {}
    int val;
    ListNode *next;
};

class Solution1 {       // first solution
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0),
                *current = result;
        int overflow = 0;
        int sum = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0);
        current -> val = (sum) % 10 + overflow;
        overflow = (sum) / 10;
        l1 = l1 -> next ? l1 -> next : nullptr;
        l2 = l2 -> next ? l2 -> next : nullptr;
        
        while(l1 || l2 || overflow){
            current -> next = new ListNode(0);
            current = current -> next;
            sum = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + overflow;
            current -> val = (sum) % 10;
            overflow = (sum) / 10;
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }
        return result;
    }
};
// result depends on server condition ;;
class Solution2 {       // Runtime: 24 ms, faster than 90.39% Memory Usage: 10.1 MB, less than 92.57%
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int count1 = 0, count2 = 0;
        ListNode *shadow1 = l1, *shadow2 = l2;
        while(shadow1){
            ++count1;
            shadow1 = shadow1 -> next;
        }
        while(shadow2){
            ++count2;
            shadow2 = shadow2 -> next;
        }
        if(count1 >= count2){
            ListNode* result = l1;
            while(l1){
                if(l2){
                    int sum = l1 -> val + l2 -> val;
                    if(sum / 10 && l1 -> next){
                        l1 -> val = sum - 10;
                        l1 -> next -> val += 1;
                    }
                    else if(sum / 10){
                        l1 -> val = sum - 10;
                        l1 -> next = new ListNode(1);
                    }
                    else
                        l1 -> val = sum;
                    l2 = l2 -> next;
                    l1 = l1 -> next;
                    }
                else{
                    if(l1 -> val / 10 && l1 -> next){
                        l1 -> val -= 10;
                        l1 -> next -> val += 1;
                    }
                    else if(l1 -> val / 10){
                        l1 -> val -= 10;
                        l1 -> next = new ListNode(1);
                    }
                    l1 = l1 -> next;
                }
                
            }
            
            return result;
        }
        else{
            ListNode* result = l2;
            while(l2){
                if(l1){
                    int sum = l1 -> val + l2 -> val;
                    if(sum / 10 && l2 -> next){
                        l2 -> val = sum - 10;
                        l2 -> next -> val += 1;
                    }
                    else if(sum / 10){
                        l2 -> val = sum - 10;
                        l2 -> next = new ListNode(1);
                    }
                    else
                        l2 -> val = sum;
                    l2 = l2 -> next;
                    l1 = l1 -> next;
                    }
                else{
                    if(l2 -> val / 10 && l2 -> next){
                        l2 -> val -= 10;
                        l2 -> next -> val += 1;
                    }
                    else if(l2 -> val / 10){
                        l2 -> val -= 10;
                        l2 -> next = new ListNode(1);
                    }
                    l2 = l2 -> next;
                }                
            }
            return result;
        }
    }
};


int main() {

    Solution S;
    return 0;
}