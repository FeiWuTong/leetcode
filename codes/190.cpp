/*
 * Approach: bit-manipulation
 * Time complexity: O(log2(n))   || 100.00% (0 ms)
 * Space complexity: O(1)  || 100.00% (6.1 MB)
 * Note: make ret bit by bit
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, bitpos = 31;
        while (n != 0) {
            ret |= (n & 1) << bitpos;
            n >>= 1;
            bitpos--;
        }
        return ret;
    }
};
/*
 * Approach: byte-manipulation
 * Time complexity: O(log256(n))   || 50.59% (4 ms)
 * Space complexity: O(1)  || 100.00% (6.3 MB)
 * Note: byte-reverse is key and hard point, with a cache (256-size) can do this repeatedly
 * Note: byte-reverse reference -- http://graphics.stanford.edu/~seander/bithacks.html#ReverseByteWith64BitsDiv
 */
class Solution {
private:
    unordered_map<uint32_t, uint32_t> cache;
    uint32_t reverseByte(uint32_t byte) {
        if (cache.count(byte)) return cache[byte];
        cache[byte] = (byte * 0x0202020202 & 0x010884422010) % 1023;
        return cache[byte];
    }
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, bytepos = 24;
        while (n != 0) {
            ret |= reverseByte(n & 0xff) << bytepos;
            n >>= 8;
            bytepos -= 8;
        }
        return ret;
    }
};
/*
 * Approach: divide and conquer
 * Time complexity: O(1)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 100.00% (5.9 MB)
 * Note: use mask and shift bits without loop (log2(32) times)
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // swap 16-bits part, 8-bits part and so on (1-bit complete)
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};