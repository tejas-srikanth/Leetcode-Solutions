class Solution {
    public int[] productExceptSelf(int[] nums) {
        int prefSums[] = new int[nums.length];
        int res[] = new int[nums.length];
        int s = 1;
        for (int i=0; i<nums.length; i++){
            s *= nums[i];
            prefSums[i] = s;
        }

        s = 1;
        for (int i=nums.length-1; i>0; i--){
            res[i] = prefSums[i-1] * s;
            s *= nums[i];
        }
        res[0] = s;
        return res;
        
    }
}