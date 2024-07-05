#include<iostream>
#include<vector>
using namespace std;
void moveallnegativenumbers(vector<int>& v){
    //Method 1 - sorting
    // sort(v.begin(),v.end());
    //Method 2 - counting approach
    // int negcount = 0;
    // int poscount = 0;
    // vector<int> temp(v.size());
    // for(int i = 0; i < v.size();i++){
    //     if(v[i]<0){
    //         negcount++;
    //     }
    //     if(v[i]>0){
    //         poscount++;
    //     }
    // }
    // for(int i = 0; i < poscount;i++){
    //     if(v[i]>0){
    //         temp.push_back(v[i]);
    //     }
    // }
    // for(int i = poscount; poscount< v.size();poscount++){
    //     if(v[i]<0){
    //         temp.push_back(v[i]);
    //     }
    // }
    // for(int i = 0; i < v.size();i++){
    //     v[i] = temp[i];
    // }

    //Method 3 - two pointers
    int i = 0;
    int j = v.size()-1;
    while(i<j){
        if(v[i]>=0){
            //means positive number
            i++;
        }
        else if(v[j]<0){
            //means negative number
            j--;
        }
        else{
            //upar se saari condition to already check hokar aa hi rhi hai to yaah swap plus bda do 
            swap(v[i],v[j]);
            i++;
            j--;
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
    moveallnegativenumbers(v);
    for(auto i : v){
        cout<<i<<" ";
    }
}
// 8
// 1 -1 3 2 -7 -5 11 6