class Solution {
 public:
      int mod = 1337;
        // 计算 a 的 k 次方然后与 mod 求模的结果
    int mypow(int a, int k) {
            int base = a % mod, res = 1;
        // 注意这里的取模
        while (k != 0) {
                  if  (k & 1) {
                        res = (res * base) % mod;
                    
      }
                  base = (base * base) % mod;
                  k >>= 1;
              
    }
            return res;
        
  }
      int superPow(int a, vector<int> & b) {
            if  (b.empty()) return 1;
            int last = b.back();
            b.pop_back();
            
        int part1 = mypow(a, last);
            int part2 = mypow(superPow(a, b), 10);
              // 每次乘法都要求模
        return (part1 * part2) % mod;
        
  }
};