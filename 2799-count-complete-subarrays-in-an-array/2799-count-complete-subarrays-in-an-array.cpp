//.Brute Force Approach. T.C :- O(N² log N). S.C :- O(N)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        set<int> total;
        for (int x : nums) {
            total.insert(x);
        }
        int totalDistinct = total.size();
        for (int i = 0; i < n; i++) {
            set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                if (st.size() == totalDistinct) {
                    ans++;
                }
            }
        }
        return ans;
    }
};