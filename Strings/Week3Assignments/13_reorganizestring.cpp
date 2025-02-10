#include<iostream>
using namespace std;
string reorganisestring(string& s){
    //Method1 - by using priority queue - TimeComplexity - O(NLogN)
    //Method2 - by using greedy approach 
    //jisme mein yeh soch skta hu ki mujhe most frequently character ko  
    //fit krna non - adjacently then mein fill krunga baaki ke 
    //sb bche hua character
    //now let's go 

    //when i am placing most occurant character it should be placed in one go  

        //lowercase english letters - 0 to 26
        // so no need to create 256 array frequency character

    // 1.) Count hash
    // 2.) Try to place most occurant in one go
    // if(not possible) return "";
    // 3.) place other characters . with 1 index gap
     
    int hash[26] = {0};
    for(int i = 0; i < s.size();i++){
        //yeh meini esliye kiya kyuki 97 se 123 tak jo characters hai mein unko 0 se 26 
        //mein map kr lunga
        //hihiihihihih hasna aa rah hai beta bhut or yhi bn nhi rah tha yaad rkhna
        hash[s[i]-'a']++;
    }//O(N) mein yeh kr diya 
    // then ab
    //find the most frequent character
    char max_freq_char;
    int maxfreq = INT_MIN;
    for(int i = 0; i < 26 ;i++){
        if(maxfreq<hash[i]){
        maxfreq = hash[i];
        max_freq_char = i + 'a';
        }
    }
    //now again 
    int index = 0;
    while(maxfreq>0 && index<s.size()){
        s[index] = max_freq_char;
        maxfreq--;
        index+=2;
    }
    if(maxfreq != 0){
        return "";
    }
    //max frequent character 0 ho gya matlab hm most frequent character ko place kr chuka
    // hai 
    hash[max_freq_char -'a'] = 0;
    //let's place the rest of characters
    for(int i = 0; i < 26;i++){
        while(hash[i]>0){
            index = index>s.size()?1:index;
            s[index] = i + 'a';
            hash[i]--;
            index+=2;
        }
    }
    return s;
}
int main(){
    string s;
    getline(cin,s);
    string output = reorganisestring(s);
    cout<<output<<" "; 
    return 0;
}

//aab
//aaab