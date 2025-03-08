#include<iostream>
using namespace std;
void printname(int n){
    if(n == 0) return ;

    cout<<"Tanush Arora"<<endl;

    printname(n-1);
}
void print1ton(int index,int n){
    if(index > n) return ;

    cout<<index<<" ";
    print1ton(index+1,n);
}
void subsequences(vector<int>& arr,int index){

}
int main(){
    int n;
    cin>>n;
    // printname(n);

    // print1ton(1,n);

    vector<int>  
    subsequences(arr,0);

    return 0;
}