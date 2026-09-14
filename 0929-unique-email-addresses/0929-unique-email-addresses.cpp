//.String Parsing + Hash Set 
class Solution{
public:
    int numUniqueEmails(vector<string>& emails){
        unordered_set<string> st;
        for(int i=0; i<emails.size(); i++){
            string e = emails[i];
            string s = "";
            bool plus = false;
            int j = 0;
            while(j<e.size() && e[j] != '@'){
                if(e[j] == '+'){
                    plus = true;
                }
                if(!plus && e[j] != '.'){
                    s += e[j];
                }
                j++;
            }
            while(j < e.size()){
                s += e[j];
                j++;
            }
            st.insert(s);
        }
        return st.size();
    }
};





// //.Two Pointer Approach
// class Solution{
// public:
//     int numUniqueEmails(vector<string>& emails){
//         unordered_set<string> st;
//         for(int i=0; i<emails.size(); i++){
//             string e = emails[i];
//             string s = "";
//             int l = 0, r = 0;
//             bool plus = false;
//             while(r < e.size() && e[r] != '@'){
//                 if (e[r] == '+') {
//                     plus = true;
//                 }
//                 if(!plus && e[r] != '.'){
//                     s += e[r];
//                 }
//                 r++;
//             }
//             while(r < e.size()){
//                 s += e[r];
//                 r++;
//             }
//             st.insert(s);
//         }
//         return st.size();
//     }
// };
