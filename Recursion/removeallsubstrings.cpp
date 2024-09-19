#include<iostream>
using namespace std;
//recursive mein datastructures ko byrefrence lena prefer kro taaki jab recursive stack par apki call jaati jaay to same copy na bnti jaay
void removealloccurrances(string& s,string& part){

    //Timecomplexity = O(NM);
    // Leftpart = O(N) , rightpart = O(M), maximum - O(NM);
    //timecomplexity of 1 case

    //how many recursive call in worst case
    //total calls = N/M
    //timecomplexit = O(N/M * NM) = O(N2)
    //space complexity = O(N/M)


    //1.) find part string in s
    //2.) remove part from s
    //3.) call again the function for new string

//s.find is STL Function or jo string as a parameter di hai uski position bta deta
//string::substr(0->starting position,number of characters -> length)

    //processing
    int found = s.find(part);
    if(found != string::npos){
        //part string has been found
        //please remove it
        string leftpart = s.substr(0,found);
        string rightpart = s.substr(found+part.size(),s.size());
        s = leftpart + rightpart;
         //recursive relation
        removealloccurrances(s,part);
    }
    else{
        //Base case
        //all the occurrances of part has been removed
        return ;
    }

}
string removeoccurrance(string s,string part){
    removealloccurrances(s,part);
    return s;
}
int main(){
    //remove all occurrance of substring
    string s = "daabcbaabcbc";
    string part = "abc";
    string st = removeoccurrance(s,part);
    cout<<"Result string will be : "<<st<<endl;
    return 0;
}