#include<iostream>
using namespace std;
int solve(string& word1,string& word2,int i,int j){
    //base case
    if(i>=word1.length()) //word1 vali string end ho gyi hogi 
        return word2.length()-j;// word1 ki length mein bhi word2 se choti hai
    if(j>=word2.length()) //word2 vali string end ho gyi hogi 
        return word1.length()-i;// word2 ki length mein bhi word1 se choti hai
    
    int ans = 0;
    //recursive cases
    if(word1[i]==word2[j]){
        //match
        ans = 0 + solve(word1,word2,i+1,j+1);
    }
    else{
        //not match
        //operation perform 
        //insert
        int option1 = 1 + solve(word1,word2,i,j+1);
        //remove
        int option2 = 1 + solve(word1,word2,i+1,j);
        //replace
        int option3 = 1 + solve(word1,word2,i+1,j+1);

        ans = min(option1,min(option2,option3));
    }
    return ans;
}
int mindistance(string& word1,string& word2){
    int i = 0;
    int j = 0;
    int ans = solve(word1,word2,i,j);
    return ans;
}
int main(){
    string word1;
    getline(cin,word1);
    string word2;
    getline(cin,word2);
    int ans = mindistance(word1,word2);
    cout<<"Minimum number of operations apply on word1 to convert in word 2 is : "<<ans<<endl;
    return 0;
}
//test case 1 - 
//word1 - 
//horse
//word2 - 
//ros

//output == 3

//testcase 2 - 
//intention
//execution
//5 operations