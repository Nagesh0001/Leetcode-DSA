// //.Brute Force Approach T.C = O(n X M), S.C = O(1)
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>ans;
//         for(int i=0; i<nums1.size(); i++){
//             int index = -1;
//             for(int j=0; j<nums2.size(); j++){
//                 if(nums2[j] == nums1[i]){
//                     index = j;
//                     break;
//                 }
//             }
//             int next = -1;
//             for(int j=index+1; j<nums2.size(); j++){
//                 if(nums2[j] > nums1[i]){
//                     next = nums2[j];
//                     break;
//                 }
//             }
//             ans.push_back(next);
//         }
//         return ans;
//     }
// };



//.Optimise Approach T.C = O(n X m), S.C = O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty())
            mp[nums2[i]] = -1;
            else
            mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int num : nums1){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};