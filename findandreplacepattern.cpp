#include<iostream>
#include<vector>
using namespace std;
void createmapping(string& s){
    char mapping[256] = {0};
    char start = 'a';

    for(auto ch:s){
        if(mapping[ch]==0){
        mapping[ch] = start;
        start++;
        }
    }

    //update string
    for(int i = 0; i < s.length();i++){
        char ch = s[i];
        s[i] = mapping[ch];
    }
}
vector<string> findandreplace(vector<string> words,string pattern){
    vector<string> ans;
    string temp = pattern;
    createmapping(temp);
    for(auto s : words){
        string tempstring = s;
        createmapping(tempstring);
        if(tempstring==temp){
            //it means s wali string is a valid answer
            ans.push_back(s);
        }
    }
    return ans;
}
int main(){
    string pattern;
    getline(cin,pattern);

    vector<string> words;
    string temp;
    while(cin>>temp){
        if(temp=="END") break;
        words.push_back(temp);
    }
    vector<string> ans = findandreplace(words,pattern);
    cout<<"Answer is : ";
    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}
// abc deq mee aqq dkd ccc END
//  abb