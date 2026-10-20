// Algo covers in 5 steps and concept of this question is Stack + LIFO + Matching Brackets
// 1. Create an empty stack to store opening brackets.
// 2. Traverse each character of the string from left to right.
// 3. If an opening bracket is found, push it onto the stack.
// 4. If a closing bracket is found, check whether the stack is empty or its top does not match; if so, return false. Otherwise, pop the matching opening bracket.
// 5. After traversing the string, return true only if the stack is empty.
class Solution{
    public:
    bool isValid(string s ){
        stack<char>st;
        //string traverse 
        for (char c: s){
            //push opening brackets 
         if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else{
            //stack is empty then its invalid 
            if (st.empty()){
                return false;
            }
            //to find out the top element 
            char top= st.top();
            st.pop();
            //for checking the matching 
             if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                        return false;
        }
    }
}

return st.empty();
    }
};

// time complexity is O(n) we traverse the string once processing each character at most once 