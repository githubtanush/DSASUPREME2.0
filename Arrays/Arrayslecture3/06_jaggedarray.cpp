// 06_jaggedarray
#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<int> >& arr){
    for(int i = 0; i < arr.size();i++){
        for(int j = 0;j < arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int> > brr;


    //jagged array means 2d vector array with varying sizes
    vector<int> vec1(10,0);
    vector<int> vec2(5,1);
    vector<int> vec3(7,0);
    vector<int> vec4(8,1);
    vector<int> vec5(20,0);

    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);
    brr.push_back(vec5);
    print(brr);
    return 0;
}