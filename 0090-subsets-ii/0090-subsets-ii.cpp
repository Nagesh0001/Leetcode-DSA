class Solution {
public:
    void storeSubset(string ans, string original, vector<string>& v, bool flag) {
        if(original == "") {
            v.push_back(ans);
            return;
        }
        char ch = original[0];
        if(original.length() == 1) {
            if(flag == true)
                storeSubset(ans + ch, original.substr(1), v, true);
            storeSubset(ans, original.substr(1), v, true);
            return;
        }
        char dh = original[1];
        if(ch == dh) {
            if(flag == true)
                storeSubset(ans + ch, original.substr(1), v, true);
            storeSubset(ans, original.substr(1), v, false);
        }
        else {
            if(flag == true)
                storeSubset(ans + ch, original.substr(1), v, true);
            storeSubset(ans, original.substr(1), v, true);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        string str = "";
        for(int x : nums)
            str += char(x + '0');
        vector<string> v;
        storeSubset("", str, v, true);
        vector<vector<int>> ans;
        for(string s : v) {
            vector<int> temp;
            for(char ch : s)
                temp.push_back(ch - '0');
            ans.push_back(temp);
        }
        return ans;
    }
};