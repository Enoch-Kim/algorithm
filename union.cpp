#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
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

bool isEn(char a){
    if('a' <= a && a <= 'z') return true;
    if('A' <= a && a <= 'Z') return true;
    return false;
}

int solution(string str1, string str2) {
    int answer = 0;
    int size1 = str1.size(), size2 = str2.size();
    unordered_map<string, int> stMap1, stMap2, unionMap, interMap;
    {
        int i=0, j=1;
        while(i<size1 && j<size1)
        {
            while(j<size1 && (!isEn(str1[i]) || !isEn(str1[j])))
            {
                i++; j++;
            }
            if(j>=size1) {
                break;
            }
            string temp;
            temp += toLower(str1[i]);
            temp += toLower(str1[j]);
            stMap1[temp]++;
            unionMap[temp]++;
            i++; j++;
            cout << temp << '\n';
        }
    }
    {
        int i=0, j=1;
        while(i<size2 && j<size2)
        {
            while(j<size2 && (!isEn(str2[i]) || !isEn(str2[j])))
            {
                i++; j++;
            }
            if(j>=size2) break;
            string temp;
            temp += toLower(str2[i]);
            temp += toLower(str2[j]);
            stMap2[temp]++;
            i++; j++;
            cout << temp << '\n';
        }
    }
    for(auto i : stMap2){
        unionMap[i.first] = unionMap[i.first] ? max(unionMap[i.first], i.second) : i.second;
        if(stMap1.find(i.first) != stMap1.end()){
            interMap[i.first] = min(stMap1[i.first], i.second);
        }
        
    }
    int uni = 0, inter = 0;
    for(auto i : unionMap){
        uni += i.second;
    }
    for(auto i : interMap){
        inter += i.second;
    }

    double ans = double(inter)* 65536. / double(uni);
    answer = int(ans);
    
    return answer;
}

int main () {
    cout << char('Z' + 1) << '\n';
    // solution(s1, s2);
}