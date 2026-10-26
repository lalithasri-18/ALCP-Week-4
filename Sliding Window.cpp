#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    int n = arr.size();

    for (int i = 0; i < n; i++) {

        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter window size k: ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid window size";
        return 0;
    }

    vector<int> result = slidingWindowMax(arr, k);

    cout << "Sliding window maximum: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
