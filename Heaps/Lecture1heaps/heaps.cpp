#include<iostream>
#include<vector>
using namespace std;
class heap{
    public:
        int* arr;
        int capacity;
        int size;

    heap(int capacity){
        this->arr = new int[capacity];
        this->capacity = capacity;
        //Size -> current number of elements in heap
        this->size = 0;
    }
 
    void insert(int val){
        //agr maanlo index jo hai 
        if(size == capacity){
            cout<<"Heap Overflow"<<endl;
            return ;
        }
        //Size increase kr denge
        size++;

        int index = size;
        arr[index] = val;
        
        //take the val to it's correct position
        while(index > 1){
            int parentindex = index / 2;
            if(arr[index] > arr[parentindex]){
                swap(arr[index],arr[parentindex]);
                index = parentindex;
            }
            else break;
        }
    }

    void printheap(){
        for(int i = 1; i <= size;i++) cout<<arr[i]<<" ";
    }

    //Deletion in heap 
    // Deletion in heap krna hai to sbse pehle last vala node 
    // uthalo kyuki us par kisi ki dependency nhi hai then usko 
    // lakar meini root node par daal diya 
    // then root node ko meini 2i and 2i+1 se check kr liya
    int deletion(){
        //root node ko delete kr rah hai 
        int answer = arr[1];
        //replacement krni hai 
        //last element size par hoga
        arr[1] = arr[size];
        //last element ko delete krdo uski original position se
        size--;
        int index = 1;
        while(index < size){
            int leftindex = 2 * index;
            int rightindex = 2 * index + 1;

            //find out krna hai , sbse bda kon hai 
            int largestkaindex = index;
            //check left child
            if(leftindex <= size && arr[largestkaindex] < arr[leftindex])
                largestkaindex = leftindex;
            if(rightindex <= size && arr[largestkaindex] < arr[rightindex])
                largestkaindex = rightindex;
            
            if(index == largestkaindex)  break;
            else{
                swap(arr[index],arr[largestkaindex]);
                index = largestkaindex;
            }
        }
        return answer;
    }
};
void heapify(int* arr,int n,int index){
    int leftindex = 2 * index;
    int rightindex = 2 * index + 1;
    int largestindex = index;

    //teeno me se max lao
    if(leftindex <= n && arr[leftindex] > arr[largestindex])
        largestindex = leftindex;

    if(rightindex <= n && arr[rightindex] > arr[largestindex])
        largestindex = rightindex;
    
    //after these 2 conditions largestindex will be pointing towards largest element among 3
    if(index != largestindex){
        swap(arr[index],arr[largestindex]);
        //ab recursion sambhal lega
        index = largestindex;
        heapify(arr,n,index);
    }
}
//Leaf node ko kbhi bhi test karne ki need nhi hai vo hmesha valid heap hoti hai 
    // (n/2 + 1)th -> nth node all are leaf node 
    void buildheap(int arr[],int n){
        for(int index = n / 2; index > 0; index--)
            heapify(arr,n,index);
    } 

    //After buildheap and heapify what is the time complexity ?
    // creation - O(N)
    
    //Heap sort - sort the array 
    // 30 11 20 10 5 6 

    //heapsort mein simply 2 steps hota hai 
    //1.) Last mein insert kro 
    //2.) first se heapify kro 
    // simply heapsort ho jayga
    void heapsort(int arr[],int n){
        while(n > 1){
            //mostly yaah par n-1 lgata hai pr tum yaad rkhna 
            // ki yaah 1-based indexing hai so n hi last element
            // hoga
            swap(arr[1],arr[n]);
            n--;
            heapify(arr,n,1);
        }
    }
int main(){
    // 0th index mein hme -1 ya kuch bhi daalna kyuki vo 0th index se le rah 
    int arr[] = {-1,5,10,15,20,25,12};
    int n = 6;
    buildheap(arr,n);
    cout<<"Printing heap : "<<endl;
    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,n);
    cout<<"Printing heap : "<<endl;
    for(int i = 1; i <= n ; i++) cout<<arr[i]<<" ";
    cout<<endl;
    // heap h(20);
    //insertion
    // h.insert(10);
    // h.insert(20);
    // h.insert(30);
    // h.insert(11);
    // h.insert(5);
    // h.insert(6);

    // cout<<"printing the content of the heap : "<<endl;
    // h.printheap();

    // cout<<endl<<"Deletion in heap : " <<h.deletion()<<endl;
    // cout<<"After deletion : ";
    // h.printheap();
    return 0;
}

// heap creation is done in O(n)✔️ not O(nlogn)❌
// finding maximum and minimum in heap is O(1)
// in array find max and min in O(n)

// insertion / deletion in heap take time O(logn);