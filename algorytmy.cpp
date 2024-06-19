#include "algorytmy.hpp"

//selection sort

void optimizedSelectionSort(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int min_idx = i;
        int max_idx = i;
        for (int j = i + 1; j < n - i; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        std::swap(arr[min_idx], arr[i]);
        
        if (arr[max_idx] == arr[i]) {
            max_idx = min_idx;
        }
        std::swap(arr[max_idx], arr[n - i - 1]);
    }
}


//insert sort 

void insertionSortWithSentinel(int arr[], int n) {
    int key, j;
    
    for (int i = 2; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



int binarySearch(int a[], int item, int low, int high) {
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == a[mid])
        return mid + 1;

    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}

void insertionSortBinary(int arr[], int n) {
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = arr[i];

        loc = binarySearch(arr, selected, 0, j);
        
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}


// bubble sort

void bubbleSortOptimized(int arr[], int n) {
    bool swapped = true;
    int i = 0;

    while (swapped && i < n - 1) {
        swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        i++;
    }
}

// quick sort

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low])
        std::swap(arr[mid], arr[low]);
    if (arr[high] < arr[low])
        std::swap(arr[high], arr[low]);
    if (arr[high] < arr[mid])
        std::swap(arr[high], arr[mid]);
    return arr[mid];
}


int hoarePartition(int arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = low - 1, j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;
        
        std::swap(arr[i], arr[j]);
    }
}

void quicksortHoare(int arr[], int low, int high) {
    if (low < high) {
        int partIdx = hoarePartition(arr, low, high);

        quicksortHoare(arr, low, partIdx);
        quicksortHoare(arr, partIdx + 1, high);
    }
}



int hoarePartitionDesc(int arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = low - 1, j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] > pivot); 

        do {
            j--;
        } while (arr[j] < pivot);

        if (i >= j)
            return j;
        
        std::swap(arr[i], arr[j]);
    }
}

void quicksortHoareDesc(int arr[], int low, int high) {
    if (low < high) {
        int partIdx = hoarePartitionDesc(arr, low, high);

        quicksortHoareDesc(arr, low, partIdx);
        quicksortHoareDesc(arr, partIdx + 1, high);
    }
}



// heapsort

void heapifyOptimized(int arr[], int n, int i) {
    while (true) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

void heapSortOptimized(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyOptimized(arr, n, i);

    for (int i=n-1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapifyOptimized(arr, i, 0);
    }
}


// shell sort

void shellSortKnuth(int arr[], int n) {

    int gap = 1;
    while (gap < n/3) {
        gap = 3 * gap + 1;
    }

    while (gap>= 1) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap/=3;
    }
}