// map is stored valued in their in key value format
//in  map there is one utility called iterators
//is we access the eleemnt of array with pointer
//traverse through iterator
//function / utilities in maps 
// ordered map / unordered map
//map is only a data structure which do insertion , deletion and searching in constant time
//ordered-map (logn)
//unordered_map (O(1)) ~ nearly constant time
//ordered map using balance BST
//unordered_map - Array / hashtable / Bucketarray
#include<iostream>
#include<unordered_map>
using namespace std;
int main(){

    //creation
    unordered_map<string,int> mapping;

    //insertion
    pair<string,int> p = make_pair("Tanush",60);
    pair<string,int> q("Tanush",61);
    pair<string,int> r;
    r.first = "arun";
    r.second = 21;

    //insertion
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    cout<<"size of map : "<<mapping.size()<<endl;

    //Access
    cout<<mapping.at("Tanush")<<endl;
    cout<<mapping["Tanush"]<<endl;

    if(mapping.find("Tanush") != mapping.end()){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
     
}