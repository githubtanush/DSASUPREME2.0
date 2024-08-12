#include<iostream> // this header file for input / output
#include<numeric> // this header file we include for accumulate
#include<vector> // this header file for using vector array 
using namespace std; // initialize so that we can under stand we use standard cin , cout

bool ispossiblesolution(vector<int>& arr,int k,long long mid){
    //make one variable timesum and initialize it with 0 to keep the track of the time
    long long timesum = 0;
    //make one variable count and initialize it with 1 so that we say that 1st painter can work and track of another painter's
    long long count = 1;

    //iterate loop till the size of the vector array 
    for(int i = 0; i < arr.size();i++){
        //if current time is greater then the solution or we can say that mid
        // then simply return false;
        if(arr[i] > mid) return false;
        //if that thing not happen then check arr[i] + timesum is greater than mid or less than mid
        if(arr[i] + timesum > mid){
            //if it is greater than the solution or mid then simply increment count variable that tells there is chance of another painter
            count++;
            //and also overhead timesum with current element
            timesum = arr[i];

            //but wait are u think if there is tracker container painter more than the total painter then  what we do ??
            //then simply return false;
            if(count > k) return false;
        }   
        else{
            //if it is less than solution or mid then simply add timesum with current element
            timesum += arr[i];
        }
    }
    //if it reaches till the end means it will simply return true means solution has exist;
    return true;

}


// /we give return type long long so that when we accumulate e ans it may be break the limit of int so 
//to avoid any inconvenience in further firstly do return type to long long 
// so you can go smoothly in further process
long long  painterspartition(vector<int>& arr,int k){
        //if we can create the search space as number of pages in the books we can create search space for finding
        int s = 0;
        int e = accumulate(arr.begin(),arr.end(),0);
        //we can create 1 new answer variable and initialize it to -1 so that we can store value in the answer variable and return it 
        long long  ans = -1;

        //we can set the condition of s <= e so that we iterate from all books simply we can say that apply binary search 
        //for minimize or maximize the function
        while(s <= e){
            //finding mid
            long long mid = ( s + ((e-s) >> 1 ) );

            //if solution has exist that means may be answer is also existing on the left side of the array
            if(ispossiblesolution(arr,k,mid)){
                //if solution exist store mid in answer
                ans = mid;
                //and check left side of the mid also 
                e = mid - 1;
            }
            //if solution has not exist that means we say s = mid + 1 so because answer is always on the right if it does not satisfy atmost value
            else{
                //if solution does not exist that means we check answer value on the right side of the mid
                s = mid + 1;
            }
        }
        return ans;
}
int main(){
    int k;
    cout<<"Enter how many painter's you have : ";
    cin>>k;
    int size;
    cout<<"Enter the size of the vector array : ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter elements into vector : ";
    for(int i = 0; i < size;i++){
        cin>>arr[i];
    }
    long long ans = painterspartition(arr,k);
    cout<<"Maximum time to finish the total work is : "<<ans<<endl;
    return 0;
}
// 4
// 4
// 10 20 30 40