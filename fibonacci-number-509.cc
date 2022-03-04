class Solution {
public:
    int fib(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 0) {
            return 0;
        }
        int res = 0;
        int a = 1; // F(n-1)
        int b = 0; // F(n-2)
        while (--n) {
            res = a + b;
            b = a;
            a = res;
        }
        return res;
    }
};
