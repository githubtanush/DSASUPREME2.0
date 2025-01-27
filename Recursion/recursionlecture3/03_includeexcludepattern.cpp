//include exclude pattern
#include<iostream>
#include<vector>
using namespace std;
void subsequenceofstring(string s,string output,int index){
    //base case
    if(index >= s.length()){
        //ans jo h , vo output string mein build ho chuka hai 
        // to print krdo
        cout<<"-> "<<output<<endl;
        return ;
    } 

    char ch = s[index];
    // //exclude
    // subsequenceofstring(s,output,index+1);
    
    // //include
    // // output string mein ch character ko include krdo 
    // output.push_back(ch);
    // subsequenceofstring(s,output,index+1); 


    //include
    output.push_back(ch);
    subsequenceofstring(s,output,index+1);

    //exclude
    output.pop_back();
    subsequenceofstring(s,output,index+1);

}
int main(){
    //Take the string s
    string s;
    //take the input 
    getline(cin,s);
    //jis string mein store krna vo rkho
    string output = "";

    subsequenceofstring(s,output,0);


    return 0;
}