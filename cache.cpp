#include <string>
#include <vector>
#include <deque>

using namespace std;


char toLower(char a){
    if('a'<= a && a <= 'z')
    {
        return a;
    }
    else
    {
        return a + ('a'-'A');
    }
}

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return cities.size() * 5;
    int answer = 0;
    deque<string> cache;
    
    for(int i=0; i<cities.size(); i++)
    {
        string temp = cities[i];
        bool cacheHit = false;
        for(int j=0; j<temp.size(); j++){
            temp[j] = toLower(temp[j]);
        }
        for(int j=0; j<cache.size(); j++){
            if(temp == cache[j]){
                cacheHit = true;
                vector<string> st;
                cache.push_back(temp);
                for(int k=0; k<j; k++){
                    st.push_back(cache.front());
                    cache.pop_front();
                }
                cache.pop_front();
                for(int k=0; k<j; k++){
                    cache.push_front(st.back());
                    st.pop_back();
                }
                break;
            }
        }
        if(cacheHit){
            answer++;
        }else{
            if(cache.size() == cacheSize)
                cache.pop_front();
            cache.push_back(temp);
            answer+=5;
        }
        
    }
    return answer;
}