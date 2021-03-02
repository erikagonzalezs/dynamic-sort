#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <time.h>

void quicksort(std::vector<int> &valores, int left, int right);
int particion(std::vector<int> &valores, int left, int right);

int main()
{
	std::vector<int> valores;
	srand(time(NULL));
	for(int i = 0; i < 10; i++) {
    	valores.push_back(rand() % 200);
	}

	quicksort(valores, 0, valores.size() - 1);

	for(int i = 0; i < valores.size() ;i++) {
        std::cout << valores[i] << std::endl;
    }
	
	return 0;
}

void quicksort(std::vector<int> &valores, int left, int right) {
    if(left < right) {
        int pivote = particion(valores, left, right);
        quicksort(valores, left, pivote - 1);
        quicksort(valores, pivote, right);
    }
}

int particion(std::vector<int> &valores, int left, int right) {
    int pivote = left + (right - left) / 2;
    int pivoteValue = valores[pivote];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(valores[i] < pivoteValue) {
            i++;
        }
        while(valores[j] > pivoteValue) {
            j--;
        }
        if(i <= j) {
            temp = valores[i];
            valores[i] = valores[j];
            valores[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}