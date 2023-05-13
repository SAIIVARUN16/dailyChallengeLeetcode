class Solution {
public:
    int f(int len,int zero,int one,vector<int>&dp){
        if(len==0) return 1;
        if(len<0) return 0;
        if(dp[len]!=-1) return dp[len];
        int zeroPick = f(len-zero,zero,one,dp)%1000000007;
        int onePick = f(len-one,zero,one,dp)%1000000007;
        return dp[len]=(zeroPick+onePick)%1000000007;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0;
        vector<int>dp(high+1,-1);
        for(int i=low;i<=high;i++){
            ans=(ans+f(i,zero,one,dp))%1000000007;
        }
        return ans;
    }
};