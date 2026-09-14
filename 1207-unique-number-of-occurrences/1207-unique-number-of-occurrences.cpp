class Solution{
public:
    bool uniqueOccurrences(vector<int>& arr){
        unordered_map<int,int>mp;
        unordered_set<int>st;
        for(int num : arr){
            mp[num]++;
        }
        for(auto it : mp){
            if(st.find(it.second) != st.end()){
                return false;
            }
            st.insert(it.second);
        }
        return true; 
    }
};