// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_set<int>s;
//         for(int val : nums){
//             if(s.find(val) != s.end()){
//                 return val;
//             }
//             s.insert(val);
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int findDuplicate(vector<int>& arr) {
       int slow = arr[0], fast = arr[0];
       do{
        slow = arr[slow];
        fast = arr[arr[fast]];
       }while(slow != fast);
       slow = arr[0];
       while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
       }
       return slow;
    }
};