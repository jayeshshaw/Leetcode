class Solution {
public:
    string largestWordCount(vector<string>& msg, vector<string>& senders) {
        unordered_map<string, int> m;
        string res;
        int mx = 0;
        for (int i = 0; i < msg.size(); ++i) {
            int words = count(begin(msg[i]), end(msg[i]), ' ') + 1;
            int total = m[senders[i]] += words;
            if (total > mx || (total == mx && senders[i] > res)) {
                mx = total;
                res = senders[i];
            }
        }
        return res;
    }
};