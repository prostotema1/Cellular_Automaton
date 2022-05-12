#pragma once
class Cell
{
public:
	bool alive_or_not;// True = alive, dead = false
	void update_status(bool dead_or_alive);
	bool get_status() {
		return this->alive_or_not;
	}
	void Draw_Cell(unsigned int x, unsigned int y, unsigned int colour);
};

