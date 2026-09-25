// //.Brute Force Approach. T.C :- O(n^2). T.L.E
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxWater = 0;
//         for(int i=0; i<height.size(); i++){
//             for(int j=i+1; j<height.size(); j++){
//                 int w = j - i;
//                 int ht = min(height[i], height[j]);
//                 int carrWater = w * ht;
//                 maxWater = max(maxWater, carrWater);
//             }
//         }
//         return maxWater;
//     }
// };


//.Optimised Approach -> TWO POINTER. T.C :- O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp = 0, rp = height.size() - 1;
        while(lp < rp){
            int w = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currWater = w * ht;
            maxWater = max(maxWater, currWater);
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};