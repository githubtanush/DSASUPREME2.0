#include<iostream>
using namespace std;
void findsubsequence(string str,string output ,int index){
    //base case 
    if(index>=str.length()){
        //answer jo h ,vo output string mein build ho chuka hai print krdu
        cout<<"->"<<output<<endl;
        return ;
    }
    
    //processing
    char ch = str[index];
    
    //exclude
    findsubsequence(str,output,index+1);
    //include - output string mein character ko include krdo 
    output.push_back(ch);
    findsubsequence(str,output,index+1);
}
int main(){
    string str = "abc";
    string output = "";
    int index = 0;
    findsubsequence(str,output,index);
    return 0;
}