#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

void numberGuessing(){
    int A = 0, B = 0, gap = 0, chance = 0;
    string result;
    cin >> A >> B;
    cin >> chance;
    gap = (B - A);
    A += gap = (gap + 1) / 2;
    for (int i = 0; i< chance; ++i){
        cout << A << endl;
        cin >> result;
        if(result == "CORRECT") 
            return;
        else if(result == "TOO_SMALL")
            A += gap = (gap + 1) / 2;
        else if(result == "TOO_BIG")
            A -= gap = (gap + 1) / 2;
        else if(result == "WRONG_ANSWER")
            throw "wrong answer";
        else
            throw "what happen?";
    }
    throw "chance all used...";
}

int main() {
    int testNum = 0;
    cin >> testNum;
    
    for(int i = 0; i<testNum; ++i)
        numberGuessing();
    return 0;
}