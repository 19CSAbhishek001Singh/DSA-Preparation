class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res=0,n=nums.size();
        // for(int i=1;i<=n;i++){
        //     if(n%i==0){
        //         res+=(nums[i-1]*nums[i-1]);
        //     }
        // }
        for(int i=0;i<n;i++){
            if(n%(i+1)==0) {
                res+= nums[i]*nums[i];
            }
        }
        return res;
    }
};