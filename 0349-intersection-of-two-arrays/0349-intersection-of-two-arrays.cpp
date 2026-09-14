//.Brute Force Approach + Marking approach
class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            int flag = 0;
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    if(flag == 0){
                        ans.push_back(nums1[i]);
                    }
                    flag = 1;
                    nums2[j] = -1; 
                }
            }
        }
        return ans;
    }
};





// //.Set Based Intersection Approach
// class Solution{
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
//         set<int> s;
//         vector<int> ans;
//         for(int i=0; i<nums2.size(); i++)
//             s.insert(nums2[i]);
//             for(int i=0; i<nums1.size(); i++){
//                 if(s.count(nums1[i]) != 0){
//                 ans.push_back(nums1[i]);
//                 s.erase(nums1[i]);
//             }
//         }
//         return ans;
//     }
// };