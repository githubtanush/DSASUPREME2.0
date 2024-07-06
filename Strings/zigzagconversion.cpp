#include<iostream>
#include<string>
#include<vector>
using namespace std;
string convert(string s,int numrows){
    //agr numrows 1 hai to string hi return krdo 
    if(numrows==1) return s;

    //eska size numrows jitna hoga aakhir utni rows hi to insert krni hai 
    vector<string> zigzag(numrows);

    //original string par iterate krega yeh i ;
    int i = 0;
    //hr row ka track rkhega
    int row = 0;
    //direction change krne mein helpful hoga
    bool direction = 1;
    //if direction==1 then top to bottom
    //if direction==0 then bottom to top

    while(true){
        if(direction){
            //Top to bottom
            while(row<numrows && i < s.size()){
                //agr row numrows se km hai or i string ke size se km hai 
                //har baar string ka index bdna chahiye kyuki different different strings mein insert krna hai 
                zigzag[row++].push_back(s[i++]);
            }
            row = numrows - 2;
        }
        else{
            // direction change - bottom to top 
            while(row >= 0 && i < s.size()){
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }
        //agr string se aaga chla gya to kro loop break;
        if(i>=s.size()) break;
        //direction har cycle ke end mein change hogi jo ki help kregi iterate krne mein 
        //this is very important and crucial
        direction = !direction;
    }
    string ans = "";
    for(int i = 0; i < zigzag.size();i++){
        ans += zigzag[i];
    }
    return ans;


}
int main(){
    string s;
    getline(cin,s);
    int numrows ;
    cout<<"Enter the value for how many rows you want to zigzag conversion : "<<endl;
    cin>>numrows;
    string ans  = convert(s,numrows);
    cout<<"After converting the string will look like : "<<ans<<endl;
    return 0; 
}
// PAYPALISHIRING
//  numRows = 3

//output - PAHNAPLSIIGYIR