/*
https://programmers.co.kr/learn/courses/30/lessons/42583
*/

#include <string>
#include <vector>

using namespace std;

typedef struct Queue{
    public :
    
    Queue(int maxSize)
        : maxSize(maxSize), front(0), back(-1), data(new int[maxSize]){}
    
    ~Queue(){
        delete data;
    }
    
    bool IsEmpty(){
        return (front+1)%maxSize == back%maxSize;
    }
    
    bool IsFull(){
        return front%maxSize == (back+1)%maxSize;
    }
    
    void Push(int d){
        if(IsFull()){
            throw "Queue Overflow Error";
            return;
        }
        data[(++back)%maxSize] = d;
    }
    
    int Pop(){
        if(IsEmpty()){
            throw "Queue Empty Error";
            return 0;
        }
        return data[(front++)%maxSize];
    }
            
    private :
    
    int maxSize;
    
    int front;
    int back;
    int* data;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    Queue bridge = Queue(bridge_length);
    int carWeights = 0;
    int idx = 0;

    while(idx != truck_weights.size()){
        if(carWeights + truck_weights[idx] > weight){

        }
    }

    return answer;
}