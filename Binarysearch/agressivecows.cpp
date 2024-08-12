#include<iostream> // this header file for input / output
#include<numeric> // this header file we include for accumulate
#include<vector> // this header file for using vector array 
using namespace std; // initialize so that we can under stand we use standard cin , cout

bool ispossiblesolution(vector<int>& arr,int k , int mid){
    //can we place cows with atleast mid distance between cows?
    //to keep the track of cows create one variable count
    int c = 1;
    //stand the first cow at first stall 
    int pos = arr[0];
    //iterate till the size of the array and finding maximum of minimum distance
    for(int i =  0; i < arr.size();i++){
        if(arr[i]-pos >= mid){
            //means answer exist because we find atleast distance or greater than atleast from mid
            // so we place the cow at that and move another cow increment count variable 
            c++;
            pos = arr[i]; // and store pos of that stall in the variable pos
        }
        //if count is equal to k then return true;
        if(c==k) return true;
    }
    //but if count is not equal to k then return false 
    //or also it is seeing that if u reach at that step means atleast distance does not exist
    return false;
}

int aggressivecows(vector<int> arr,int k){
    //firstly we sort the array if they did not sort so that we made the search space 
    sort(arr.begin(),arr.end());
    //initialize the distance between cows to the search space 
    //which start from s = 0;
        int s = 0;
        //which ends at last element - first element
        int e = arr[arr.size()-1] - arr[0];
        //to store the answer we create one variable
        int ans = -1;
        //condition we say that s <= e because we also divide the array then thought is binary search
        while( s <= e){
            //finding mid
            int mid = s + ( e - s )/2;

            if(ispossiblesolution(arr,k,mid)){
                //if answer is existing then we check answer to right side of the because atleast maximum distance we want to find
                // and also store the mid which is answer
                ans = mid;
                //and move right side in the array 
                s = mid + 1;
            }
            else{
                //if the possible solution not exist then 
                //come to the lesser value then atleast
                e = mid - 1;
            }

        }
        //you made it here so return ans
        return ans;
}
int main(){
    int k ;
    cout<<"Enter how many cows do you exactly have : ";
    cin>>k;

    int n;
    cout<<"Enter the size of the vector array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements into vector : ";
    for(int i = 0 ; i < n;i++){
        cin>>arr[i];
    }
    long long ans = aggressivecows(arr,k);
    cout<<"The maximum of minimum between the cows is : "<<ans<<endl;
    return 0;
}
//Input - 
// 5
// 3
// 1 2 4 8 9 

//output  - 3