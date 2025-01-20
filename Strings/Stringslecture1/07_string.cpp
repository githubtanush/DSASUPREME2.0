//character array null terminated hota 
//aise hi string hota hai 
//string mein hme class/object ki baat krni chaiye 


//for creating string
// string name;
//string is a datatype name is a variable name

//string is a collection of character
//string runtime mein dynamically change kr skti hai like vector

//creation of string  =>  string name;
//input of the string  => cin>>name;
//print the string  => cout<<name;
//access the string => by index;


#include<iostream>
using namespace std;
//string inbuilt function - size, empty , push_back, pop_back, append,at
// substr, compare , find
int main(){
    // //creation
    // string name;

    // //input
    // // cin>>name;// delimeter - space / tab and new line
    // // so use getline
    // getline(cin,name);

    // //print
    // cout<<"Printing name : "<<name<<endl;

    // // cout<<"printing first character : "<<name[0]<<endl;

    // int index = 0;
    // while(name[index] != '\0'){
    //     cout<<"Index : "<<index<<" character : "<<name[index] <<endl;
    //     index++;
    // }

    // cout<<"Printing index 6 value : "<<name[6]<<endl;

    // int value = (int) name[6];
    // cout<<"Value : "<<value<<endl;

    // string name;
    // cin>>name;

    // //empty string 
    // string temp = "";
    // cout<<"Length of the string : "<<name.length()<<endl;
    // cout<<"String is empty or not : "<<name.empty()<<endl;
    // cout<<"Character at position 0 is : "<<name.at(0) << endl;
    // cout<<"Front character of string is : "<<name.front()<<endl;
    // cout<<"back character of string is : "<<name.back()<<endl;

    // //append = to concatenate two strings
    // string str1 = "Tanush";
    // string str2 = "Arora";
    // cout<<"Before appending : "<<endl;
    // cout<<str1<<endl<<str2<<endl;
    // //append
    // str1.append(str2);
    // cout<<"After appending : "<<endl;
    // cout<<str1<<endl<<str2<<endl;


    // string desc = "This is a car";
    // desc.erase(4,3);
    // cout<<desc<<endl;

    // string names = "Tanush Arora";
    // string middle = "kumar ";
    // names.insert(7,middle);
    // cout<<names<<endl;

    // you can also use push and pop back operation in string


    //now ab string ke andar find krni hai 
    // to find function use hota hai 
    // string str1 = "yaar tera superstar desi kalakar";
    // string str2 = "star";
    // if(str1.find(str2) == string::npos){
    //     //npos ke equal aagya matlab found nhi hua to
    //     //not found kr do 
    //     cout<<"Not Found"<<endl;
    // } 
    // else{
    //     //nhi to found ho gya
    //     cout<<"Found"<<endl;
    // }

    //compare krne ke liye .compare    
    // string str1 = "Tanush";
    // string str2 = "Tanush";
    // if(str1.compare(str2) == 0){
    //     cout<<"Matching"<<endl;
    // }
    // else{
    //     cout<<"Not matching"<<endl;
    // }

    //substring ek string ke andar se substring keise nikalta hai 
    string desc = "This is a car, big daddy of all suvs";
    cout<<desc.substr(19,5)<<endl;

    return 0;   
}