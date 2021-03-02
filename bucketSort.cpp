#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <time.h>
#include <algorithm>

void bucketSort(std::vector<int> &valores, int tam);
void countSort(std::vector<int> &valores, int tam);

int main() {
	std::vector<int> valores;
	srand(time(NULL));
	for(int i = 0; i < 100; i++) {
    	valores.push_back(rand() % 200);
	}

	bucketSort(valores, valores.size());

	for(int i = 0; i < valores.size() ;i++) {
    	std::cout << valores[i] << std::endl;
	}
}

void bucketSort(std::vector<int> &valores, int tam) {
	int maximo = 0;
	int divisor = 0;
	int casillero = 0;
	std::vector<std::vector<int> > bucket;
	std::vector<int> aux;

	bucket.reserve(valores.size());

	for(int i = 0; i < tam; i++){
		if(valores[i] > maximo){
			maximo = valores[i];
		}
		bucket.push_back(aux);
	}

	divisor = maximo / tam;

	for(int i = 0; i < tam; i++){
		casillero = valores[i] / divisor;
		if(casillero >= tam){
			bucket[tam-1].push_back(valores[i]);
		}else{
			bucket[casillero].push_back(valores[i]);
		}
	}

	for(int i = 0; i < tam; i++){
		if(!bucket[i].empty()){
			countSort(bucket[i],bucket[i].size());
		}
	}

	valores.clear();

	for(int i = 0; i < tam; i++){
		if(!bucket[i].empty()){
			valores.reserve(valores.size() + bucket[i].size());
			valores.insert(valores.end(), bucket[i].begin(), bucket[i].end());
		}
	}
	
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
