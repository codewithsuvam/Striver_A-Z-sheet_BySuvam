//algo covers in 6 steps and concept of this question is Two Pointers + String Manipulation
// 1. Initialize two pointers at the beginning and end of the string.
// 2. Skip non-alphanumeric characters from both sides.
// 3. Convert both characters to lowercase and compare them.
// 4. If the characters don't match, return false.
// 5. If they match, move both pointers towards the center.
// 6. If all valid characters match, return true.
class Solution{
public: 
bool isPalindrome(string s){
    int left=0;
    int right= s.size()-1;
    while (left<right){
        if (!isalnum(s[left])){
            left++;
        }
        else if(!isalnum(s[right])){
            right--;
        }
        else{
            if (tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
    }
    return true;
}
};