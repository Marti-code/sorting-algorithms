#pragma once

#include <iostream>
#include <fstream>
#include <ostream>
#include <cstdlib>
#include <chrono>
#include <vector>

void optimizedSelectionSort(int arr[], int n);


void insertionSortWithSentinel(int arr[], int n);


int binarySearch(int a[], int item, int low, int high);
void insertionSortBinary(int arr[], int n);


void bubbleSortOptimized(int arr[], int n);


int medianOfThree(int arr[], int low, int high);
int hoarePartition(int arr[], int low, int high);
void quicksortHoare(int arr[], int low, int high);

int hoarePartitionDesc(int arr[], int low, int high);
void quicksortHoareDesc(int arr[], int low, int high);


void heapifyOptimized(int arr[], int n, int i);
void heapSortOptimized(int arr[], int n);


void shellSortKnuth(int arr[], int n);
