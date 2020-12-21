/*
https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

2147483647  1 * 31 -> 0
1           1  -> 0
16          1 0*4 -> 0
17          1 0*3 1  -> 3
32          1 0*5 -> 0
64
*/

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0;
    int times = 0;
    
    while(31 > times){
        if((N & (1 << times)) == 0){
            times++;
            continue;
        }
        int temp = times++;
        
        while(31 >= times && (N & (1 << times)) == 0){
            if(times == 31) return ans;
            times++;
        }
        ans = max(ans, times - temp - 1);
    }
    return ans;
}