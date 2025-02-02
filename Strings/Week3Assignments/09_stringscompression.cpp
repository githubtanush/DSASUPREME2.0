#include<iostream>
#include<string>
#include<vector>
using namespace std;
//string compression also known as run length encoding best algorithm to compression the string
int compress(vector<char>& s){
    //  int index = 0;//string mein compress krke save krne ka liye
        // int count = 1;//count ka track rkhna ka liye
        // char prev = s[0]; // to match the string by using two pointers
    //ek mein index rkhunga jo track rkhega ki kitna length ki hogyi string
    //Think like two pointer approach
    int index = 0;
    //count variable track rkhne ke liye ki kitne same element hai 
    //count ko 1 se initialize krna
    int count = 1;
    //prev match krna ke liye i se taaki track rkhne mein asani ho 
    char prev = s[0];
    for(int i = 1; i < s.size();i++){
        if(s[i]==prev){
            //When curr and prev pointer are same
            count++;
        }
        else{
            //when they are different then 
            //matlab counting puri ho gyi matlab ab hm character ko insert kr skte hai 
            //so s[index++] = prev;
            s[index++] = prev;
            //if count==1 then hma print nhi krna 
            //but agar count>1 hai to hme insert krna krna hai after inserting character in array 
            if(count>1){
                //yeh start esliye taaki jab hm answer nikalanga to hmara answer glt aayga 
                //to usko reverse krne ke liye sahi position hai this is play important role
                int start = index;
                //jab tak count 0 nhi ho jata tab tak 
                while(count){
                    s[index++] = (count%10) + '0';
                    count /= 10;
                }
                reverse(s.begin()+start,s.begin()+index);

            }
            //prev ko s[i] ke brabar krdo or count ko phir se 1 krdo 
            prev = s[i];
            count = 1;
        }
    }
    //jab i out of bound ho jay then i ke index ko phir se prev ko do and again repeat that steps 
        s[index++] = prev;
        if(count>1){
            int start = index;
            while(count){
                s[index++] = ( count % 10 ) + '0';
                count /= 10;
            }
            reverse(s.begin()+start,s.begin()+index);
        }
        return index;
}
int main(){
    vector<char> s;
    int n;
    cin>>n;
    s.resize(n);
    for(int i = 0; i < n;i++){
        cin>>s[i];
    }
    int ans = compress(s);
    cout<<"After compressing the string size is : "<<ans<<endl;

    return 0;
}
// 7
// a a b b c c c 
               
// 13
// a a a a a a a a a a a a a