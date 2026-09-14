// //.Brute Force Approach
// class Solution {
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//        //int l;
//         int count = 0;
//         int n = nums1.size();
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 for(int k=0; k<n; k++){
//                     for(int l=0; l<n; l++){
//                         if(nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0){
//                         count++;
//                         }
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };




//.Hash Map + Two Sum technique
class Solution{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4){
        int n = nums1.size();
        unordered_map<int, int> m;
        int x, y;
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                x = nums1[i] + nums2[j];
                m[x]++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                y = nums3[i] + nums4[j];
                count += m[-y];
            }
        }
        return count;
    }    
};
