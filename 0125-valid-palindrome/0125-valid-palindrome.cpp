//.Brute Force Approach. T.C :- O(n), S.C :- O(n)
class Solution {
public:
   bool isPalindrome(string s) {
        int n=s.length();
        string str1="";
        for(auto ch:s)
        {
            if(isalnum(ch))
            str1+=tolower(ch);
        }
        string str2=str1;
        reverse(str1.begin(),str1.end());
        return (str1==str2);
   }
};


// //.Best Approach. T.C :- O(n), S.C :- O(1)
// class Solution {
// public:
//    bool isPalindrome(string s) {
//         int n=s.length();
//         int low=0;
//         int high=n-1;
//         while(low<high)
//         {
//            if(!isalnum(s[low]))
//            low++;
//            else if(!isalnum(s[high]))
//            high--;
//            else if(tolower(s[low])==tolower(s[high]))
//            {
//                low++;
//                high--;
//            }
//            else
//            return false;
//         }
//         return true;
//    }
// };