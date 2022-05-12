#include"Field.h"
#include<iostream>
#include<Windows.h>
#include <ctime>
#include<SDL.h>
#define LIMIT_RATE 1;
#define TICK_RATE 50;
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
	f.init(height, wight, cell_size);
	std::cout << "\nEnter the number of alive cells\nCells alive = ";
	int n;
	std::cin >> n;
	std::cout << std::endl;
	f.random_fill(n);
	std::cout << "\nYour generated field\nEnter the number of iterations\nIterations = ";
	int num;
	std::cin >> num;
	f.init_graphic();
	for (int i = 0; i < num; i++){
		f.next_iteration();
		SDL_UpdateWindowSurface(f.window);
	}
	SDL_DestroyWindow(f.window);
	SDL_Quit();
	f.cleaning();
}
