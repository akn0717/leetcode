#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    vector<int> E(n, 0);
    int global = 0;
    for (int i = 0; i < n; i++) {
      int max_e = 0;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          max_e = max(max_e, E[j]);
        }
      }
      E[i] = 1 + max_e;
      global = max(global, E[i]);
    }
    return global;
  }
};

int main() { return 0; }