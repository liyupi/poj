// http://poj.org/problem?id=1028
// 栈的应用，别想太复杂
#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<string> mstack;
stack<string> forStack;

int main() {
    string instr;
    string url;
    mstack.push("http://www.acm.org/");
    while(cin >> instr && instr != "QUIT") {
        if (instr == "VISIT") {
            cin >> url;
            mstack.push(url);
            while(!forStack.empty()) {
                forStack.pop();
            }
            cout << url << endl;
        } else if (instr == "BACK") {
            if (mstack.size() < 2) {
                cout << "Ignored" << endl;
            } else {
                forStack.push(mstack.top());
                mstack.pop();
                cout << mstack.top() << endl;
            }
        } else if (instr == "FORWARD") {
            if (forStack.empty()) {
                cout << "Ignored" << endl;
            } else {
                cout << forStack.top() << endl;
                mstack.push(forStack.top());
                forStack.pop();
            }
        }
    }
    return 0;
}