#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string decodestring(string s) {
    stack<string> st;
    for (auto ch : s) {
        if (ch == ']') {
            string stringtorepeat = "";
            while (!st.empty() && st.top() != "[") {
                stringtorepeat = st.top() + stringtorepeat;
                st.pop();
            }
            st.pop();  // pop '['
            string numerictime = "";
            while (!st.empty() && isdigit(st.top()[0])) {
                numerictime = st.top() + numerictime;
                st.pop();
            }
            int n = stoi(numerictime);
            string currentdecode = "";
            while (n--) {
                currentdecode += stringtorepeat;
            }
            st.push(currentdecode);
        } else {
            string temp(1, ch);
            st.push(temp);
        }
    }
    string ans;
    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}

int main() {
    string st = "3[a]2[bc]";
    cout << st << endl;
    string result = decodestring(st);
    cout << result << endl;
    return 0;
}