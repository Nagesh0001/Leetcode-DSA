//.Brute Force Approach. T.C :- O(1). S.C :- O(1)
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flush = true;
        for (int i = 1; i < 5; i++) {
            if (suits[i] != suits[0]) {
                flush = false;
                break;
            }
        }
        for (int i = 0; i < 5; i++) {
            int count = 0;
            for (int j = 0; j < 5; j++) {
                if (ranks[i] == ranks[j]) {
                    count++;
                }
            }
            if (count >= 3)
                return "Three of a Kind";
        }
        if (flush)
            return "Flush";
        for (int i = 0; i < 5; i++) {
            int count = 0;
            for (int j = 0; j < 5; j++) {
                if (ranks[i] == ranks[j]) {
                    count++;
                }
            }
            if (count >= 2)
                return "Pair";
        }
        return "High Card";
    }
};


// //.Optimised / Iterative Approach. T.C :- O(1). S.C :- O(1)  
// class Solution {
// public:
//     string bestHand(vector<int>& ranks, vector<char>& suits) {
//         unordered_map<int, int> mp;
//         for (int rank : ranks) {
//             mp[rank]++;
//         }
//         for (auto it : mp) {
//             if (it.second >= 3) {
//                 return "Three of a Kind";
//             }
//         }
//         bool flush = true;
//         for (int i = 1; i < 5; i++) {
//             if (suits[i] != suits[0]) {
//                 flush = false;
//                 break;
//             }
//         }
//         if (flush) {
//             return "Flush";
//         }
//         for (auto it : mp) {
//             if (it.second >= 2) {
//                 return "Pair";
//             }
//         }
//         return "High Card";
//     }
// };