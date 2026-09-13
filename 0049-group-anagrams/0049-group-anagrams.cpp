//.Brute Force Approach
class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        map<string, vector<string>> m;
        for(auto &s : strs){
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &pair : m){
            ans.push_back(pair.second);
        }
        return ans;
    }
};







// //.Two Pointer Approach
// class Solution{
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs){
//         vector<pair<string, string>> v;
//         for(auto &s : strs){
//             string t = s;
//             sort(t.begin(), t.end());
//             v.push_back({t, s});
//         }
//         sort(v.begin(), v.end());
//         vector<vector<string>> ans;
//         int i = 0;
//         while(i < v.size()){
//             vector<string> group;
//             int j = i;
//             while(j < v.size() && v[j].first == v[i].first){
//                 group.push_back(v[j].second);
//                 j++;
//             }
//             ans.push_back(group);
//             i = j;
//         }
//         return ans;
//     }
// };
