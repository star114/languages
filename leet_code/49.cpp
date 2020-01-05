/*
https://leetcode.com/problems/group-anagrams
This code runs well in leetcode.com
To compile this file locally, you may need some addtional prerequisite like including headers,
setting up testing environments, ...

49. Group Anagrams

Description:

    Given an array of strings, group anagrams together.

    Example:

    Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
    Output:
    [
    ["ate","eat","tea"],
    ["nat","tan"],
    ["bat"]
    ]
    Note:

    All inputs will be in lowercase.
    The order of your output does not matter.

Solution:
    Intuition:
        Two strings are anagrams if and only i their character counts are the same.
    Algorithm:
        We can transform each string s into a character count, consisting of 26 non-negative integers
        representing number of a's, b's, c's... We use these counts as the key for hash map.
    Complexity:
        N is the number of strings, and K is the maximum length of the string.
        Time: O(N*K)
        Space: O(N*K)

Submissions:
    Success

    Details
    Runtime: 196 ms, faster than 5.08% of C++ online submissions for Group Anagrams.
    Memory Usage: 68.7 MB, less than 5.97% of C++ online submissions for Group Anagrams.
*/

class Solution {
public:
    // Two string are anagrams if and only if their character counts are the same.
    // We can transform each string s into a character count, consisting of 26 non-negative integers representing number of a's, b's, c's... We use these counts as the key for hash map.
    string getHashableRepresentation(unordered_map<int, int>& wordCount)
    {
        stringstream ss;
        for (int i = 0; i < 26; ++i) {
            ss << "#" << wordCount[i];
        }
        return ss.str();
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        // starts to count each strings: O(number of strings)
        for (auto& str : strs) {
            unordered_map<int, int> wordCount; // counting object
            // count each string: O(max string length)
            for (auto& c : str) {
                wordCount[(c-'a')]++;
            }
            ans[getHashableRepresentation(wordCount)].push_back(str); // O(1) for hash map
        }

        vector<vector<string>> groups;
        // build return vectors: O(1) ~ 26 constant number iteration
        for (auto& [_, value] : ans) {
            groups.push_back(value);
        }
        return groups;
    }
};
