import java.util.Map;
import java.util.HashMap;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        for (int i=0; i<nums.length; i++){
            int find = target - nums[i];
            if (hm.get(find) != null){
                int[] ret = {hm.get(find), i};
                return ret;
            } else {
                hm.put(nums[i], i);
            }
        }
        int[] ret = {-1, -1};
        return ret;
    }
}