#include "Cell.h"
void Cell::update_status(bool dead_or_alive) {
	switch (dead_or_alive)
	{
	case false:
		status = dead;
		break;
	case true:
		status = alive;
		break;
	default:
		break;
	}
}
