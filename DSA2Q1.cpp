#include<bits/stdc++.h>
using namespace std;

int crossProduct(int *arr, int low, int mid, int high, int &start, int &end)
{
    int leftMax = INT_MIN, rightMax = INT_MIN;
    int curProd = 1;
    int tempStart = mid, tempEnd = mid + 1;

    for (int i = mid; i >= low; i--) 
    {
        curProd *= arr[i];

        if (curProd > leftMax) 
        {
            leftMax = curProd;
            tempStart = i;
        }
    }

    curProd = 1;

    for (int i = mid + 1; i <= high; i++) 
    {
        curProd *= arr[i];
        if (curProd > rightMax) {
            rightMax = curProd;
            tempEnd = i;
        }
    }

    start = tempStart;
    end = tempEnd;
    return leftMax * rightMax;
}

int maxProductRec(int *arr, int low, int high, int &start, int &end)
{
    if(low == high) 
    {
        start = low;
        end = high;
        return arr[low];
    }

    int mid = (low + high) / 2;
    
    int leftStart, leftEnd, rightStart, rightEnd, crossStart, crossEnd;

    int leftMax = maxProductRec(arr, low, mid, leftStart, leftEnd);

    int rightMax = maxProductRec(arr, mid + 1, high, rightStart, rightEnd);

    int crossMax = crossProduct(arr, low, mid, high, crossStart, crossEnd);

    
    if(leftMax >= rightMax && leftMax >= crossMax) 
    {
        start = leftStart;
        end = leftEnd;
        return leftMax;
    }
    else if(rightMax >= leftMax && rightMax >= crossMax) 
    {
        start = rightStart;
        end = rightEnd;
        return rightMax;
    }
    else 
    {
        start = crossStart;
        end = crossEnd;
        return crossMax;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int start, end;

    int maxProduct = maxProductRec(arr, 0, n - 1, start, end);

    cout << maxProduct << endl;
    cout << "Start index : " << start << endl;
    cout << "End index : " << end << endl;

    return 0;
}
