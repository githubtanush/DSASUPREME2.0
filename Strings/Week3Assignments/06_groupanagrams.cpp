#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<array>
using namespace std;

//Method 1 - with sorting
// vector<vector<string>>groupAnagrams(vector<string>& strs){

    // //Method 1 - sort the array 
    // //saara element ko map kr diya
    // map<string,vector<string>>mp;
    
    // //ek ek krke har string ko access kiya or usko sort kiya
    // for(auto str:strs){
    //     string s = str;
    //     sort(s.begin(),s.end());
    //     //or sorting vali string ka map mein saaari us level ki unsorted list map kr liya
    //     mp[s].push_back(str);
    // }
    // //then usko ek 2d vector mein push kr diya 
    // vector<vector<string> > ans;
    // //or map key value hota jisme key  ko first or value ko second kaha jata hai 
    // //to hmm it ke second ko vector mein push kr denge or hmara map create ho jayga
    // for(auto it = mp.begin();it != mp.end();it++){
    //      ans.push_back(it->second);
    // }
    // return ans;
 //TC = O(nklogk)
 //SC =  O(Nk)
// }
    //Method2 - without sort the array
    //TC - O(Nk)
    //SC- O(NK)
    //new stl used STL::array<int,256>hash = {0};
    std::array<int,256> computehash(string s){
        std::array<int,256>hash = {0};
        for(int i = 0; i < s.size();i++){
            hash[s[i]]++;
        }
        return hash;
    } 
    //Method2 without sorting
    
    vector<vector<string> > groupAnagrams(vector<string>& strs){
        map<std::array<int,256> ,vector<string> >mp;

        for(auto str: strs){
            mp[computehash(str)].push_back(str);
        }
        vector<vector<string> > ans;
        for(auto it = mp.begin(); it != mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
int main(){
    vector<string> s;
    string temp;
    cout<<"When u stop to enter in this vector array then type (END) :";
    while(cin>>temp){
        if(temp=="END") break;
        s.push_back(temp);
    }
    vector<vector<string> > ans = groupAnagrams(s);
    for(auto i = 0; i < ans.size(); i++){
        for(auto it = 0; it<ans[i].size();it++){
            cout<<ans[i][it]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// eat tea tan ate nat bat 
// END