//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int getMinInArr(int arr[], int n, int prevMin)
    {
        int min = arr[0];

        sort(arr, arr + n);

        return min;
    }

    int minOperations(int arr[], int n, int k)
    {
        // code here
        int count = 0, min1, min2;

        min1 = getMinInArr(arr, n, 0);
        min2 = getMinInArr(arr, n, min1);

        cout << min1 << " " << min2 << endl;

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cout << "Enter array size and condition" << endl;
        cin >> n >> k;
        int arr[n];
        cout << "Enter array elements" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends