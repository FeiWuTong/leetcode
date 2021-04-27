/*
 * Approach: multiset(Tree) (elegant)
 * Time complexity: O(nlogn)   || 62.70% (72 ms)
 * Space complexity: O(n)  || 27.61% (16.7 MB)
 * Note: Straight-forward solution is for every building, we traverse all other buildings to find whether exists a larger height
 * Note: which take O(n^2)... But indeed, we just need to traverse all boundary point and add/del it or find height in O(logn), by using a sorted multiset / heap
 */
/*
 * a left point in, insert its height; a right point in, erase its height
 * find max height from multiset at current point and use it as current point's height
 * For multiset can delete a height in O(logn) easily, and access max height in O(1)
 */
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // 1: boundary points record and sort, negative height means left, O(nlogn)
        multiset<pair<int, int>> bp;
        for (auto b : buildings) {
            // why left is negative? (can try to use positive, what happen?) think of 0-2 | 2-5 with same height 3
            // for multiset is ascending, if we use positive, we will encounter 2(right) before 2(left)
            // then at position 2 we will fall to 0 at first, then rise to 3, which is unnecessary
            bp.emplace(make_pair(b[0], -b[2]));
            bp.emplace(make_pair(b[1], b[2]));
        }
        // 2: multiset to maintain the current set of height
        //    `cur` to record current height and its left point, which can be push into result
        multiset<int> heights = {0}; // (right point fall to) ground, never erase
        vector<int> cur = {0, 0};
        vector<vector<int>> ret;
        // 3: traverse all points, O(nlogn)
        for (auto p : bp) {
            if (p.second < 0) heights.emplace(-p.second);
            else heights.erase(heights.find(p.second));
            // once the height change, we push that change point and update height
            if (*heights.rbegin() != cur[1]) {
                cur[0] = p.first;
                cur[1] = *heights.rbegin();
                ret.push_back(cur);
            }
        }
        return ret;
    }
};
/*
 * Approach: map (same as above, but traverse all building 1 time)
 * Time complexity: O(nlogn)   || 97.78% (44 ms)
 * Space complexity: O(n)  || 85.22% (13.2 MB)
 * Note: map is also a r-b trie, this solution just move step by step,
 * Note: and devide it into right part (in map) and left part (final part in while) to deal with
 * Note: this code exist a lot of repeative (or unnecessary) part
 */
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // mp->first = x, mp->second = y (or height), map is ascending ordered
        map<int, int> mp;
        vector<vector<int>> ans;
        int idx = 0;

        // map only save right boundary point
        while (idx < buildings.size() || !mp.empty()) {
            // time to deal with the right points (in map) when fall to ground (0) or platform
            if (!mp.empty() && (idx == buildings.size() || mp.begin()->first < buildings[idx][0])) {
                auto it = mp.begin();
                auto jt = next(it);
               
                int x0 = it->first;
                // if `it` is the "last" point in map, height is 0 to fall to ground, or fall to the platform (jt)
                int h  = (jt == mp.end() ? 0 : jt->second);
               
                mp.erase(it, jt);
                // first push_back or not equal to previous height
                if (ans.empty() || ans.back()[1] != h) {
                    ans.push_back(vector<int>{x0, h});
                }
            } else {
                int x0 = buildings[idx][0];
                int x1 = buildings[idx][1];
                int h  = buildings[idx][2];
               
                auto it = mp.find(x1);
                
                // a new right boundary point, save it 
                if (it == mp.end()) {
                    auto status = mp.insert({x1, h});
                    auto nt     = next(status.first);
                   
                    it = status.first;

                    // exist righter point, update this point's height
                    if (nt != mp.end()) {
                        it->second = max(h, nt->second);
                    }
                } else {
                    // if exist right boundary point, update its max height
                    it->second = max(it->second, h);
                }
               
                int mx = it->second;
                
                // not the leftmost right point, deal with its previous lower height points (erase)
                if (it != mp.begin()) {
                    auto jt = prev(it);
                    while (jt != mp.begin() && jt->second <= mx) {
                        --jt;
                    }

                    if (jt->second > mx) ++jt;
                    else if (jt == mp.begin() && jt->second <= mx) {
                        jt = mp.begin();
                    }

                    mp.erase(jt, it);
                }

                // get current height and deal with left point (push or not push)
                h = mp.begin()->second;
                // if exist same x before, update x's height (this part is use to deal with duplicate overlay)
                if (!ans.empty() && ans.back()[0] == x0) {
                    ans.back()[1] = max(ans.back()[1], h);
                }
                // first push_back or not same height as previous
                else if (ans.empty() || ans.back()[1] != h) {
                    ans.push_back(vector<int>{x0, h});
                }                    
                ++idx;
            }
        }
        return ans;
    }
};