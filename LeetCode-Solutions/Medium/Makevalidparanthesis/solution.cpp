class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int open = 0, insertion = 0;
        for(char ch : s){
            if(ch == '('){
                open++;
            }
            else{
                if(open > 0){
                    open --;
                }
                else{
                    insertion ++;
                }
            }
        }
        return open + insertion;
        
    }
};
