#include <iostream>
#include <vector>

using namespace std;

void sumSubset(vector<int>& nums, int target, vector<int>& subset, int index, int sum) {
    if (sum == target) {
        // Print the subset that sums up to the target
        cout << "{";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ",";
            }
        }
        cout << "}" << endl;
        return;
    }

    if (sum > target || index == nums.size()) {
        // Backtrack if the sum exceeds the target or we reach the end of the array
        return;
    }

    // Include the current element in the subset
    subset.push_back(nums[index]);
    sumSubset(nums, target, subset, index + 1, sum + nums[index]);
    subset.pop_back();  // Exclude the current element from the subset

    // Exclude the current element from the subset
    sumSubset(nums, target, subset, index + 1, sum);
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> subset;
    sumSubset(nums, target, subset, 0, 0);
    return 0;
}

