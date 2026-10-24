// Algo covers in 6 steps and concept of this question is Sliding Window + Frequency Map.
// 1. Store the required frequency of every character in t.
// 2. Initialize left = 0, required = number of unique required characters,
//    formed = 0, and variables to store the minimum window.
// 3. Expand the window by moving right and update the frequency of the current character.
// 4. If a required character reaches its required frequency, increase formed.
// 5. When formed == required, the window is valid:
//    - Update the minimum window if the current window is smaller.
//    - Shrink the window from the left.
//    - If removing a character makes its frequency insufficient, decrease formed.
// 6. Continue until right reaches the end. Return the minimum substring,
//    or an empty string if no valid window exists.
//time complexity O(n+m) where n=s.size() and m=t.size() both pointers forward each char. is processed a limited no of times 
//space complexity O(1) becoz the frequency array has a fixed size of  128 
class Solution {
    public:
    string minWindow(string s, string t){
        // if t is longer than s a valid window is impossible 
        if (t.size()>s.size()){ 
            return "";
        }
        vector<int> need(128,0);
        for (char c : t){
            need[c]++;
        }
        int left = 0;
        int required = t.size();
        int minLength = INT_MAX; 
        int start = 0;
        for (int right = 0; right < s.size(); right ++){
            if (need[s[right]]>0){
                required--;

            }
            need[s[right]]--;
            while (required ==0){
                int windowLength = right - left +1 ;
                if (windowLength<minLength){
                    minLength=windowLength;
                    start = left ;
                }
                need [s[left]]++;
                if ( need [s[left]]>0){
                    required++;
                }
                left++;
            }
        }
        return minLength == INT_MAX
         ? ""
          : s.substr(start,minLength);
    }
};