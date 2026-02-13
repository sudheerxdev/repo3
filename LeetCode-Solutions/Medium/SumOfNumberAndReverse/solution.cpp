class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        string str_num = to_string(num);
       // int numlen = str_num.length();
       if(num == 0){
        return true;
       }
        for(int i = num ; i > 0 ;i--){
            string str1 = to_string(i);

            string revstr1 = str1;
            reverse(revstr1.begin() , revstr1.end());
            if(stoi(str1) + stoi(revstr1)==num){
                return true;
            }
        }
        return false;
    }
};
