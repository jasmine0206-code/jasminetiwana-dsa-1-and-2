//ASSIGNMENT 2

//QUESTION 1

#include <iostream>
using namespace std;

/**
 * Binary Search on a raw array (iterative)
 * @param arr pointer to the first element
 * @param n   number of elements
 * @param target value to find
 * @return index of target if found, else -1
 */
int binarySearch(const int* arr, int n, int target) {
    if (n <= 0) return -1; 

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        // Safe mid calculation (avoids potential overflow)
        int mid = left + (right - left) / 2;
        int midVal = arr[mid];

        if (midVal == target) {
            return mid; // found it
        } else if (midVal < target) {
            left = mid + 1;  // search right half
        } else {
            right = mid - 1; // search left half
        }
    }
    return -1; // not found
}

int main() {
    // Sorted array (must be ascending)
    int a[] = {-5, -1, 0, 3, 4, 7, 9, 12};
    int n = sizeof(a) / sizeof(a[0]);

    cout << binarySearch(a, n, 7) << "\n";  // 5
    cout << binarySearch(a, n, 8) << "\n";  // -1
    return 0;
}


//QUESTION 2

#include <iostream>
using namespace std;

// Helper: print the array nicely
void printArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << "\n";
}

/**
 * Bubble Sort (simple and easy to follow)
 * - Repeatedly compares adjacent elements and swaps if they’re in the wrong order.
 * - After the i-th pass, the largest element among the unsorted part bubbles to the end.
 * - Time: O(n^2) in worst/average cases; O(n) if already sorted (with early-exit).
 */
void bubbleSort(int* arr, int n) {
    // Basic safety
    if (n <= 1) return;

    // Outer loop: number of passes
    for (int pass = 0; pass < n - 1; ++pass) {
        bool swapped = false; // track if any swap happened in this pass

        // Inner loop: compare adjacent pairs up to the unsorted boundary (n - 1 - pass)
        for (int j = 0; j < n - 1 - pass; ++j) {
            // If the left element is bigger, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Optional: show array state after each pass (helps visualize)
        // Comment this out if you want cleaner output.
        cout << "After pass " << pass + 1 << ": ";
        printArray(arr, n);

        // If no swaps in this pass, the array is already sorted — bail out early
        if (!swapped) break;
    }
}

int main() {
    // Given elements
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted:   ";
    printArray(arr, n);

    return 0;
}


//QUESTION 3

#include <bits/stdc++.h>
using namespace std;

// Find the single missing number in a sorted array containing numbers 1..n (one missing).
// arr length = n-1
int findMissing_1_to_n(const int* arr, int n_minus_1) {
    int l = 0, r = n_minus_1 - 1;
    // We look for the first index where arr[i] != i+1
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == mid + 1) {
            // Perfect up to mid, hole is to the right
            l = mid + 1;
        } else {
            // Mismatch here or before
            r = mid - 1;
        }
    }
    // l is the first mismatch index; missing number is l+1
    return l + 1;
}

int main1() {
    int a[] = {1, 2, 3, 5, 6};
    int n_minus_1 = sizeof(a) / sizeof(a[0]); // here n would be 6
    cout << "Missing (1..n): " << findMissing_1_to_n(a, n_minus_1) << "\n"; // 4
    return 0;
}


