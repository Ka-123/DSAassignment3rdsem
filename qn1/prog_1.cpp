#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isitgoood(string someletters) {
    stack<char> thisstack;
    for (int i = 0; i < someletters.length(); i++) {
        char currentthing = someletters[i];
        if (currentthing == '(' || currentthing == '[' || currentthing == '{') {
            thisstack.push(currentthing);
        } else if (currentthing == ')' || currentthing == ']' || currentthing == '}') {
            if (thisstack.empty()) {
                return false;
            }
            char toplittlething = thisstack.top();
            if ((currentthing == ')' && toplittlething == '(') ||
                (currentthing == ']' && toplittlething == '[') ||
                (currentthing == '}' && toplittlething == '{')) {
                thisstack.pop();
            } else {
                return false;
            }
        }
    }
    return thisstack.empty();
}

int main() {
    string math1 = "a+(b-c)*(d";
    string math2 = "m+[a-b*(c+d*{m)]";
    string math3 = "a+(b-c)";

    cout << "Expression: " << math1 << endl;
    if (isitgoood(math1)) {
        cout << "It is balanced" << endl;
    } else {
        cout << "It is not balanced" << endl;
    }

    cout << "\nExpression: " << math2 << endl;
    if (isitgoood(math2)) {
        cout << "It is balanced" << endl;
    } else {
        cout << "It is not balanced" << endl;
    }

    cout << "\nExpression: " << math3 << endl;
    if (isitgoood(math3)) {
        cout << "It is balanced" << endl;
    } else {
        cout << "It is not balanced" << endl;
    }

    return 0;
}
