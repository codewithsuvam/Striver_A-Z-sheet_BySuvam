class Solution{
    public:
    vector<vector<string>> groupAnagrams(vector<string>&strs){
        unordered_map<string,vector<string>>mp;
        for (string s: strs){
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        
        }
        vector<vector<string>> result;
        for (auto& entry:mp){
            result.push_back(entry.second);
        }
        return result;
    }
};

//algo for this solution in 6 steps 
//1.Create a hash map to store groups of anagrams.
//2.Pick each string from the given array and sort its characters.
//3.Use the sorted string as a key in the hash map.
//4.Add the original string to the group corresponding to that key. If the key already exists, add it to the existing group.
//5.After processing all strings, store all the groups in a result vector.
//6.Return the result vector.