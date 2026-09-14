// //.Brute Force Approach T.C = O(n^2), S.C = O(n)
// class Solution{
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
//         stack<int> st;
//         int j = 0;
//         for(int i=0; i<pushed.size(); i++){
//             st.push(pushed[i]);
//             while(!st.empty() && j<popped.size() && st.top() == popped[j]){
//                 st.pop();
//                 j++;
//             }
//         }
//         return st.empty();
//     }
// };



//.Optimize Approach T.C = O(n), S.C = O(n)
class Solution{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
        stack<int>st;
        int j = 0;
        for(int i=0; i<pushed.size(); i++){
            st.push(pushed[i]);
            while(!st.empty() && j<popped.size() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};