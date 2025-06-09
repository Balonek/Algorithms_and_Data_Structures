#include <iostream>
#include <string>
#include <cctype>  
#include "ArrayStack.hpp"

using namespace std;

int priorytet(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixToPostfix(string s) {
    ArrayStack stack; 
    string result;

    for (std::string::size_type i = 0; i < s.length(); i++) { 
        char c = s[i];

        if (isspace(c)) continue;

        if (isdigit(c)) {
            while (i < s.length() && isdigit(s[i])) {
                result += s[i++];
            }
            result += " "; 
            i--; 
        }

        else if (c == '(') {
            stack.push(c);
        }

        else if (c == ')') {
            while (!stack.empty()) {
                int temp = stack.pop();  
                if (temp == '(') {  
                    break; 
                }
                result += (char)temp;  
                result += " "; 
            }
        }

        else {
            while (!stack.empty()) {
                int topElement = stack.pop();  
                if (priorytet(c) > priorytet((char)topElement)) {
                    stack.push(topElement);  
                    break;
                }
                result += (char)topElement;  
                result += " "; 
            }
            stack.push(c);  
        }
    }

    while (!stack.empty()) {
        result += (char)stack.pop();
        result += " "; 
    }
//usuwanie ostatniej spacji 
    if (!result.empty()) {
        result.pop_back();
    }
cout << result << "" << endl;
}

int main() {
    string s;
    getline(cin, s);
    infixToPostfix(s);
    return 0;
}   
