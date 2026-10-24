// Algo covers in 5 steps and concept of this question is Fixed Size Sliding Window + Frequency Array.
// 1. If s1 is longer than s2, return false because permutation is impossible.
// 2. Create two frequency arrays of size 26 to store character counts of s1 and the current window of s2.
// 3. Count the frequencies of s1 and the first window of s2. If both arrays match, return true.
// 4. Slide the window one character at a time:
//    - Add the new character entering the window.
//    - Remove the character leaving the window.
// 5. After each slide, compare both frequency arrays. If they match, return true. If no match is found, return false.
// time complexity is O(n)
//space complexity is O(1)
class Solution{
    public:
    bool checkInclusion(string s1,string s2){
        if (s1.size()>s2.size()){
            return false;
        }
        vector<int>s1Count(26,0);
        vector<int>windowCount(26,0);
        for (int i = 0; i < s1.size(); i++){
            s1Count[s1[i]-'a']++;
            windowCount[s2[i]-'a']++;
        }
        if (s1Count == windowCount){
            return true;
        }
        for (int right = s1.size();right<s2.size();right++ ){
            windowCount[s2[right]-'a']++;
            windowCount[s2[right-s1.size()]-'a']--;
            if (s1Count == windowCount){
                return true ;

            }
        }
        return false;
    }
};
