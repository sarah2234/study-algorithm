class Solution {
public:
    string to_lower_copy(const string &s) {
        string tmp = s;
        transform(tmp.begin(), tmp.end(), tmp.begin(),
                  [](unsigned char c){ return tolower(c); });
        return tmp;
    }

    string devowel(const string &s) {
        string tmp = to_lower_copy(s);
        for (char &c : tmp) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                c = '*';  
        }
        return tmp;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        for (auto &w : wordlist) {
            string lower = to_lower_copy(w);
            string dev = devowel(w);

            if (!caseInsensitive.count(lower)) caseInsensitive[lower] = w;
            if (!vowelInsensitive.count(dev)) vowelInsensitive[dev] = w;
        }

        vector<string> ans;
        for (auto &q : queries) {
            if (exact.count(q)) {  
                ans.emplace_back(q);
            } else {
                string lower = to_lower_copy(q);
                string dev = devowel(q);

                if (caseInsensitive.count(lower)) { 
                    ans.emplace_back(caseInsensitive[lower]);
                } else if (vowelInsensitive.count(dev)) { 
                    ans.emplace_back(vowelInsensitive[dev]);
                } else {
                    ans.emplace_back("");
                }
            }
        }
        return ans;
    }
};
