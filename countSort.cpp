#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <time.h>

void countSort(std::vector<int> &valores, int tam);

int main()
{
	int n;
	std::vector<int> valores;
	srand(time(NULL));
	for(int i = 0; i < 10000; i++) {
    	valores.push_back(rand() % 20000);
	}

	countSort(valores, valores.size());

	for(int i = 0; i < valores.size() ;i++) {
    	std::cout << valores[i] << std::endl;
	}
	
	return 0;
}

void countSort(std::vector<int> &valores, int tam)
{
	int max = valores[0];
	std::vector<int> salida;
	std::vector<int> cuenta;

	for(int i = 1; i < tam; i++){
		if(valores[i] > max){
			max = valores[i];
		}
	}

	for(int i = 0; i <= max; ++i){
		cuenta.push_back(0);
		salida.push_back(0);
	}

	for(int i = 0; i < tam; i++){
		cuenta[valores[i]]++;
	}

	for(int i = 1; i <= max; i++){
		cuenta[i] += cuenta[i - 1];
	}

	for (int i = tam - 1; i >= 0; i--) {
    	salida[cuenta[valores[i]] - 1] = valores[i];
    	cuenta[valores[i]]--;
  	}

  	for (int i = 0; i < tam; i++) {
    	valores[i] = salida[i];
  	}

}
