🔹 Problem Statement

Given an integer array nums and an integer k, remove the minimum number of elements such that for the remaining elements:

max_element ≤ min_element × k

💡 Key Insight

After sorting the array:

The minimum element of a subarray is at the left pointer

The maximum element is at the right pointer

So the problem reduces to finding the largest subarray [i…j] such that:

nums[j] ≤ nums[i] × k


Minimum removals =

n − (maximum valid subarray size)

🛠️ Approach

Sort the array

Use two pointers (i, j) to maintain a sliding window

Expand the window using j

Shrink the window from the left when the condition breaks

Track the maximum window size

⏱️ Complexity Analysis
Type	Complexity
Time	O(n log n)
Space	O(1) extra
