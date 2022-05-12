#include"Field.h"
#include<iostream>
#include<Windows.h>
#include <ctime>
#include<SDL.h>
const unsigned int LIMIT_RATE = 1;
const unsigned int TICK_RATE =50;
#undef main;

void main(){
	Field f;
	std::cout << "Enter the size of the field \nHeight = ";
	int height;
	std::cin >> height;
	std::cout << "\nWight = ";
	int wight;
	std::cin >> wight;
	int cell_size;
	std::cout << "\nSize of a cell = ";
	std::cin >> cell_size;
	while (height < 0 || wight < 0 || cell_size < 0) {
		std::cout << "\nWrong input. Enter correct information\nHeight = ";
		std::cin >> height;
		std::cout << "\nWight = ";
		std::cin >> wight;
		std::cout << "\nCell size = ";
		std::cin >> cell_size;
	}
	f.init(height, wight, cell_size);
	std::cout << "\nEnter the number of alive cells\nCells alive = ";
	int n;
	std::cin >> n;
	while (n < 0) {
		std::cout << "Wrong data. Enter the right one\nCells alive = ";
		std::cin >> n;
	}
	f.random_fill(n);
	std::cout << "\nField has been generated\nEnter the number of generations\nGenerations = ";
	int generations;
	std::cin >> generations;
	while (generations < 0) {
		std::cout << "\nWrong data. Enter the right one\nGenerations = ";
		std::cin >> generations;
	}
	f.init_graphic();
	for (int i = 0; i < generations; i++){
		f.next_iteration();
		SDL_UpdateWindowSurface(f.window);
		if (LIMIT_RATE) { SDL_Delay(TICK_RATE); }
	}
	SDL_DestroyWindow(f.window);
	SDL_Quit();
	f.cleaning();
}
