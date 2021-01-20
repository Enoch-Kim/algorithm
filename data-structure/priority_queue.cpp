#include <vector>
#include <iostream>

using namespace std;

class PriorityQueue{
    /*
    minimum priority queue
    */
    public:
        PriorityQueue(int maxSize) : maxSize(maxSize), size(0), heap(vector<int>(maxSize+1)){}

        PriorityQueue(int maxSize, vector<int> arr) : maxSize(maxSize), size(0), heap(vector<int>(maxSize)) {
            for(int i=0; i<arr.size(); i++){
                Push(arr[i]);
            }
        }

        void Push(int val) {
            size++;
            heap[size] = val;
            
            int idx = size;
            
            while(idx > 1 && heap[idx/2] > val){
                swap(heap[idx], heap[idx/2]);
                idx /= 2;
            }
        }

        void Push(vector<int>& arr){
            for(int i=0; i<arr.size(); i++){
                Push(arr[i]);
            }
        }

        int Pop(){
            int minVal = heap[1];
            heap[1] = heap[size];
            size--;

            int idx = 1;
            int minIdx = getMinChild(idx);
            while(heap[idx] > heap[minIdx]){
                swap(heap[idx], heap[minIdx]);
                idx = minIdx;
                minIdx = getMinChild(idx);
            }
            return minVal;
        }

        void Print(){
            int two = 2;
            cout << "heap \n";
            for(int i=1; i<size; i++){
                if(i % two == 0) {
                    cout << '\n';
                    two *= 2;
                }
                cout << heap[i] << "\t";
            }
            cout << heap[size] << "\n";
        }

    private:

        int getMinChild(int idx){
            if(size/2 < idx){
                return idx;
            }
            int left = idx*2 <= size ? idx*2 : idx;
            int right = idx*2+1 <= size ? idx*2+1 : idx;

            if(heap[left] < heap[right]){
                return left;
            } else {
                return right;
            }
        }

        int maxSize;
        int size;
        vector<int> heap;
};

int main() {
    PriorityQueue pq = PriorityQueue(100);

    pq.Push(101);
    pq.Push(110);
    pq.Push(130);
    pq.Push(10);
    pq.Push(1);
    pq.Push(1120);
    pq.Push(1099);
    pq.Push(100);
    pq.Push(140);
    pq.Push(1210);
    pq.Push(1022);
    pq.Push(100);

    pq.Print();

    cout << "min element : " << pq.Pop() << '\n';

    pq.Print();
}