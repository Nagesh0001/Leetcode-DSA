// //.Brute Force Approach. T.C :- O(nlog(n)), S.C :- O(1)
// class Solution {
// public:
//    bool isAnagram(string s, string t) {
//        sort(s.begin(),s.end());
//        sort(t.begin(),t.end());
//        return (s==t);
//    }
// };


//.Better Approach. T.C :- O(n), S.C :- O(n)
class Solution {
public:
   bool isAnagram(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        if(n1!=n2) return false;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(auto ch:s)
        {
           m1[ch-'a']++;
        }
        for(auto ch:t)
        {
           m2[ch-'a']++;
        }
        return (m1==m2);
   }
};


// //.Better Approach T.C :- O(n), S.C :- O(1)
// class Solution {
// public:
//    bool isAnagram(string s, string t) {
//         int n1=s.length();
//         int n2=t.length();
//         if(n1!=n2) return false;
//         int count[26]={0};
//         for(int i=0;i<n1;i++)
//         {
//             count[s[i]-'a']++;
//             count[t[i]-'a']--;
//         }
//         for(int i=0;i<26;i++)
//         {
//            if(count[i]!=0) return false;
//         }
//         return true;
//    }
// };