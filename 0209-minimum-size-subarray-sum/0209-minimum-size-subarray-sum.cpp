class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
         int n=nums.size();
        deque<pair<long long,long long>>dq;
        long long sum=0;
        long long shortest=INT_MAX;
        for(long long i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=k) shortest=min(shortest,i+1);
            // reduce the window
            pair<long long,long long> curr={INT_MIN,INT_MIN};
            // sum>=k try to reduce from the front side
            while(!dq.empty()&& (sum-dq.front().first>=k)){
                curr=dq.front();
                dq.pop_front();
            }
            if(curr.second!=INT_MIN){
                shortest=min(shortest,(i-curr.second));
            }
            // if current sum less than the last sum pop 
            // untill it becomes greater
            while(!dq.empty() && sum<=dq.back().first){
                dq.pop_back();
            }
            // store current sum with index
            dq.push_back({sum,i});
        }
        return shortest==INT_MAX?0:shortest;
        
        
        /*
         int n = nums.size();
        int left = 0; // left pointer
        int right = 0; // right pointer
        int sum = 0; // we will keep adding sum here
        int ans =INT_MAX; // we are going to store the mininum window size from all
        while(right < n){
            sum += nums[right];
            // We will keep adding sum untill it is greater than target
            if(sum >= target){
                // here we are trying to shrink the size of the window
                // to check is window could be made smaller
               while(sum >= target){
                   sum -= nums[left];
                left++;
               }
                ans = min(ans,right-left+2);
        // right - left+2 is done because when the loop will break sum would have been 
        // smaller than target so we need to include the previous index also
              }
            right++;
        }
        if(ans == INT_MAX) return 0;
        return ans;
        */
        
    }
};