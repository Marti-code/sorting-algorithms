#include <iostream>
#include <fstream>
#include <ostream>
#include <cstdlib>
#include <chrono>
#include <vector>

#include "algorytmy.cpp"

enum userChoice
{
    BUBBLE = 1,
    SELECTION,
    INSERT,
    QUICKSORT,
    HEAPSORT,
    SHELL,
};

int main(int argc, char* argv[]){
    FILE *data;
    data=fopen("dane","r");

    int n;
    std::cout << "Liczba el do posortowania:";
    std::cin >> n;

    int choice;
    int what_data;

    std::cout << "Wybierz algorytm:\n";
    std::cout << "Bubble: 1\n";
    std::cout << "Selection: 2\n";
    std::cout << "Insertion binary search: 3\n";
    std::cout << "Quicksort: 4\n";
    std::cout << "Heapsort: 5\n";
    std::cout << "Shellsort: 6\n";
    std::cout << "Koniec: 0\n";
    std::cin >> choice;

    std::cout << "Dane randomowe (1), posortowane rosnaco (2), posortowane malejaco (3): ";
    std::cin >> what_data;

    std::vector<int> arr(n);

    for(int i=0;i<n;i++)
        fscanf(data,"%d",&arr[i]);

    switch (what_data){
        case 1:
            break;
        case 2:
            quicksortHoare(arr.data(), 0, n-1);
            break;

        case 3:
            quicksortHoareDesc(arr.data(), 0, n-1);
            break;
        
        default:
            std::cout << "Zly input.\n";
            break;
    }

    do{
        auto start = std::chrono::high_resolution_clock::now();

        switch (choice){
            case BUBBLE:
                bubbleSortOptimized(arr.data(), n);
                break;
            case SELECTION:
                optimizedSelectionSort(arr.data(), n);
                break;
            case INSERT:
                insertionSortBinary(arr.data(), n);
                break;
            case QUICKSORT:
                quicksortHoare(arr.data(), 0, n-1);
                break;
            case HEAPSORT:
                heapSortOptimized(arr.data(), n);
                break;
            case SHELL:
                shellSortKnuth(arr.data(), n);
                break;
            default:
                std::cout << "Zly input.\n";
                break;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

        std::cout << "Sortowanie zajelo " << duration.count() << " sekund." << std::endl;

        std::cout << "Wynik: \n \n";

        for(int i=0;i<n;i++){
            std::cout << arr[i]; 
            std::cout << " ";
        }

        std::cout<<std::endl;

        rewind(data);


        std::cout << "Liczba el do posortowania:";
        std::cin >> n;

        std::cout << "Wybierz algorytm:\n";
        std::cout << "Bubble: 1\n";
        std::cout << "Selection: 2\n";
        std::cout << "Insertion binary search: 3\n";
        std::cout << "Quicksort: 4\n";
        std::cout << "Heapsort: 5\n";
        std::cout << "Shellsort: 6\n";
        std::cout << "Koniec: 0\n";
        std::cin >> choice;

        std::cout << "Dane randomowe (1), posortowane rosnaco (2), posortowane malejaco (3): ";
        std::cin >> what_data;

        for(int i=0;i<n;i++)
            fscanf(data,"%d",&arr[i]);

        switch (what_data){
        case 1:
            break;
        case 2:
            quicksortHoare(arr.data(), 0, n-1);
            break;

        case 3:
            quicksortHoareDesc(arr.data(), 0, n-1);
            break;
        
        default:
            std::cout << "Zly input.\n";
            break;
        }

    }while(choice!=0);


    // std::cout << "Sorted: \n \n";

    // for(int i=0;i<n;i++){
    //     std::cout << arr[i]; 
    //     std::cout <<std::endl;
    // }

    // std::cout<<endl;

    return 0;
}
