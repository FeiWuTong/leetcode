/*
 * Approach: Backtrack
 * Time complexity:  --    || 60.21%
 * Space complexity: --    || 100.00% (9.4MB)
 * Note: below ver is quicker but not concise
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        backTrack(res, candidates, tmp, target, 0);
        return res;
    }
private:
    void backTrack(vector<vector<int>>& res, vector<int>& candidates, 
    vector<int>& tmp, int target, int begin) {
        if (!target) res.push_back(tmp);
        else {
            for (int i = begin; i < candidates.size() && candidates[i] <= target; i++) {
                tmp.push_back(candidates[i]);
                backTrack(res, candidates, tmp, target-candidates[i], i);
                tmp.pop_back();
            }
        }
    }
};
/*
 * Approach: Backtrack
 * Time complexity:  --    || 100.00%
 * Space complexity: --    || 100.00% (9.1M which illustrates backtrack times has been reduced)
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        // no needed for sorting in this problem
        vector<int> tmp;
        backTrack(res, candidates, tmp, target, 0);
        return res;
    }
private:
    void backTrack(vector<vector<int>>& res, vector<int>& candidates, 
    vector<int>& tmp, int target, int begin) {
        if (target < 0) return;
        if (!target) res.emplace_back(tmp);
        else {
            for (int i = begin; i < candidates.size(); i++) {
                // reduce times of recursion
                int count = 0;
                for (int j = candidates[i]; j <= target; j += candidates[i], count++) {
                    tmp.emplace_back(candidates[i]);
                }
                for(; count > 0; count--) {
                    backTrack(res, candidates, tmp, target-count*candidates[i], i+1);
                    tmp.pop_back();
                }
            }
        }
    }
};