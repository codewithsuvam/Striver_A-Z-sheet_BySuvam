// Concept: Monotonic Increasing Stack
// 1. Traverse the histogram from left to right and store bar indices in a stack.
// 2. Maintain increasing bar heights in the stack.
// 3. When the current height is smaller than the height at the stack's top,
//    pop that index because its maximum rectangle's right boundary is found.
// 4. Calculate width using the current index and the new stack top.
//    If the stack is empty, width = current index; otherwise,
//    width = current index - stack.top() - 1.
// 5. Calculate area = popped bar height * width and update maxArea.
// 6. Process an extra height of 0 at the end to calculate areas for all
//    remaining bars. Return maxArea.
//here is the code of this question 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() &&
                   heights[st.top()] > currHeight) {

                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                int area = height * width;
                maxArea = max(maxArea, area);
            }

            if (i < n) {
                st.push(i);
            }
        }

        return maxArea;
    }
};
// time complexity is O(n) Each bar index is pushed onto the stack once and popped at most once. Therefore, the total number of stack operations is linear in the number of bars.