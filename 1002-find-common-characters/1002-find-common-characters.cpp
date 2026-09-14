//.Brute Force Approach (Simple thinking)
class Solution{
public:
    vector<string> commonChars(vector<string>& words){
        vector<string> ans;
        for(int i=0; i<words[0].size(); i++){
            char ch = words[0][i];
            bool found = true;
            for(int j=1; j<words.size(); j++){
                int pos = words[j].find(ch);
                if(pos == string::npos){
                    found = false;
                    break;
                }
            }
            if(found){
                ans.push_back(string(1, ch));
                for(int j=1; j<words.size(); j++){
                    int pos = words[j].find(ch);
                    words[j].erase(pos, 1);
                }
            }
        }
        return ans;
    }
};




// //.Frequency Count + Minimum Intersection
// class Solution{
// public:
//     vector<string> commonChars(vector<string>& words){
//         vector<int> minFreq(26, INT_MAX);
//         for(int i=0; i<words.size(); i++){
//             vector<int> freq(26, 0);
//             string s = words[i];
//             for(int j=0; j<s.length(); j++){
//                 freq[s[j] - 'a']++;
//             }
//             for(int k=0; k<26; k++){
//                 minFreq[k] = min(minFreq[k], freq[k]);
//             }
//         }
//         vector<string> ans;
//         for(int i=0; i<26; i++){
//             while(minFreq[i] > 0){
//                 ans.push_back(string(1, char(i + 'a')));
//                 minFreq[i]--;
//             }
//         }
//         return ans;
//     }
// };
