class Solution {
public:
    bool check(int capacity, vector<int>& weights, int days) {
        int count = 1;
        int load = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(load + weights[i] <= capacity) {
                load += weights[i];
            }
            else {
                count++;
                load = weights[i];
            }
        }
        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxWeight = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(maxWeight < weights[i])
                maxWeight = weights[i];
            sum += weights[i];
        }
        int lo = maxWeight;
        int hi = sum;
        int minCapacity = sum;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(check(mid, weights, days)) {
                minCapacity = mid;
                hi = mid - 1;   // Capacity kam karke dekhte hain
            }
            else {
                lo = mid + 1;    // Capacity badhani padegi
            }
        }
        return minCapacity;
    }
};