class Solution {
    public boolean isValid(String s) {
        Stack<Character>st = new Stack<>();
        for(char ch : s.toCharArray()){
            if(ch=='(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else if(ch == '}' ||  ch == ']' || ch == ')'){
                if(st.isEmpty()) return false;
                else if((ch == ')' && st.peek()!= '(') || (ch == ']' && st.peek() != '[') || (ch == '}' && st.peek()!= '{') ){
                    return false;
                }
                st.pop();
            }
        }
        if(!st.isEmpty()) return false;
        return true;
    }
}
