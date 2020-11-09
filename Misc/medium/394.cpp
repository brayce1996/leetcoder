class Solution {
public:
    string decodeString(string s) {
        string result;
        int lastIndex;
        tie(result, lastIndex) = decodeString(s, 0);

        return result;
    }

    tuple<string, int> decodeString(string s, int start) {
        if (start >= s.size()) return make_tuple("", start);

        string result = "";
        int curr;
        for (curr = start; curr < s.size(); ++curr) {
            if (isdigit(s[curr])) {
                // parse repeat num, stop at '['
                int repeatNum = 0;
                while (isdigit(s[curr])) {
                    repeatNum = repeatNum*10 + (s[curr] - '0');
                    curr++;
                }


                string subResult;
                tie(subResult, curr) = decodeString(s, curr+1);
                for (int j = 0; j < repeatNum; ++j) {
                    result += subResult;
                }
            } else if (s[curr] == ']') {
                break;
            } else {
                result += s[curr];
            }

        }
        return make_tuple(result, curr);
    }
};
