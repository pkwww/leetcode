#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int app(int first_i, int second_i, string token) {
        if (token == "+") {
            return first_i + second_i;
        } else if (token == "-") {
            return first_i - second_i;
        } else if (token == "*") {
            return first_i * second_i;
        } else {
            return first_i / second_i;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                int result = app(first, second, token);
                s.push(result);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
