//05_findmissingelementinsortedarray
#include<iostream>
#include<vector>
using namespace std;
//When there is sorted array or start from 1 then we use binary search
// if pattern continues by +1 then it is ok but if there is pattern break then 
// it means that element is missing


//Now homework what is change in full logic so that last if condition we remove
int findmissingelement(vector<int>& arr){
    int s = 0;
    int e = arr.size()-1;
    int mid = s + ( e - s )/2;
    int ans = -1;
    while(s <= e){
        int diff = arr[mid] - mid;
        if(diff == 1){
            //right mein jao
            s = mid + 1;
        }
        else{
            //answer ko store kro or left mein jao
            ans = mid;
            //left mein jao
            e = mid - 1;
        }
        mid = s + ( e - s )/2;
    }
    if(ans+1 == 0) return arr.size()+1;
    return ans+1;
}
int main(){
    int n;
    cout<<"Enter how many elements do you want to enter : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int answer = findmissingelement(arr);
    cout<<"Missing element is : "<<answer<<endl;

    return 0;
}
//8
//1 2 3 4 6 7 8 9 