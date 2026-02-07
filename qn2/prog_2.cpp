#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int checkboss(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string mkpostfix(string input_str) {
    stack<char> s1;
    string final_p = "";
    for (int i = 0; i < input_str.length(); i++) {
        char ch = input_str[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            final_p += ch;
        } else if (ch == '(') {
            s1.push('(');
        } else if (ch == ')') {
            while (!s1.empty() && s1.top() != '(') {
                final_p += s1.top();
                s1.pop();
            }
            if (!s1.empty()) s1.pop();
        } else {
            while (!s1.empty() && checkboss(ch) <= checkboss(s1.top())) {
                final_p += s1.top();
                s1.pop();
            }
            s1.push(ch);
        }
    }
    while (!s1.empty()) {
        final_p += s1.top();
        s1.pop();
    }
    return final_p;
}

int calculate_now(string post_str) {
    stack<int> s2;

    for (int i = 0; i < post_str.length(); i++) {
        char ch = post_str[i];

        if (ch >= '0' && ch <= '9') {

            s2.push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (s2.size() < 2) continue; 


            int b = s2.top(); s2.pop();
            int a = s2.top(); s2.pop();
            if (ch == '+') s2.push(a + b);

            else if (ch == '-') s2.push(a - b);
            else if (ch == '*') s2.push(a * b);
            else if (ch == '/') {
                if (b != 0) s2.push(a / b);
                else s2.push(0); 
            }
            else if (ch == '^') s2.push(pow(a, b));
        }
    }

    if (s2.empty()) return 0;
    return s2.top();

}

int main() {
    string user_input;
    cout << "enter expression: ";
    cin >> user_input;
    string result_p = mkpostfix(user_input);
    cout << "postfix: " << result_p << endl;
    
    
    int final_result = calculate_now(result_p);
    cout << "result: " << final_result << endl;
    return 0;
}
