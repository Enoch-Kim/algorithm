/*
    2020-03-13 LeetCode
    Median Of Two Sorted Arrays
    https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution1 {   //Runtime: 20 ms, faster than 69.95% ,Memory Usage: 8.9 MB, less than 100.00%
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), sum = m + n,
            p1 = (m + 1) / 2 - 1, p2 = (n + 1) / 2 - 1, dis = m < n ? (p1 + 1) / 2 : (p2 + 1) / 2;
        if(dis == 0) dis = 1;
        
        if(m == 0) 
            return n % 2 ? nums2[p2] : (nums2[p2] + nums2[p2 + 1]) / 2.;
        
        if(n == 0)    
            return m % 2 ? nums1[p1] : (nums1[p1] + nums1[p1 + 1]) / 2.;
        
        if(m == 1 && n == 1)
            return (nums1[0] + nums2[0]) / 2.;
        
        if(m == 1){
            if(sum % 2){
                if(nums1[p1] == nums2[p2])
                    return nums2[p2];
                if(nums1[p1] > nums2[p2])
                    return min(nums2[p2 + 1], nums1[p1]);
                else
                    return nums2[p2];
            }
            else {  // m, n both odd
                if(nums1[p1] == nums2[p2])
                    return nums1[p1];
                if(nums1[p1] > nums2[p2])
                    return (nums2[p2] + min(nums2[p2 + 1], nums1[p1])) / 2.;
                else
                    return (nums2[p2] + max(nums2[p2 - 1], nums1[p1])) / 2.;
            }
            
        }
        
        if(n == 1){
            if(sum % 2){
                if(nums2[p2] == nums1[p1])
                    return nums1[p1];
                if(nums2[p2] > nums1[p1])
                    return min(nums1[p1 + 1], nums2[p2]);
                else
                    return nums1[p1];
            }
            else {  // m, n both odd
                if(nums2[p2] == nums1[p1])
                    return nums2[p2];
                if(nums2[p2] > nums1[p1])
                    return (nums1[p1] + min(nums1[p1 + 1], nums2[p2])) / 2.;
                else
                    return (nums1[p1] + max(nums1[p1 - 1], nums2[p2])) / 2.;
            }
            
        }
        
        if(nums1[m-1] < nums2[0]) {
            int mid = (sum + 1) / 2;
            if(mid == m)
                return sum % 2 ? nums1[m - 1] : (nums1[m - 1] + nums2[0]) / 2.;
            if(mid > m)
                return sum % 2 ? nums2[mid - m - 1] : (nums2[mid - m - 1] + nums2[mid - m]) / 2.;
            else
                return sum % 2 ? nums1[mid - 1] : (nums1[mid - 1] + nums1[mid]) / 2.;
        }
        
        if(nums2[n-1] < nums1[0]) {
            int mid = (sum + 1) / 2;
            if(mid == n)
                return sum % 2 ? nums2[n - 1] : (nums2[n - 1] + nums1[0]) / 2.;
            if(mid > n)
                return sum % 2 ? nums1[mid - n - 1] : (nums1[mid - n - 1] + nums1[mid - n]) / 2.;
            else
                return sum % 2 ? nums2[mid - 1] : (nums2[mid - 1] + nums2[mid]) / 2.;
        }
        
        
        if(sum % 2) {
            while(dis){
                if(nums1[p1] == nums2[p2])
                    return nums1[p1];
                else if(nums1[p1] > nums2[p2]){
                    if(p2 == n - 1 || nums2[p2 + 1] >= nums1[p1])
                        return nums1[p1];
                    if(p1 == 0)
                        return nums2[(sum + 1) / 2 - 1];
                    p1 -= dis;
                    p2 += dis;
                }
                else{
                    if(p1 == m - 1 || nums1[p1 + 1] >= nums2[p2])
                        return nums2[p2];
                    if(p2 == 0)
                        return nums1[(sum + 1) / 2 - 1];
                    p1 += dis;
                    p2 -= dis;
                }                
                dis = (dis + 1) / 2;
            }        
            return 0;
        }
        else {
            while(dis){
                if(nums1[p1] == nums2[p2])
                    return m % 2 ? nums1[p1]
                                 : (nums1[p1] + min(nums1[p1 + 1], nums2[p2 + 1])) / 2.;
                else if(nums1[p1] > nums2[p2]){
                    if(p2 == n - 1)
                        return m % 2 ? (nums1[p1] + max(nums1[p1 - 1], nums2[p2])) / 2.
                                     : (nums1[p1] + nums1[p1 + 1]) / 2.;
                    if(nums2[p2 + 1] >= nums1[p1]){
                        if(p1 == m - 1)
                            return m % 2 ? (nums1[p1] + max(nums1[p1 - 1], nums2[p2])) / 2.
                                     : (nums1[p1] + nums2[p2 + 1]) / 2.;   
                        else if(p1 == 0)
                            return m % 2 ? (nums1[p1] + nums2[p2]) / 2.
                                     : (nums1[p1] + min(nums1[p1 + 1], nums2[p2 + 1])) / 2.;    
                        else
                            return m % 2 ? (nums1[p1] + max(nums1[p1 - 1], nums2[p2])) / 2.
                                     : (nums1[p1] + min(nums1[p1 + 1], nums2[p2 + 1])) / 2.;    
                    }
                    if(p1 == 0){
                        return (min(nums1[p1], nums2[(sum + 1) / 2]) + nums2[(sum + 1) / 2 - 1]) / 2.;
                    }
                          
                    p1 -= dis;
                    p2 += dis;
                }
                else{
                    if(p1 == m - 1)
                        return m % 2 ? (nums2[p2] + max(nums2[p2 - 1], nums1[p1])) / 2.
                                     : (nums2[p2] + nums2[p2 + 1]) / 2.;
                    if(nums1[p1 + 1] >= nums2[p2]){
                        if(p2 == n - 1)
                            return m % 2 ? (nums2[p2] + max(nums2[p2 - 1], nums1[p1])) / 2.
                                     : (nums2[p2] + nums1[p1 + 1]) / 2.;
                        else if(p2 == 0)
                            return m % 2 ? (nums2[p2] + nums1[p1]) / 2.
                                     : (nums2[p2] + min(nums2[p2 + 1], nums1[p1 + 1])) / 2.;
                        else
                            return m % 2 ? (nums2[p2] + max(nums2[p2 - 1], nums1[p1])) / 2.
                                     : (nums2[p2] + min(nums2[p2 + 1], nums1[p1 + 1])) / 2.;
                    }    
                    if(p2 == 0){
                        return (min(nums2[p2], nums1[(sum + 1) / 2]) + nums1[(sum + 1) / 2 - 1]) / 2.;
                                     
                                     
                    }
                    p1 += dis;
                    p2 -= dis;
                }                
                dis = (dis + 1) / 2;
            }   
            return 0;
        }
    }
};
// 7:50
    // 이걸 이해해보자
class Solution { //Runtime: 12 ms, faster than 98.23%  Memory Usage: 8.8 MB, less than 100.00%
private:
    double findMedian(int total, pair<int, int> x, pair<int, int> y) {
        int maximum = max(x.first, y.first), minimum = min(x.second, y.second);
        return !(total & 1) ? (maximum + minimum) / 2.0 : maximum;
    }
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);
        int p = a.size(), q = b.size(), total = p + q, l = 0, r = p;
        while (l <= r) {
            int pX = l + ((r - l) >> 1), pY = ((total + 1) >> 1) - pX;
            pair<int, int> x = {!pX ? INT_MIN : a[pX-1], pX == p ? INT_MAX : a[pX]};
            pair<int, int> y = {!pY ? INT_MIN : b[pY-1], pY == q ? INT_MAX : b[pY]};
            if (x.first <= y.second and y.first <= x.second) return findMedian(total, x, y);
            (x.first > y.second) ? r = pX - 1 : l = pX + 1;
        }
        return INT_MAX;
    }
};

int main() {
    vector v1{4, 5},
           v2{1, 2, 3, 6};
    Solution S;
    double d = S.findMedianSortedArrays(v1,v2);
    cout << "d is " << d << endl;
    int i = 29, j = 0;
    int k = ((i - j) >> 1);
    cout << "i is " << k << endl;
}