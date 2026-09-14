class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0;
        int j = 0;
        while(i<g.size() && j<s.size()){
            if(s[j] >= g[i]){
                count++;
                i++;
                j++;
            }
            else j++;
        }
        return count;
    }
};



// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         int count = 0;
//         int mn = min(g.size(), s.size());
//         for(int i=0; i<mn; i++){
//             if(s[i] >= g[i]) count++;
//         }
//         return count;
//     }
// };



// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         int count = 0;
//         int idx = -1;
//         for(int i=0; i<s.size(); i++){
//             if(s[i] >= g[0]){
//                 idx = i;
//                 break;
//             }
//         }
//         if(idx == -1) return 0;
//         int i = 0;
//         int j = idx;
//         while(i<g.size() && j<s.size()){
//             if(s[j] >= g[i]) count++;
//             i++;
//             j++;
//         }
//         return count;
//     }
// };