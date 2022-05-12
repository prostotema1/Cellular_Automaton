#pragma once
#include"Cell.h"
#include<iostream>
#include<random>
#include"include/SDL.h"
#define OFF_COLOUR 0x00
#define ON_COLOUR 0xFF

class Field
{
	Cell** field;
	Cell** copy;
	int wight = 0 ;
	int height = 0;	
	unsigned int cell_size;
	
	inline bool get_cell_status(int x, int y) {
		return field[x][y].status;
	}

public:
	SDL_Event e;
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	void init(int x, int y, int cell_size);
	void alive_from_start(int x, int y);
	void print_field();
	bool update_status(int x, int y);
	void next_iteration();
	void random_fill(int number_of_alive_cells);
	void cleaning();
	friend std::ostream& operator<<(std::ostream& s, const Field& f);
	void Draw_cell(unsigned int x, unsigned int y, unsigned int colour);
	void init_graphic();
};

