/*
Concept Used:
Sliding Window + Frequency Array.
Algorithm:
1. Create a frequency array of size 26 for A-Z.
2. Initialize left = 0, maxFreq = 0, maxLength = 0.
3. Move right pointer through the string.
4. Increase the frequency of s[right].
5. Update maxFreq with the highest frequency seen.
6. Calculate replacements needed:
   window size - maxFreq.
7. If replacements needed > k:
   - Decrease frequency of s[left].
   - Move left one step forward.
8. Update maxLength using the current window size.
9. Return maxLength.
Time Complexity: O(n)
Space Complexity: O(1), because the frequency array
always contains 26 elements.
*/
class Solution{
    public:
    int characterReplacement(string s, int k){
        vector<int> freq(26,0);
        int left = 0;
        int maxFreq=0;
        int maxLength=0;
        for (int right =0; right <s.size(); right++){
            freq[s[right]-'A']++;
            maxFreq= max(maxFreq,freq[s[right]-'A']);
            while ((right-left+1)- maxFreq>k){
                freq[s[left]-'A']--;
                left++;
        }
        maxLength=max(maxLength,right-left+1);
    }
    return maxLength;
}
};
//formula used here : window size - highest frequency = replacement neeeded !! 
