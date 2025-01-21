#include<iostream>
#include<vector>
using namespace std;
// //this function normalises all the words and patterns into a similar format
// // so that we can compare them and find the solution
//     void createMapping(string &str){
//         //find mapping
//         char start = 'a';
//         char mapping[300] = {0};

//         for(auto ch: str){
//             if(mapping[ch] == 0){
//                 mapping[ch] = start;
//                 start++;
//             }
//         }
//         //update the string
//         for(int i = 0; i < str.length();i++){
//             char ch = str[i];
//             str[i] = mapping[ch];
//         }
//     }
// //we simply create the array for both of the vector and string then if it is matched then we say that it is matching else we 
// // say that it is not matching
// vector<string> findandreplace(vector<string> words,string pattern){
//    vector<string> ans;
//         //firstly normalise the pattern 
//         createMapping(pattern);
//         //saara words ke sath khelna hai 
//         for(string s: words){
//             string temp = s;
//             //normalise temp
//             createMapping(temp);
//             if(temp == pattern){
//                 //it means , that "s" wali string was a valid answer
//                 ans.push_back(s);
//             }
//     return ans;
// }
// }
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