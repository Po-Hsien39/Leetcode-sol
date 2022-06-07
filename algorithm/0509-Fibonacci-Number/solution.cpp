class Solution {
 public:
  int fib(int n) {
    if (n <= 1) return n;
    int sum1 = 1;
    int sum2 = 0;
    int res;
    for (int i = 2; i <= n; i++) {
      res = sum1 + sum2;
      sum2 = sum1;
      sum1 = res;
    }
    return res;
  }
};