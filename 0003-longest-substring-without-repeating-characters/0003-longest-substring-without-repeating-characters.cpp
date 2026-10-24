 /*
        Concept Used:
        Sliding Window + Hash Set.
        Algorithm:
        1. Initialize left = 0 and maxLength = 0.
        2. Traverse the string using right pointer.
        3. If s[right] is already in the window:
           - Remove s[left] from the set.
           - Increment left until the duplicate is removed.
        4. Insert s[right] into the set.
        5. Update maxLength = max(maxLength, right - left + 1).
        6. Return maxLength.
        Time Complexity: O(n)
        Each character is added to and removed from the set
        at most once.
        Space Complexity: O(min(n, charset))
        The set stores unique characters in the current window.
        */ 
class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        unordered_set<char> window;
        int left=0;
        int maxLength=0;
        for (int right = 0; right <s.size();right ++){
            //important code line 
            while (window.count(s[right])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            maxLength=max(maxLength, right-left+1);
        }
        return maxLength;
    }
};
