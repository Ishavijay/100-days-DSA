/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.*/
#include <stdio.h>
#include <stdlib.h>

// Simple hash function size
#define HASH_SIZE 10007

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Hash table for prefix sums
    long long hash[HASH_SIZE] = {0};
    long long prefixSum = 0;
    long long count = 0;

    // Important: prefix sum 0 initially occurs once
    hash[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = ((prefixSum % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;

        count += hash[index];
        hash[index]++;
    }

    printf("%lld\n", count);

    return 0;
}