// variable size window - jisme agr aap xyz condition koi satisfy krwana chahta hai 
// variable size - 10 / 20 / 30 / 40 / 50 / 60 / 70

// find a valid answer 
// valid answer vala case ke andar mein window ko minimize kr rah hota
// hu eska matlab start ko aaga bdana or end ko kam krna taaki hmara pass 
// ek valid answer aa jay

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin>>v[i];
     
    return 0;
}