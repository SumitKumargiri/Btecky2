#include <iostream>
#include <vector>
using namespace std;

void countingSort(std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }

    int maxElement = *std::max_element(arr.begin(), arr.end());

    std::vector<int> count(maxElement + 1, 0);

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }

    std::vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    countingSort(arr);
    
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    return 0;
}
