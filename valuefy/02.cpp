#include<iostream>
using namespace std;
void merge(vector<int>& v,int s,int e){
    int mid = s + ( e - s )/2;
    int n1 = mid - s + 1;
    int n2 = e - mid;
    vector<int> l(n1),r(n2);
    int i = 0 , j = 0;
    int k = s;
    for(i = 0; i < n1;i++){
        l[i] = v[k];
        k++;
    }
    k = mid + 1;
    for(j = 0; j < n2;j++){
        r[j] = v[k];
        k++;
    }
    while(i < n1 && j < n2){
        if(l[i] < r[j]){
            v[k] = l[i];
            k++;
            i++;
        }
        else{
            v[k] = r[j];
            k++;
            j++;
        }
    }
}
void mergesort(vector<int>& v,int s,int e){
    if(s >= e) return ;
    int mid = s + ( e - s )/2;
    mergesort(v,s,mid);
    mergesort(v,mid+1,e);
    merge(v,s,e);
} 
int main(){

}