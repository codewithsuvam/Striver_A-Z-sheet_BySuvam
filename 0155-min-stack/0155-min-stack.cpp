// Algo covers in 5 steps and concept of this question is Stack + Auxiliary Stack
// 1. Create one stack to store all values and another stack to track the minimum at each level.
// 2. On push, add the value to the main stack and push the smaller of the new value and current minimum onto the minimum stack.
// 3. On pop, remove the top element from both stacks.
// 4. On top, return the top element of the main stack.
// 5. On getMin, return the top element of the minimum stack.
// here is the code of this question 
class MinStack {
private:
stack <int> st;
stack <int> minStack;
public :
MinStack(){

}
void push (int val){
    st.push(val);
    if (minStack.empty()){
        minStack.push(val);
    }
    else {
        minStack.push(min(val,minStack.top()));

    }
    }
    void pop(){
        st.pop();
        minStack.pop();
    }
    int top(){
        return st.top();

    }
    int getMin(){
        return minStack.top();
    }
};

//time complexity: O(1) each operation performs a constant no. of stack operations ! 


