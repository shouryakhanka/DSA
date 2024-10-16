# # Python program for implementation of Insertion Sort

# # Function to do insertion sort
# def insertionSort(arr):

#     if (n := len(arr)) <= 1:
#         return
#     for i in range(1, n):

#         key = arr[i]

#         # Move elements of arr[0..i-1], that are
#         # greater than key, to one position ahead
#         # of their current position
#         j = i-1
#         while j >= 0 and key < arr[j]:
#             arr[j+1] = arr[j]
#             j -= 1
#         arr[j+1] = key


# # sorting the array [12, 11, 13, 5, 6] using insertionSort
# arr = [12, 11, 13, 5, 6]
# insertionSort(arr)
# print(arr)

# Python program for implementation of Selection
# Sort
import sys
A = [64, 25, 12, 22, 11]

# Traverse through all array elements
for i in range(len(A)):

    # Find the minimum element in remaining
    # unsorted array
    min_idx = i
    for j in range(i+1, len(A)):
        if A[min_idx] > A[j]:
            min_idx = j

    # Swap the found minimum element with
    # the first element
    A[i], A[min_idx] = A[min_idx], A[i]

# Driver code to test above
print("Sorted array")
for i in range(len(A)):
    print("%d" % A[i], end=" , ")
