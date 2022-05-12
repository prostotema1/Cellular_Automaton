#pragma once
enum Cell_status { alive = 1, dead = 2 };
class Cell
{
public:
	Cell_status status;
	void update_status(bool dead_or_alive);
	int get_status() {
		return status;
	}
	void Draw_Cell(unsigned int x, unsigned int y, unsigned int colour);
};

