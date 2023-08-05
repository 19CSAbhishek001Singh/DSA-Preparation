class Solution {
public:
    int longestConsecutive(vector<int>& ar) {
      unordered_set<int> s;
      for(int x:ar){
          s.insert(x);
      }
      int longestStreak=0;
      for(int nums:ar){
          if(!s.count(nums-1)){
              int currNumber=nums;
              int currStreak=1;
              while(s.count(currNumber+1)){
                  currNumber+=1;
                  currStreak+=1;
              }
              longestStreak=max(longestStreak,currStreak);
          }
      }
      return longestStreak;
    }
};