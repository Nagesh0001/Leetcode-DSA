// //.Three Pointer Approach (Dutch Flag Algorithm)
//  T C:- O(n + m), S C:- O(n + m)
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m - 1;      // last element of nums1's original part
//         int j = n - 1;      // last element of nums2
//         int k = m + n - 1;  // last position in nums1
//         while(i >= 0 && j >= 0){
//             if(nums1[i] > nums2[j]){
//                 nums1[k] = nums1[i];
//                 i--;
//             }
//             else{
//                 nums1[k] = nums2[j];
//                 j--;
//             }
//             k--;
//         }
//         while(j >= 0){
//             nums1[k] = nums2[j];
//             j--;
//             k--;
//         }
//     }
// };




//.Two Pointer Approach   T C:- O(n + m),  S C:- O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Last index of the original part of nums1
        int j = n - 1;      // Last index of nums2
        int k = m + n - 1;  // Last index of nums1 (full size)
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};