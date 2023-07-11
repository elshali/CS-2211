/*
- part1.c -
Gives information about an array with its contents specified by the user
Ali El-Shamy
251239933
CS 2211
*/

#include <stdio.h>

#define SIZE ((int) (sizeof(a) / sizeof(a[0])))

void part1(int a[], int arrSize, int arrSizeBytes) {
    printf("\nPart 1:");

    // Print out each element of the array and its position
    printf("\n    Your array is: ");
    for (int i = 0; i < arrSize; i++) {
        printf("[%d] = %d", i, a[i]);
        if (i != arrSize - 1)
            printf(", ");
    }
    
    // Print out size and element count
    printf("\n    The size of your array is %d bytes", arrSizeBytes);
    printf("\n    Your array has %d elements", arrSize);
}

void part2(int a[], int arrSize) {
    printf("\n\nPart 2:");

    // Go through the array in reverse order and print out the elements
    printf("\n    Your array in reverse is: ");
    for (int i = arrSize-1; i >= 0; i--)
        printf("%d ", a[i]);
}

void part3(int a[], int arrSize) {
    printf("\n\nPart 3:");

    // Store the first element in a variable called largest; loop through the array and compare with largest, replacing it if it is larger
    int largest = a[0];
    for (int i = 0; i < arrSize; i++) {
        if (a[i] > largest)
            largest = a[i];
    }

    printf("\n    The largest value in your array is: %d", largest);
}

void part4(int a[], int arrSize) {
    printf("\n\nPart 4:");

    int sum = 0;

    // Loop through the array and add each integer to the sum integer
    for (int i = 0; i < arrSize; i++)
        sum += a[i];

    printf("\n    The sum of all values in your array is: %d", sum);

}

void part5(int a[], int arrSize) {
    printf("\n\nPart 5:");
    
    // Create a copy of the array called r; copy the elements of a into r
    int r[arrSize];
    for (int i = 0; i < arrSize; i++)
        r[i] = a[i];

    // Switch the first and last elements
    int first = r[0];
    r[0] = r[arrSize-1];
    r[arrSize-1] = first;

    printf("\n    Your array with the first and last element switched is: ");
    for (int i = 0; i < arrSize; i++)
        printf(" %d", r[i]);
    
}

void part6(int a[], int arrSize) {
    printf("\n\nPart 6:");

    // Create a copy of a called s and create a temp variable
    int temp;
    int s[arrSize];
    for (int i = 0; i < arrSize; i++)
        s[i] = a[i];
    
    // Use Bubble Sort to sort the array in ascending order 
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (s[i] > s[j]) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("\n    Your array sorted in ascending order: ");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", s[i]);

}

int main(void) {

    int amount;

    printf("\n\nPlease enter the amount of integers in your array (maximum 15): ");
    scanf("%d", &amount);

    // Check if the user entered a valid amount of integers, restart if not
    if ((amount < 1) || (amount > 15)) {
        printf("\nInvalid number.");
        main();
    }

    int a[amount];
        
    // Prompt the user to enter their integers
    printf("\nPlease enter %d integers separated by spaces: ", amount);
    for (int i = 0; i < amount; i++)
        scanf("%d", &a[i]);

    int arrSizeBytes = sizeof(a);

    // Go through each part function in order, passing through the array and its size
    part1(a, SIZE, arrSizeBytes);
    part2(a, SIZE);
    part3(a, SIZE);
    part4(a, SIZE);
    part5(a, SIZE);
    part6(a, SIZE);

    return 0;
}