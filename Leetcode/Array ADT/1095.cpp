#include <iostream>
using namespace std;


  // This is the MountainArray's API interface.
  // You should not implement it, or speculate about its implementation
  class MountainArray {
    public:
      int get(int index);
      int length();
  };


class Solution {
public:

   int peakIndex(MountainArray A)
    {
        int start = 0;
        int end = A.length() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (A.get(mid) > A.get(mid + 1))
                end = mid;

            if (A.get(mid) < A.get(mid + 1))
                start = mid + 1;
        }
        return start;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
                int start = 0, peak;
        int end = mountainArr.length() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) > mountainArr.get(mid + 1))
                end = mid;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                start = mid + 1;
        }
        peak = start;

    // now search in the left part
    start = 0;
    end = peak;

    bool isAsc = mountainArr.get(start) < mountainArr.get(end);

while (start <= end)
{
    int mid = start + (end - start) / 2;

if (mountainArr.get(mid) == target)
return mid;

    if (isAsc) {
        if (mountainArr.get(mid) > target)
        end = mid - 1;
        else 
        start = mid + 1;
    }
    else {
        if (mountainArr.get(mid) > target)
        start = mid + 1;
        else 
        end = mid - 1;
    }
}

// search in the second part after peak
start = peak + 1
while (start <= end)
{
    int mid = start + (end - start) / 2;

if (mountainArr.get(mid) == target)
return mid;

    if (isAsc) {
        if (mountainArr.get(mid) > target)
        end = mid - 1;
        else 
        start = mid + 1;
    }
    else {
        if (mountainArr.get(mid) > target)
        start = mid + 1;
        else 
        end = mid - 1;
    }
}
return -1;
    }

};

int main()
{
    
    return 0;
}