//QUESTION 4

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Check if a character is a vowel (a, e, i, o, u) in either case
bool isVowel(char ch) {
    char c = ch;
    if (c >= 'A' && c <= 'Z') c = char(c - 'A' + 'a'); // manual tolower
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    // (a) Concatenate one string to another
    cout << "\n(a) Concatenate two strings\n";
    cout << "Enter first string: ";
    string s1; getline(cin, s1);
    cout << "Enter second string: ";
    string s2; getline(cin, s2);
    string concatenated = s1 + s2; // simplest way
    cout << "Concatenated: " << concatenated << "\n";

    // (b) Reverse a string
    cout << "\n(b) Reverse a string\n";
    cout << "Enter a string to reverse: ";
    string toReverse; getline(cin, toReverse);
    // Basic reverse using two pointers
    int i = 0, j = (int)toReverse.size() - 1;
    while (i < j) {
        char tmp = toReverse[i];
        toReverse[i] = toReverse[j];
        toReverse[j] = tmp;
        i++; j--;
    }
    cout << "Reversed: " << toReverse << "\n";

    // (c) Delete all vowels from the string
    cout << "\n(c) Delete all vowels from a string\n";
    cout << "Enter a string: ";
    string withVowels; getline(cin, withVowels);
    string noVowels = "";
    for (char ch : withVowels) {
        if (!isVowel(ch)) noVowels += ch; // keep non-vowels
    }
    cout << "Without vowels: " << noVowels << "\n";

    // (d) Sort strings in alphabetical order
    cout << "\n(d) Sort multiple strings alphabetically\n";
    cout << "How many strings? ";
    int n; 
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline
    vector<string> arr(n);
    for (int k = 0; k < n; ++k) {
        cout << "Enter string " << (k + 1) << ": ";
        getline(cin, arr[k]);
    }
    // Simple sort using standard lexicographical order
    sort(arr.begin(), arr.end());
    cout << "Sorted order:\n";
    for (const auto& s : arr) cout << s << "\n";

    // (e) Convert a character from uppercase to lowercase
    cout << "\n(e) Convert a character from uppercase to lowercase\n";
    cout << "Enter a single character: ";
    char ch;
    cin >> ch;
    // Manual lowercase conversion (only affects A-Z)
    if (ch >= 'A' && ch <= 'Z') {
        ch = char(ch - 'A' + 'a');
    }
    cout << "Lowercase: " << ch << "\n";

    return 0;
}



//QUESTION 7

#include <iostream>
using namespace std;

// Function to count inversions in array A of size n
int countInversions(int A[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number of elements:\n";
    cin >> n;

    int A[100];  // max 100 elements
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int inversions = countInversions(A, n);
    cout << "Number of inversions: " << inversions << endl;

    return 0;
}

//QUESTION 8

#include <iostream>
using namespace std;

// Function to count distinct elements in array A of size n
int countDistinct(int A[], int n) {
    int distinctCount = 0;
    
    for (int i = 0; i < n; i++) {
        bool found = false;
        // Check if A[i] appeared before in the array
        for (int j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            distinctCount++;
        }
    }
    
    return distinctCount;
}

int main() {
    int n;
    cout << "Enter number of elements:\n";
    cin >> n;

    int A[100];  // max 100 elements
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int result = countDistinct(A, n);
    cout << "Number of distinct elements: " << result << endl;

    return 0;
}

//ADDITIONAL QUESTIONS

//QUESTION 1

#include <iostream>
#include <vector>
using namespace std;

int countPairs(vector<int> &arr, int k) {
    int n = arr.size();
    int cnt = 0;

    // generate all possible pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            // If absolute difference = k, then increment
            // count by 1
            if (abs(arr[i] - arr[j]) == k) {
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 4, 1, 4, 5};
    int k = 3;

    cout << countPairs(arr, k);
    return 0;
}

//QUESTION 2

#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    int freq[26] = {0};

    // Count characters in str1
    for (char c : str1) {
        freq[c - 'a']++;
    }

    // Subtract counts using str2
    for (char c : str2) {
        freq[c - 'a']--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }
    return true;
}

// QUESTION 3

#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    int freq[26] = {0};

    // Count characters in str1
    for (char c : str1) {
        freq[c - 'a']++;
    }

    // Subtract counts using str2
    for (char c : str2) {
        freq[c - 'a']--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }
    return true;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

//QUESTION 4

#include <iostream>
using namespace std;

void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];

//QUESTION 5

#include <iostream>
#include <vector>
using namespace std;

void duplicateTwos(vector<int>& arr) {
    int n = arr.size();
    int possibleLength = n;
    int twosCount = 0;

    // Count twos (but careful about overflow in last element)
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            // If duplicating this 2 would exceed array length
            if (i + twosCount >= n - 1) {
                // Special case: put one 2 at the end and stop
                arr[n - 1] = 2;
                possibleLength = n - 1;
                break;
            }
            twosCount++;
        }
    }

    int i = possibleLength - 1;
    int j = n - 1;

    // Second pass: copy backwards
    while (i >= 0) {
        if (arr[i] == 2) {
            arr[j--] = 2;
            arr[j--] = 2;
        } else {
            arr[j--] = arr[i];
        }
        i--;
    }
}

int main() {
    int n;
cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    duplicateTwos(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}





