//.Better Approach T.C :- O(n), S.C :- O(n)
class Solution {
public:
   string reverseWords(string s) {
       vector<string> words;
       string word = "";
       // Step 1: Traverse and extract words
       for (char c : s)
       {
           if (c != ' ')
           word += c;
           else if (!word.empty())
           {
               words.push_back(word);
               word = "";
           }
       }
       // Add the last word if any
       if (!word.empty()) {
           words.push_back(word);
       }
       // Step 2: Reverse the vector of words
       reverse(words.begin(), words.end());
       // Step 3: Join words with a single space
       string result = "";
       for (int i = 0; i < words.size(); ++i)
       {
           result += words[i];
           if (i < words.size() - 1)
           result += " ";
       }
       return result;
   }
};


// //.Best Approach T.C :- O(n) S.C :- O(1).
// class Solution {
// public:
//    string reverseWords(string s) {
//        string ans="";
//        string str="";
//        for(int i=0;i<s.length();i++)
//        {
//            if(s[i]==' ' && str!="")
//            {
//                ans=str+' '+ans;
//                str="";
//            }
//            else if(s[i]==' ')
//            continue;
//            else
//            str+=s[i];
//        }
//        if(str!="")
//        ans=str+' '+ans;
//        ans.pop_back();
//        return ans;
//    }
// };