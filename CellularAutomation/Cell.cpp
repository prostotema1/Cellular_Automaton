#include "Cell.h"
void Cell::update_status(bool dead_or_alive) {
	switch (dead_or_alive)
	{
	case false:
		alive_or_not = false;
		break;
	case true:
		alive_or_not = true;
		break;
	default:
		break;
	}
}
