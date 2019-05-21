#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include <stack>
#include <string>


using namespace std;

bool getSign(string exp, int x) {
    if (x == 0)
        return true;
    if (exp[x - 1] == '-')
        return false;
    return true;
};

bool isBalanced(string exp) {
    stack<char> st;
    char ch;
    char temp;

    for (int i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];
        if (ch == '{' || ch == '[' || ch == '(') {
            st.push(ch);
        } else if (ch == '}' || ch == ']' || ch == ')') {
            if (st.size() == 0) {
                return false;
            }

            temp = st.top();
            st.pop();
            if (
                    (ch == ')' && (temp == '{' || temp == '[')) ||
                    (ch == '}' && (temp == '(' || temp == '[')) ||
                    (ch == ']' && (temp == '(' || temp == '{'))
                    ) {
                return false;
            }
        }
    }

    return st.empty();
}

void addIntoMap(string exp, map<char, int> &m, bool add) {
    stack<bool> st;
    st.push(true);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '+' || exp[i] == '-') {
            continue;
        }

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {

            if (getSign(exp, i))
                st.push(st.top());
            else
                st.push(!st.top());
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
            st.pop();

        else {
            if (m.find(exp[i]) == m.end()) {

                if (st.top()) {
                    m.insert(make_pair(exp[i],
                                       (getSign(exp, i) ? add ? 1 : -1 :
                                        add ? -1 : 1)));
                } else {
                    m.insert(make_pair(exp[i], (getSign(exp, i) ? add ? -1 : 1 :
                                                add ? 1 : -1)));
                }
            } else {
                int temp;
                if (st.top()) {
                    temp = m.at(exp[i]);
                    temp += (getSign(exp, i) ? add ? 1 : -1 :
                             add ? -1 : 1);
                } else {
                    temp = m.at(exp[i]);
                    temp += (getSign(exp, i) ? add ? -1 : 1 :
                             add ? 1 : -1);
                }
                m.find(exp[i])->second = temp;
            }
        }
    }
}

string solveNumber(string exp) {
    stack<bool> st;
    st.push(true);
    string rt;
    int total = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '+' || exp[i] == '-') {
            rt += exp[i];
            continue;
        } else if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            rt += exp[i];
            if (getSign(exp, i))
                st.push(st.top());
            else
                st.push(!st.top());
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            rt += exp[i];
            st.pop();
        } else if (exp[i] >= 48 && exp[i] <= 57) {
            if (st.top()) {
                total += (getSign(exp, i) ? 1 : -1) * (exp[i] - 48);
            } else {
                total += (getSign(exp, i) ? -1 : 1) * (exp[i] - 48);
            }
            if (i > 0 && (exp[i - 1] == '+' || exp[i - 1] == '1'))
                rt.pop_back();

        } else {
            rt += exp[i];
        }
    }
    rt = rt + (total >= 0 ? "+" : "") + to_string(total);
    return rt;
}

bool isEquivalent(string exp1, string exp2) {
    exp1 = solveNumber(exp1);
    exp2 = solveNumber(exp2);
    map<char, int> m;
    addIntoMap(exp1, m, true);

    addIntoMap(exp2, m, false);

    map<char, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second != 0) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {

//     Incorrect Usage
    if (argc < 2) {
        cout << "Usage: evalexpr \"input=<file>;output=<file>\"" << endl;
        return -1;
    }

    ArgumentManager am(argc, argv);

    string input = am.get("input");
    string output = am.get("output");

    ifstream file1(input.c_str());
    ofstream file2(output.c_str());

    if (!file1 || !file2) {
        cout << "error";
        return -1;
    }

    string exp;
    bool isValid = true;
    bool compareExp = true;
    bool allEquivalent = true;
    string prevExp = "";
    int i = 0;
    while (getline(file1, exp)) {
        if (exp.length() == 0) {
            continue;
        }
        i++;
        cout << exp << endl;
        isValid = isBalanced(exp);
        if (!isValid) {
            file2 << "Error at: " << i << endl;
            compareExp = false;
        }

        if (prevExp.length() != 0 && compareExp && allEquivalent) {
            allEquivalent = isEquivalent(exp, prevExp);
        }
        prevExp = exp;
    }

    if (compareExp) {
        file2 << (allEquivalent ? "Yes" : "No") << endl;
    }

    return 0;
}