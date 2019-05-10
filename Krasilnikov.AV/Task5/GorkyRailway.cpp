#include "GorkyRailway.h"


// Функция проверки занятости места
// Возращает 1, если место свободно и 0 если занято или введены неверные данные
bool GorkyRailway::Check_private(int day, int direction, int type_wagon, int wagon, int place, int type_place)
{
	if (type_place == 1) {
		if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 8 || place < 1 || place > 100) {
			return 0;
		}
		else {
			if (private_lastsochka[day][direction][wagon][place] == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	else if (type_place == 2) {
		if (type_wagon == 1) {
			if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 4 || place < 1 || place > 54) {
				return 0;
			}
			if (private_firmeniy_plac[day][direction][wagon][place] == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (type_wagon == 2) {
			if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 6 || place < 1 || place > 36) {
				return 0;
			}
			if (private_firmeniy_kupe[day][direction][wagon][place] == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (type_wagon == 3) {
			if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 2 || place < 1 || place > 18) {
				return 0;
			}
			if (private_firmeniy_sv[day][direction][wagon][place] == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else if (type_place == 3) {
		if (type_wagon == 1) {
			if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 4 || place < 1 || place > 54) {
				return 0;
			}
			if (private_skoriy_plac[day][direction][wagon][place] == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (type_wagon == 2) {
			if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 8 || place < 1 || place > 36) {
				return 0;
			}
			if (private_skoriy_kupe[day][direction][wagon][place] == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

// Метод брони беста
void GorkyRailway::Set_private(int day, int direction, int type_wagon, int wagon, int place, int type_place)
{
	if (type_place == 1) {
		if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 8 || place < 1 || place > 100) {
			return;
		}
		else {
			private_lastsochka[day][direction][wagon][place] = 1;
		}
	}
	else if (type_place == 2) {
		if (type_wagon == 1) {
			if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 4 || place < 1 || place > 54) {
				return;
			}
			else {
				private_firmeniy_plac[day][direction][wagon][place] == 1;
			}
		}
		else if (type_wagon == 2) {
			if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 6 || place < 1 || place > 36) {
				return;
			}
			else {
				private_firmeniy_kupe[day][direction][wagon][place] = 1;
			}
		}
		else if (type_wagon == 3) {
			if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 2 || place < 1 || place > 18) {
				return;
			}
			else {
				private_firmeniy_sv[day][direction][wagon][place] = 1;
			}
		}
	}
	else if (type_place == 3) {
		if (type_wagon == 1) {
			if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 4 || place < 1 || place > 54) {
				return;
			}
			else {
				private_skoriy_plac[day][direction][wagon][place] == 1;
			}
		}
		else if (type_wagon == 2) {
			if (day < 1 || day > 31 || direction < 1 || direction > 2 || wagon < 1 || wagon > 8 || place < 1 || place > 36) {
				return;
			}
			else {
				private_skoriy_kupe[day][direction][wagon][place] == 1;
			}
		}
	}
}

GorkyRailway::GorkyRailway()
{
}


GorkyRailway::~GorkyRailway()
{
	delete[] private_lastsochka;
	delete[] private_firmeniy_plac;
	delete[] private_firmeniy_kupe;
	delete[] private_firmeniy_sv;
	delete[] private_skoriy_plac;
	delete[] private_skoriy_kupe;
}
