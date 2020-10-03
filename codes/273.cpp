/*
 * Approach: No
 * Time complexity: O(n)   || 55.08% (8 ms)
 * Space complexity: O(n)  || 89.12% (6.3 MB)
 */
class Solution {
private:
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string toWords(int n) {
        if (n >= 1000000000) {
            return toWords(n / 1000000000) + " Billion" + toWords(n % 1000000000);
        } else if (n >= 1000000) {
            return toWords(n / 1000000) + " Million" + toWords(n % 1000000);
        } else if (n >= 1000) {
            return toWords(n / 1000) + " Thousand" + toWords(n % 1000);
        } else if (n >= 100) {
            return toWords(n / 100) + " Hundred" + toWords(n % 100);
        } else if (n >= 20) {
            return " " + tens[n / 10] + toWords(n % 10);
        } else if (n >= 1) {
            return " " + digits[n];
        } else {
            return "";
        }
    }
public:
    string numberToWords(int num) {
        return num ? toWords(num).substr(1) : "Zero";
    }
};