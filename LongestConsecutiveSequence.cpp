/*

Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence. 
Example: Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4. 
Your algorithm should run in O(n) complexity.
×

*/

int Solution::longestConsecutive(const vector<int> &nums) {
    
    unordered_set<int> s(nums.begin(), nums.end());
        int maxSeq = 0;
        for(long i : nums){
            if(s.count(i - 1) > 0)
                continue;            
            int curSeq = 0;
            while(s.count(i++) > 0)
                curSeq++;
            maxSeq = max(maxSeq, curSeq);
        }
        return maxSeq;
}
