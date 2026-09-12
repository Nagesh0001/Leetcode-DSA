//.Sliding Window + Frequency Array
class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int n = s.length();
        int l = 0, r = 0;
        int mL = 0;
        vector<int> freq(256, 0);
        while(r < n){
            freq[s[r]]++;
            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }
            mL = max(mL, r - l + 1);
            r++;
        }
        return mL;
    }
};





// //.Sliding Window + Hash Map
// class Solution{
// public:
//     int lengthOfLongestSubstring(string s){
//         int n = s.length();
//         int l = 0, r = 0;
//         int mL = 0;
//         unordered_map<char, int> mp;
//         while(r < n){
//             mp[s[r]]++;
//             while(mp[s[r]] > 1){
//                 mp[s[l]]--;
//                 l++;
//             }
//             mL = max(mL, r - l + 1);
//             r++;
//         }
//          return mL;
//     }
// };
