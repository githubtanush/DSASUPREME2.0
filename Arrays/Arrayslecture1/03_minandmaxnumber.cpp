#include<iostream>
#include<limits>//for INT_MIN ,INT_MAX
#include<vector> //for vector
using namespace std;
int findminimum(vector<int>& arr){
    //mini ko INT_MAX se initialize kiya jiska matlab yeh hai ki jada se jada yeh value ho skti hai
    int mini = INT_MAX; // initialize one variable with INT_MIN named maxi
    for(int i = 0; i < arr.size();i++){//iterate in the for loop 
    if(arr[i] < mini){//agr arr[i] mini se km hai toh
    mini = arr[i]; //mini ke andar arr[i] ko daal do or iterate krte rho
    }
    }
    return mini; // or last mein mini ko return krdo
}
int findmaximum(vector<int>& arr){
    //maxi ko INT_MIN se initialize kiya jiska matlab yeh hai ki km se km yeh value ho skti hai
    int maxi = INT_MIN; // initialize one variable with INT_MIN named maxi
    for(int i = 0; i < arr.size();i++){//iterate in the for loop 
    if(arr[i] > maxi){//agr arr[i] maxi se jada hai toh
    maxi = arr[i]; //maxi ke andar arr[i] ko daal do or iterate krte rho
    }
    }
    return maxi; // or last mein maxi ko return krdo
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    cout<<"Minimum number in the array is : "<<findminimum(arr)<<endl;
    cout<<"Maximum number in the array is : "<<findmaximum(arr)<<endl;
    return 0;
}