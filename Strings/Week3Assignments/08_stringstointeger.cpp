#include<iostream>
#include<string>
using namespace std;
int myAtoi(string s){
    //Method 1 -  USAGE OF INBUILT FUNCTION
    //inbuilt function atoi in their i also convert string into character 
    // arrays by c_str();
    //in atoi function when string cannot convert to integer 
    // it simply returns 0 
    // int integer = atoi(s.c_str());
    //but weight there is one more inbuilt function which is stoi
    //but only difference between stoi and atoi is 
    // when string cannot convert to integer in stoi 
    // it throws an exception
    // int integer  = stoi(s.c_str());
    // return integer;


    //METHOD 2 - default way to understand problem and check all conditions
    //To create this follow 5 steps;
    int num = 0;
    int i = 0;
    //if sign is 1 means positive but if sign is -1 
    // means it is negative number
    int sign = 1;

    //STEP 1 - 
    //IGNORE THE TRAILING/LEADING SPACES
    while(i<s.size() && s[i]==' '){
        i++;
    }

    //STEP 2 - 
    //CHECK THERE I IS IN UNDER THE STRING ARRAY SIZE OR NOT
    //THEN NEXT CHECK SIGN IS THERE OR NOT 
    //IF SIGN IS THERE THEN WHAT SIGN IS THERE
    if(i<s.size() && (s[i]=='-' || s[i]=='+')){
        //sign is decided by relational operator
        sign =( s[i] == '+') ? 1 : -1;
        i++;
        //after finding sign - break;
        // break;   //WHEN WE USE WHILE INSTEAD OF IF THEN BREAK STATEMENT 
        // AT THAT TIME PLAY AN IMPORTANT ROLE
    }

    //STEP 3 - 
    //CHECK THERE CONDITION IS BOUNDED OR NOT STILL I IS LESS THAN STRING 
    // SIZE OR NOT
    //THEN IN NEXT STEP IT IS CHECK THAT ISDIGIT OR NOT THAT THE 
    // STRING AT THERE CHARACTER IS DIGIT OR NOT 
    while(i<s.size() && isdigit(s[i])){
        //IN CHARACTERS WITH ALL CHARACTERS THERE ARE 1 ASCII VALUE 
        // WHICH IS ASSOCIATED ALWAYS 
        // In C++ (and many other programming languages), 
        // characters are internally represented by their ASCII values,
        //  which are integers. When you perform arithmetic operations 
        // involving characters and integers, 
        // the character’s ASCII value is used in the calculation.
        //AND WE USE S[I]-'0' SO THAT CORRECT VALUE OF NUMBER BEING 
        // ADD NOT AN ASCII VALUE AND THIS IS WORKS

        //EDGE CASE 
        //STEP 5 - 
        //INT_MAX - 2147483647
        //INT_MIN - -2147483647
        //NOW CHECK IF CONDITION IS OUT OF BOUND THEN 
        //IF OUR NUMBER IS BIGGER THAN INT_MAX THEN RETURN INT_MAX 
        // BECAUSE IT IS OUT OF RANGE
        //OR BDA KB HOGA JB NUM 214748365 HO JAYGA TO HMNA PEHLE HI CHECK 
        // KR LIYA DIVIDE BY 10 KRKE YEH HMARI PEHLI CONDITION HOGI
        //THEN  2ND CONDITION - AGR LOOP INT_MAX/10 KE BRABAR HO JATA 
        // 214748364 TK TOH USI TIME RETURN KRDO KYUKI USKE BAAD BHI 
        // OUT OF BOUND JAYGA
        //THEN 3RD CONDITION - MERA 214748364 AAGA 7 TK TO MUJHE ALLOWED HAI 
        // OUT OF BOUND TO TAB HOGA NA JAB
        //7 SE BDA HOGA ESLIYE EK OR CONDITION S[I]>'7' DLEGI
        //THIS IS CALLED SPECIAL HANDLING
        if((num > INT_MAX/10) || ((num==INT_MAX/10) && (s[i]>'7') )){
            //ESMA BHI 1 CATCH HAI  AGR SIGN  -1 HAI TO HMA RETURN KRNA PDEGA -1 ELSE +1
            return (sign==-1)?INT_MIN:INT_MAX;
        }
        num = num * 10 + (s[i] - '0');
        i++;
    }

    //STEP 4 - RETURN NUM WITH SIGN;
    return num*sign;

}
int main(){
    string s;
    getline(cin,s);
    int ans = myAtoi(s);
    cout<<ans<<endl;
    return 0;
}
// 42
//      -042
// 13337c0d3
//0-1
//words and 987