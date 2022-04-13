## Questions Solutions :-

* `last-stone-weight` - https://leetcode.com/problems/last-stone-weight/discuss/360047/Super-Simple-O(N)-Java-Solution-using-bucket-sort-and-two-pointers :-> `Could be done using priority queue in O(NlogN) also`
<hr>

* `kth-largest-element-in-a-stream` - https://leetcode.com/problems/kth-largest-element-in-a-stream/solution/ 
    * The Solultion uses min-heap to keep track of k largest element, it pops initial elements first to always have k size elements. This approach appers to be faster than max heap as copy need not be created of priority queue.

<hr>

* Heap custom sort condition function
    ``` auto comp = [&mp](int n1, int n2){return mp[n1]>mp[n2];};
        priority_queue<int,vector<int>,decltype(comp)> heap(comp);
        
        for(pair<int,int> p: mp){
            heap.push(p.first);
            if (heap.size() > k) heap.pop();
        }
    ```

<hr>

* `top-k-frequent-elements`  - https://leetcode.com/problems/top-k-frequent-elements/discuss/81676/C%2B%2B-O(nlogk)-and-O(n)-solutions 

* `maximum-product-after-k-increments` - https://leetcode.com/problems/maximum-product-after-k-increments/discuss/1931054/C++-oror-Easy-Solution-Using-Min-Heap/1344431