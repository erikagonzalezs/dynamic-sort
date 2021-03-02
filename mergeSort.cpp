#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <time.h>

void sort(std::vector<int> &valores);
void mergeSort(std::vector<int> &izq,std::vector<int> &der,std::vector<int> &valores);

int main() {
   std::vector<int> valores;

   srand(time(NULL));
   for(int i = 0; i < 10; i++) {
      valores.push_back(rand() % 200);
   }

   sort(valores);

   for(int i = 0; i < valores.size() ;i++) {
      std::cout << valores[i] << std::endl;
  }

   return 0;
}

void sort(std::vector<int> &valores) {
   if (valores.size() <= 1) return;

   int mid = valores.size() / 2;
   std::vector<int> izq;
   std::vector<int> der;

   for (int i = 0; i < mid;i++)
   {
        izq.push_back(valores[i]);
   }
   for (int j = 0; j < (valores.size()) - mid; j++)
   {
        der.push_back(valores[mid + j]);
   }

    sort(izq);
    sort(der);
    mergeSort(izq, der, valores);
}

void mergeSort(std::vector<int> &izq, std::vector<int> &der, std::vector<int> &valores)
{
    int newIzq = izq.size();
    int newDer = der.size();
    int i = 0, j = 0, k = 0;

    while (j < newIzq && k < newDer) 
    {
        if (izq[j] < der[k]) {
            valores[i] = izq[j];
            j++;
        }
        else {
            valores[i] = der[k];
            k++;
        }
        i++;
    }
    while (j < newIzq) {
        valores[i] = izq[j];
        j++; 
        i++;
    }
    while (k < newDer) {
        valores[i] = der[k];
        k++; 
        i++;
    }
}
