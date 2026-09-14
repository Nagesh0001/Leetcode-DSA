// //.Reverse Array logic
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         reversePart(0, n - k - 1, nums);
//         reversePart(n - k, n - 1, nums);
//         reversePart(0, n - 1, nums);
//     }
//     void reversePart(int i, int j, vector<int>& v) {
//         while(i <= j) {
//             int temp = v[i];
//             v[i] = v[j];
//             v[j] = temp;
//             i++;
//             j--;
//         }
//     }
// };





class Solution {
public:
    void reversePart(vector<int>& nums, int i, int j) {
        while(i<j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reversePart(nums, 0, n - 1);
        reversePart(nums, 0, k - 1);
        reversePart(nums, k, n - 1);
    }
};
