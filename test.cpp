#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<array>
#include<bitset>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<string.h>
using namespace std;

// Solution class here
class Solution {
private:
    int counts(vector<int>& arr, int n) {
        if (n <= 0) return 1;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % n == 0 || n % arr[i] == 0) {
                swap(arr[i], arr[n-1]);
                ret += counts(arr, n - 1);
                swap(arr[n-1], arr[i]);
            }
        }
        return ret;
    }
public:
    int countArrangement(int N) {
        vector<int> arr(N);
        for (int i = 0; i < N; i++) arr[i] = i + 1;
        return counts(arr, N);
    }
};

int main() {
    // begin test
    // cout << Solution().nextPermutation() << endl;
    // string s = "a good   example";
    //vector<vector<int>> points = {{40,-23},{9,138},{429,115},{50,-17},{-3,80},{-10,33},{5,-21},{-3,80},{-6,-65},{-18,26},{-6,-65},{5,72},{0,77},{-9,86},{10,-2},{-8,85},{21,130},{18,-6},{-18,26},{-1,-15},{10,-2},{8,69},{-4,63},{0,3},{-4,40},{-7,84},{-8,7},{30,154},{16,-5},{6,90},{18,-6},{5,77},{-4,77},{7,-13},{-1,-45},{16,-5},{-9,86},{-16,11},{-7,84},{1,76},{3,77},{10,67},{1,-37},{-10,-81},{4,-11},{-20,13},{-10,77},{6,-17},{-27,2},{-10,-81},{10,-1},{-9,1},{-8,43},{2,2},{2,-21},{3,82},{8,-1},{10,-1},{-9,1},{-12,42},{16,-5},{-5,-61},{20,-7},{9,-35},{10,6},{12,106},{5,-21},{-5,82},{6,71},{-15,34},{-10,87},{-14,-12},{12,106},{-5,82},{-46,-45},{-4,63},{16,-5},{4,1},{-3,-53},{0,-17},{9,98},{-18,26},{-9,86},{2,77},{-2,-49},{1,76},{-3,-38},{-8,7},{-17,-37},{5,72},{10,-37},{-4,-57},{-3,-53},{3,74},{-3,-11},{-8,7},{1,88},{-12,42},{1,-37},{2,77},{-6,77},{5,72},{-4,-57},{-18,-33},{-12,42},{-9,86},{2,77},{-8,77},{-3,77},{9,-42},{16,41},{-29,-37},{0,-41},{-21,18},{-27,-34},{0,77},{3,74},{-7,-69},{-21,18},{27,146},{-20,13},{21,130},{-6,-65},{14,-4},{0,3},{9,-5},{6,-29},{-2,73},{-1,-15},{1,76},{-4,77},{6,-29}};
    //vector<vector<int>> points = {{1,1},{1,1},{0,0},{3,4},{4,5},{5,6},{7,8},{8,9}};
    //vector<vector<int>> points = {{1,4},{1,1},{4,1},{5,3},{2,3},{3,2}};
    //vector<int> nums = {1,1,5,-3,-3,-3,-3,-3,-3,-3};
    vector<int> a = {1,2,3,4,5,10,6,7,8,9};
    int k = 5;
    cout << Solution().countArrangement(8) << endl;
    //vector<int> nums = {1,1,1,1,1,1,1,5,3,3,3,3,3,3,3};
    //cout << Solution().singleNumber(nums) << endl;
    //int direct[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    //for (auto t : Solution().restoreIpAddresses(s)) cout << t << endl;
    /*
    Solution().nextPermutation(nums);
    for (auto i : nums) cout <<i<<",";
    cout <<endl;
    */

    system("pause");
}