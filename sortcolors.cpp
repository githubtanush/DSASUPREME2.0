#include<iostream>
#include<vector>
using namespace std;
void sortcolors(vector<int>& v){
    //Method 1 - sorting
    // sort(v.begin(),v.end());

    //Method 2 - counting Approach
    // int zerocount = 0;
    // int onecount = 0;
    // int twocount = 0;

    // for(int i = 0; i < v.size();i++){
    //     if(v[i]==0){
    //         zerocount++;
    //     }
    //     if(v[i]==1){
    //         onecount++;
    //     }
    //     if(v[i]==2){
    //         twocount++;
    //     }
    // }
    // int index = 0;
    // for(int i = 0; i < zerocount;i++){
    //     v[index] = 0;
    //     index++;
    // }
    // for(int i = 0; i < onecount;i++){
    //     v[index] = 1;
    //     index++;
    // }
    // for(int i = 0; i < twocount;i++){
    //     v[index] = 2;
    //     index++;
    // }

    //Method 3 - Two pointers
    int left = 0;
    int index = 0;
    int right = v.size()-1;
    while(index < right){
        if(v[index]==0){
            swap(v[index],v[left]);
            left++;
            index++;
        }
        else if(v[index]==2){
            swap(v[index],v[right]);
            right--;
        }
        else{
            //v[index] 1 par hai 
            //so 
            index++;
        }
    }

}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    v.resize(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    sortcolors(v);
    for(int i = 0; i < v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
//size - 6
// 2 0 2 1 1 0
// 2 0 1