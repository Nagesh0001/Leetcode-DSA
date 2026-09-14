//.Using difference mapping
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> v(150, 1000);
        // s -> t mapping
        for(int i=0; i<s.length(); i++){
            int idx = (int)s[i];
            if(v[idx] == 1000) v[idx] = s[i] - t[i];
            else if(v[idx] != (s[i] - t[i])) return false;
        }
        // reset vector for t -> s mapping
        for(int i=0; i<150; i++) v[i] = 1000;
        for(int i=0; i<s.length(); i++){
            int idx = (int)t[i];
            if(v[idx] == 1000) v[idx] = t[i] - s[i];
            else if(v[idx] != (t[i] - s[i])) return false;
        }
        return true;
    }
};




// //.Using character mapping
// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if(s.length() != t.length()) return false;
//         unordered_map<char, char> mapST;
//         unordered_map<char, char> mapTS;
//         for(int i=0; i<s.length(); i++){
//             if(mapST.count(s[i]) && mapST[s[i]] != t[i]) return false;
//             if(mapTS.count(t[i]) && mapTS[t[i]] != s[i]) return false;
//             mapST[s[i]] = t[i];
//             mapTS[t[i]] = s[i];
//         }
//         return true;
//     }
// };