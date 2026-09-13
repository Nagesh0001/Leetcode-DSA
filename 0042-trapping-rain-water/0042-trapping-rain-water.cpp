// //.Brute Force Approach (Time Limit Exceeded)
// class Solution{
// public:
//     int trap(vector<int>& he){
//         int n = he.size();
//         int w = 0;
//         for(int i=0; i<n; i++){
//             int mL = 0, mR = 0;
//             for(int j=0; j<=i; j++){
//                 mL = max(mL, he[j]);
//             }
//             for(int j=i; j<n; j++){
//                 mR = max(mR, he[j]);
//             }
//             w += min(mL, mR) - he[i];
//         }
//         return w;
//     }
// };




//.Two Pointer Optimized Solution
class Solution {
public:
    int trap(vector<int>& he) {
        int l = 0, r = he.size() - 1;
        int lM = 0, rM = 0, w = 0;
        while(l <= r){
            if(he[l] < he[r]){
                if(he[l] >= lM) lM = he[l];
                else w += lM - he[l];
                l++;
            } else{
                if(he[r] >= rM) rM = he[r];
                else w += rM - he[r];
                r--;
            }
        }
        return w;
    }
};
