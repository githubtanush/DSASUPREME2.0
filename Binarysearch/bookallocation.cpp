#include<iostream> // this header file for input / output
#include<numeric> // this header file we include for accumulate
#include<vector> // this header file for using vector array 
using namespace std; // initialize so that we can under stand we use standard cin , cout

bool ispossiblesolution(vector<int>& arr,int n,int m, int mid){
        //firstly we count the pagesum so we intialize one  variable pagesum with 0
        int pagesum = 0;
        // and we track the no. of students finish or not so we initialize one count variable with initialize with student 1
        int count = 1;
        //now we iterate on all the 4 books for finding pagesum  and  verify that mid is one of the possible solution or not
        for(int i = 0; i < m ; i++){
            //but wait there if one more condition exist if current pagesum value is greater then mid value then must return false because we cannot allocate
            //the student to one book
            if(arr[i] > mid) return false;
            //now we check if pagesum when we add with arr value then it cannot greater than mid 
            //if it becomes greater than mid then 
            if(arr[i] + pagesum > mid){
                //then firstly we increment count that there is starting of another student
                count++;
                //then we simply override pagesum with arr[i] value
                pagesum = arr[i];
                //but wait if count variable exceeds the number of students then it must also return false
                if(count > n) return false;
            }
            else{
                //means pagesum not overflow 
                //then simply add arr[i] in pagesum
                pagesum += arr[i];
            }
        }
    //if we reach at that point it means you all done are correctly then return true
    return true;
}

//we give return type long long so that when we accumulate e ans it may be break the limit of int so 
//to avoid any inconvenience in further firstly do return type to long long 
// so you can go smoothly in further process
long long  booksallocation(vector<int>& arr,int n, int m){
//1st condition is that if number of students more than no. of books that which we can distribute 
// so it return -1 that books is not allocated 
//because is condition is that every student can get atleast one book 
        if(n > m) return -1;
        //if we can create the search space as number of pages in the books we can create search space for finding
        int s = 0;
        int e = accumulate(arr.begin(),arr.end(),0);
        //we can create 1 new answer variable and initialize it to -1 so that we can store value in the answer variable and return it 
        long long  ans = -1;

        //we can set the condition of s <= e so that we iterate from all books simply we can say that apply binary search 
        //for minimize or maximize the function
        while(s <= e){
            //finding mid
            int mid = ( s + e ) >> 1;

            //if solution has exist that means may be answer is also existing on the left side of the array
            if(ispossiblesolution(arr,n,m,mid)){
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
    int n;
    cout<<"Enter number of student : ";
    cin>>n;
    int m;
    cout<<"Enter no. of books : ";
    cin>>m;
    vector<int> arr(m);
    cout<<"Enter elements into array : ";
    for(int i = 0; i < m;i++){
        cin>>arr[i];
    }
    long long answer = booksallocation(arr,n,m);
    cout<<"Students which has maximum of minimum books is : "<<answer<<endl;
    return 0;
}
// 2
// 4
// 12 34 67 90