#include "Field.h"
//Initialization of Feild with size wight * Height
void Field::init(int Wight, int Height,int cell_size) {
	wight = Wight;
	height = Height;
	this->cell_size = cell_size;
	field = new Cell * [height];
	for (size_t i = 0; i < height; i++) {
		field[i] = new Cell[Wight];
	}
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < Wight; j++) {
			field[i][j].update_status(false);
		}
	}
}

//Draw cell in window
void Field::Draw_cell(unsigned int x, unsigned int y, unsigned int colour) {
	Uint8* pixel_ptr = (Uint8*)surface->pixels + (y * cell_size * wight * cell_size + x * cell_size) * 4;
	for (unsigned int i = 0; i < cell_size; i++)
	{
		for (unsigned int j = 0; j < cell_size; j++)
		{
			*(pixel_ptr + j * 4) = colour;
			*(pixel_ptr + j * 4 + 1) = colour;
			*(pixel_ptr + j * 4 + 2) = colour;
		}
		pixel_ptr += cell_size * wight * 4;
	}
}

//Draw field in console
void Field::print_field() {
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < wight; j++) {
			if (field[i][j].get_status() == 1) {
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
	std::cout << std::endl << std::endl << std::endl << std::endl;
}

//Update cell status on it's neighbours
bool Field::update_status(int x, int y) {
	int counter_dead = 0;
	int counter_alive = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (i != 0 || j != 0) {
				if (x + i < 0) {
					if (y + j < 0) {
						if (field[height - 1][wight - 1].get_status() == 1) {
							counter_alive++;
						}
						else { counter_dead++; }
					}
					else if (y + j > wight - 1) {
						if (field[height - 1][0].get_status() == 1) { counter_alive++; }
						else {
							counter_dead++
								;
						}
					}
					else {
						if (field[height - 1][y + j].get_status() == 1) { counter_alive++; }
						else { counter_dead++; }
					}
				}
				else if (x + i > height - 1) {
					if (y + j < 0) {
						if (field[0][wight - 1].get_status() == 1) { counter_alive++; }
						else { counter_dead++; }
					}
					else if (y + j > wight - 1) {
						if (field[0][0].get_status() == 1) { counter_alive++; }
						else { counter_dead++; }
					}
					else {
						if (field[0][y + j].get_status() == 1) { counter_alive++; }
						else {counter_dead++;}
					}
				}
				else {
					if (y + j < 0) {
						if (field[x + i][wight - 1].get_status() == 1) { counter_alive++; }
						else {counter_dead++;
					}
					}
					else if (y + j > wight - 1) {
						if (field[x + i][0].get_status() == 1) { counter_alive++; }
						else { counter_dead++; }
					}
					else {
						if (field[x+i][y+j].get_status() == 1) { counter_alive++; }
						else {counter_dead++;}
					}
				}
			}
		}
	}
	if (field[x][y].get_status() == 1) {
		if (counter_alive == 2 || counter_alive == 3) {
			return true;
		}
		else if (counter_alive > 3 || counter_alive < 2) {
			return false;
		}
	}
	else {
		if (counter_alive == 3) {
			return true;
		}
	}
}

//Next generation of life
void Field::next_iteration() {
	copy = new Cell * [height];
	for (int i = 0; i < height; i++) {
		copy[i] = new Cell[wight];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < wight; j++) {
			copy[i][j].status = field[i][j].status;
		}
	}
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < wight; j++) {
			bool stat = this->update_status(i, j);
			copy[i][j].update_status(stat);
			if (stat) {Draw_cell(i, j, OFF_COLOUR); }
			else {
				Draw_cell(i, j, ON_COLOUR);
			}
		}
	}
	this->cleaning();
	std::swap(this->field, copy);
	//delete copy;
}

//If you need to set some cells from a start, you can do it by yourself
void Field::alive_from_start(int x, int y) {
	field[x][y].update_status(true);
}

//Fill the field with cells
void Field::random_fill(int number_of_alive_cells){
	for (int i = 0; i < number_of_alive_cells; i++) {
		field[rand() % height][rand() % wight].update_status(true);
	}

}

//Clean the Field
void Field::cleaning() {
	for (size_t i = 0; i < height; i++) {
		delete [] this->field[i];
	}
	delete [] this->field;
}

//Output operator in console
std::ostream& operator<<(std::ostream& s, const Field& f) {
	for (int i = 0; i < f.height; i++) {
		for (int j = 0; j < f.wight; j++) {
			if (f.field[i][j].get_status() == 1) {
				s<< "*";
			}
			else {
				s << " ";
			}
		}
		s << "\n";
	}
	s << std::endl << std::endl << std::endl << std::endl;
	return s;
}

//Graphic
void Field::init_graphic() {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Conway's Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wight * cell_size, height * cell_size, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
}
