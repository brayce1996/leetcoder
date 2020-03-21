// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Different Ways to Add Parentheses.
// Memory Usage: 13.4 MB, less than 83.33% of C++ online submissions for Different Ways to Add Parentheses.

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<string> exprList = parse(input);
        for (string s: exprList) {
            cout << s << " ";
        }
        cout << endl;
        
        return divideAndConquer(exprList);
    }
    
    vector<string> parse(string input) {
        vector<string> exprList;
        int intStart = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                exprList.push_back(input.substr(intStart, i - intStart));
                intStart = i + 1;
                exprList.push_back(input.substr(i, 1));
            }
        }
        exprList.push_back(input.substr(intStart, input.length()));
        return exprList;;
    }
    
    vector<int> divideAndConquer(vector<string>& exprList) {
        if (exprList.size() == 1)
            return vector<int>(1, stoi(exprList[0]));
        
        vector<int> results;
        for (int i = 1; i < exprList.size(); i += 2) {
            vector<string> frontHalf(exprList.begin(), exprList.begin() + i);
            vector<string> rearHalf(exprList.begin() + i + 1, exprList.end());
            vector<int> frontRes =  divideAndConquer(frontHalf);
            vector<int> rearRes =  divideAndConquer(rearHalf);
            for (int fr: frontRes) {
                for (int rr: rearRes) {
                    results.push_back(doOperate(fr, exprList[i], rr));
                }
            }
        }
        return results;
    }
    
    int doOperate(int a, string op, int b) {
        if (op == "+") {
            return a + b;
        } else if (op == "-") {
            return a - b;
        } else if (op == "*") {
            return a * b;
        } else cout << "something mess up." << endl;
        return 0;
    }
};