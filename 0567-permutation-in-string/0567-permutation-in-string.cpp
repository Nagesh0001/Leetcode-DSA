// //.Brute Force Approach. T.C :- O((m-n)*nlog(n)), S.C :- O(n)
// class Solution {
// public:
//    bool checkInclusion(string s1, string s2) {
//        int n = s1.size();
//        int m = s2.size();
//        if (n > m) return false;
//        sort(s1.begin(), s1.end());
//        for (int i = 0; i <= m - n;i++){
//            string temp = s2.substr(i, n);
//            sort(temp.begin(), temp.end());
//            if (temp == s1) return true;
//        }
//        return false;
//    }
// };


// //.Better Approach. T.C :- O(n*m), S.C :- O(m)
// class Solution {
// public:
// bool isAnagram(string& a, string& b) {
//        int count[26] = {0};
//        for (char c : a) count[c - 'a']++;
//        for (char c : b) count[c - 'a']--;
//        for (int i = 0; i < 26; i++)
//            if (count[i] != 0)
//                return false;
//        return true;
// }
// bool checkInclusion(string s1, string s2) {
//        int n = s2.size(), m = s1.size();
//        if (m > n) return false; // Edge case
//        for (int i = 0; i <= n - m; i++){
//            string sub = s2.substr(i, m);
//            if (isAnagram(sub, s1)) {
//                return true;
//            }
//        }
//        return false;
//    }
// };


//.Best Approach. T.C :- O(n2), S.C :- O(1)
class Solution {
public:
   bool checkInclusion(string s1, string s2) {
       int n1=s1.length();
       int n2=s2.length();
       if(n1>n2) return false;
       vector<int>count1(26,0);
       vector<int>count2(26,0);
       for(int i=0;i<n1;i++){
           count1[s1[i]-'a']++;
           count2[s2[i]-'a']++;
       }
       if(count1==count2) return true;
       int j=0;
       for(int i=n1;i<n2;i++){
           count2[s2[i]-'a']++;
           count2[s2[j]-'a']--;
           if(count1==count2) return true;
           j++;
       }
       return false;
   }
};

