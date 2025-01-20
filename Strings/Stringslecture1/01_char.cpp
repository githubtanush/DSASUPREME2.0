// character array is made assitice same like the integer array 
// char array contains 1 byte space integer array contains 4 bytes space
// for each memory block
// total we have 256 character to fill in this


// #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;

int main(){
    
    // // for integer array 
    // int arr[10];
    // //input
    // for(int i = 0; i < 10; i++){
    //     cin>>arr[i];
    // }
    // //for printing integer array 
    // for(int i : arr) cout<<i<<" ";

//#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //In the case of integer array we create array and for taking 
    //input or printing this we go with a for loop 
    //to input or print each and every value

    // but in the case of character this take 1 byte space and 
    // also we take input in one line 

    // for character array also make one size bigger than actual
    //because where the string end it's add null character at the end
    //and at null character your printing will be stop


    //use character array in case of string because character array are more
    //efficient and faster than strings that was why you may be notice
    //when you do some questions with strings this show tle
    //but if you do with character array yeh chl gya
    //null character ki ascii value 0 hai
    //baaki character array ke upar hm same integer array vala sb kuch lga skta hai
    //chay vo two pointer ho prefix sum ho ya kuch bhi

    // //creation 
    // char ch[100];
    
    // //input
    // // cin>>ch;//but remember that for this cin space , tab and new line is delimeter
    // //by getline this delimeter is only new line and for this we use
    // // cin.getline(then array name , size of the array)
    // cin.getline(ch,100); 

    // //print
    // cout<<"printing the value of ch : "<<ch<<endl;

    // //printing using loop 
    // for(int i = 0; i < 10;i++){
    //     cout<<"At Index : "<<i<<" "<<ch[i]<<endl;
    // }

    // char temp = ch[6];
    // //typecasting to check this at what number
    // int value = (int) temp; 
    // cout<<"Printing integer value : "<<value<<endl;

    return 0;
}