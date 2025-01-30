class Solution {
    fun topKFrequent(nums: IntArray, k: Int): IntArray {
        var myMap = mutableMapOf<Int, Int>()
        for (num in nums) {
            myMap[num] = myMap.getOrDefault(num, 0) + 1
            
        }
        var pq = PriorityQueue<Pair<Int, Int>>(compareBy{ it.first })
        myMap.forEach { key, value ->
            if (pq.size < k){
                pq.add(Pair(value, key))
            } else {
                val (lastval, lastkey) = pq.poll()
                if (lastval < value){
                    pq.add(Pair(value, key))
                } else {
                    pq.add(Pair(lastval, lastkey))
                }

            }
        }
        val res = IntArray(k)
        var i = 0
        while (pq.size > 0){
            res[i] = pq.poll().second
            i++
        }
        return res
    }
}