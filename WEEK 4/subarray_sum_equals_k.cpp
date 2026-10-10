#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;

    prefixCount[0] = 1;

    int prefixSum = 0;
    int count = 0;

    for (int num : nums) {
        prefixSum += num;

        if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
            count += prefixCount[prefixSum - k];
        }

        prefixCount[prefixSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << subarraySum(nums, k);

    return 0;
}