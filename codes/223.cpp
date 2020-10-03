/*
 * Approach: No
 * Time complexity: O(n)   || 97.31% (4 ms)
 * Space complexity: O(n)  || 38.95% (6.1 MB)
 */
class Solution {
private:
    int common(int A, int B, int C, int D) {
        if (A > D || B < C) return 0;
        if (A < C) return min(B - C, D - C);
        else return min(B - A, D - A);
    }
    int area(int A, int B, int C, int D) {
        return (C - A) * (D - B);
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return area(A, B, C, D) - common(A, C, E, G) * common(B, D, F, H) + area(E, F, G, H);
    }
};