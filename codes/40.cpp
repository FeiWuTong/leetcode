/*
 * Approach: Backtrack (same as 39)
 * Time complexity:  --    || 100.00%
 * Space complexity: --    || 100.00% (8.8MB << 9.2M)
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        backTrack(res, candidates, tmp, target, 0);
        return res;
    }
private:
    void backTrack(vector<vector<int>>& res, vector<int>& candidates, 
    vector<int>& tmp, int target, int begin) {
        if (!target) res.emplace_back(tmp);
        else {
            for (int i = begin; i < candidates.size(); i++) {
                if (i > begin && candidates[i] == candidates[i-1]) continue;
                if (candidates[i] > target) return;
                tmp.emplace_back(candidates[i]);
                backTrack(res, candidates, tmp, target-candidates[i], i+1);
                tmp.pop_back();
            }
        }
    }
};