/*
 * Approach: STL
 * Time complexity: O(nlogk)   || 84.50% - 71.05% (16 - 20 ms)
 * Space complexity: O(1)  || 67.03% - 40.83% (9.9 - 10.1 MB)
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // partition (quicksort)
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<>());
        return nums[k-1];
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // heap
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<>());
        return nums[k-1];
    }
};
/*
 * Approach: min-heap
 * Time complexity: O(nlogk)   || 24.80% (40 ms)
 * Space complexity: O(k)  || 19.41% (10.3 MB)
 * Note: we don't need to partial_sort, we just need to maintain the largest k elements in a min-heap
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min-heap (O(nlogk))
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int& num : nums) {
            // push spend a lot of time
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
/*
 * Approach: max-heap
 * Time complexity: O(n + klogn)   || 71.05% (20 ms)
 * Space complexity: O(n)  || 14.21% (10.4 MB)
 * Note: we don't need to partial_sort, we just need to maintain the largest k elements in a min-heap
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // max-heap (heapify O(n))
        priority_queue<int> pq(nums.begin(), nums.end());
        // O(klogn)
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
/** how to implement heap on our own */
/*
 * Approach: max-heap
 * Time complexity: O(n + klogn)   || 84.50% (16 ms)
 * Space complexity: O(1)  || 61.43% (10 MB)
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        for (int i = 0; i < k - 1; i++) {
            // equal to pop
            swap(nums[0], nums[--heapSize]);
            maxHeapify(nums, 0);
        }
        return nums[0];
    }
private:
    int heapSize;
    
    int left(int i) {
        return (i << 1) + 1;
    }
    
    int right(int i) {
        return (i << 1) + 2;
    }
    
    void maxHeapify(vector<int>& nums, int i) {
        int largest = i, l = left(i), r = right(i);
        if (l < heapSize && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest);
        }
    }
    
    void buildMaxHeap(vector<int>& nums) {
        heapSize = nums.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; i--) {
            maxHeapify(nums, i);
        }
    }
};
/** how to implement partition (quicksort) on our own */
/*
 * Approach: partition (quicksort)
 * Time complexity: O(n^2)   || 71.05% (20 ms) / without shuffle 164 ms
 * Space complexity: O(n)  || 14.88% (10.3 MB)
 * Note: with shuffle and without shuffle are different, especially in worst case
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        shuffle(nums);
        int left = 0, right = nums.size() - 1, kth;
        while (true) {
            int idx = partition(nums, left, right);
            if (idx == k - 1) {
                kth = nums[idx];
                break;
            }
            if (idx < k - 1) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }
        return kth;
    }
private:
    void shuffle(vector<int>& nums) {
        srand(time(NULL));
        int n = nums.size();
        for (int i = 0; i < n >> 1; i++) {
            swap(nums[rand()%n], nums[rand()%n]);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};