//Custom comparator - means we use cpp stl 
// sort()
// for vector -> sort(v.begin(),v.end());
// for array  -> sort(arr,arr+n);

#include<iostream>
#include<vector>
using namespace std;
// //mycomp parameter mein hmesha return type bool hoga
// bool mycomp(int& a,int& b){
//     // return a < b; // increasing order sorting
//     return a > b; // decreasing order sorting
// }

// always take return type bool for comparator 
//and pass parameter by refrence
bool mycomp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];//ascending order
    // return a[1]>b[1]; // descending order
}


void print(vector<vector<int> >& v){
    for(int i = 0; i < v.size();i++){
        vector<int>& temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout<<a<<" "<<b<<endl;
    }
    cout<<endl;
}
int main(){
    // int n;
    // cout<<"Enter how many elements do you want to take : ";
    // cin>>n;
    // vector<int> v(n);
    // for(int i = 0; i < n;i++) cin>>v[i];
    // //stl vala sort mein bubble sort , insertion sort , selection sort 
    // // nhi hota 
    // // esma merge sort , quick sort , heap sort ka kuch mishran hota h
    // // sort(v.begin(),v.end())// increasing order sorting
    // // for decreasing order we give one parameter of custom in which 
    // // we decide how to sort this
    // sort(v.begin(),v.end(),mycomp);
    // for(int i : v)cout<<i<<" ";

//#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //let's say we have do vector of vector sorting
    vector<vector<int> >v;
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    for(int i = 0; i < n;i++){
        int a,b;
        cout<<"Enter a,b : ";
        cin>>a>>b;
        vector<int>temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    cout<<"Here are the values : "<<endl;
    print(v);

    //Now sort by 1st index
    //but this sort do sorting by 0th index
    // sort(v.begin(),v.end());

    // sort with 1st index use mycomp
    sort(v.begin(),v.end(),mycomp);
    cout<<endl;
    print(v);
    return 0;
}
// 5
// 44 33 55 22 11

// 5
// 1 44
// 0 55
// 0 22
// 0 11
// 2 33