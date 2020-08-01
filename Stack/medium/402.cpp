class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = ""; // use string to simulate a stack structure
        
        for (int i = 0; i < num.size(); i += 1) {
            while (!res.empty() && num[i] < res.back() && k > 0) {
                res.pop_back();
                k -= 1;
            }
            
            res.push_back(num[i]);
        }
        
        // if k is not consumed, erase last k char
        res.erase(res.size() - k, string::npos);
        
        // erase leading zeros
        for (int i = 0; i < res.size(); i += 1) {
            if (i == res.size() - 1 || res[i] != '0') {
                res = res.substr(i);
                break;
            }
        }
        
        return (res == "")? "0":res ;
    }
};
