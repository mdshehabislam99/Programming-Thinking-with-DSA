#include<bits/stdc++.h>
using namespace std;

void missing_number(vector<int> &arr, int n) {
    int total_sum = (n * (n + 1)) / 2;
    int arr_sum = accumulate(arr.begin(), arr.end(), 0);
    int missing_num = total_sum - arr_sum;
    cout << "The missing number is: " << missing_num << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n - 1);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    missing_number(arr, n);

    return 0;
}
