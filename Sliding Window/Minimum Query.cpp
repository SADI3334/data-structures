#include <bits/stdc++.h>

using namespace std;

void printMinimum(int *arr, int n, int k) {
    deque <int> Q;
    for (int i = 0; i < k; ++i) {
        while (!(Q.empty()) && arr[i] <= arr[Q.front()]) {
            Q.pop_front();
        }
        Q.push_front(i);
    }
    for (int i = k; i < n; ++i) {
        cout << arr[Q.back()] << " ";
        while ((!Q.empty()) && Q.back() <= i - k) {
            Q.pop_back();
        }
        while (!(Q.empty()) && arr[i] <= arr[Q.front()]) {
            Q.pop_front();
        }
        Q.push_front(i);
    }
    cout << arr[Q.back()] << endl;
}

int main()
{
    int arr[] = {1, 2, -1, 3, 1, -2, 3, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printMinimum(arr, n, k);
}
