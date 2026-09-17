// //.Brute Force Approach. T.C :- O(N^2). S.C :- O(N^2). T.L.E
// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         vector<string> ans;
//         for(int i = 0; i <= s.size() - 10; i++) {
//             string sub = s.substr(i, 10);
//             int count = 0;
//             for(int j = 0; j <= s.size() - 10; j++) {
//                 if(s.substr(j, 10) == sub)
//                     count++;
//             }
//             // count aur sub yahin available hain
//             if(count > 1) {
//                 bool alreadyPresent = false;
//                 for(string x : ans) {
//                     if(x == sub) {
//                         alreadyPresent = true;
//                         break;
//                     }
//                 }
//                 if(!alreadyPresent)
//                     ans.push_back(sub);
//             }
//         }
//         return ans;
//     }
// };


//.Optimised Approach - Hash set. T.C :- O(N). S.C :- O(N)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        for(int i = 0; i + 10 <= s.size(); i++) {
            string sub = s.substr(i, 10);
            if(seen.count(sub)) {
                repeated.insert(sub);
            }
            else {
                seen.insert(sub);
            }
        }
        vector<string> ans;
        for(string sub : repeated) {
            ans.push_back(sub);
        }
        return ans;
    }
};