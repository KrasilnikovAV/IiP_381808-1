#pragma once

class GorkyRailway
{
private:
	// Здесь храниться информация о занятых местах
	bool private_lastsochka[31][2][8][100] = { 0 }; // Индексы означают: День, направление, вагон, место.
	bool private_firmeniy_plac[31][2][4][54] = { 0 };
	bool private_firmeniy_kupe[31][2][6][36] = { 0 };
	bool private_firmeniy_sv[31][2][2][18] = { 0 };
	bool private_skoriy_plac[31][2][4][54] = { 0 };
	bool private_skoriy_kupe[31][2][8][36] = { 0 };
public:
	// Цены билетов
	const unsigned int lastsochka_price = 100;
	const unsigned int firmeniy_plac_price = 200;
	const unsigned int firmeniy_kupe_price = 300;
	const unsigned int firmeniy_sv_price = 250;
	const unsigned int skoriy_plac_price = 150;
	const unsigned int skoriy_kupe_price = 200;
	// Функция проверки занятости места
	bool Check_private(int day, int direction, int type_wagon, int wagon, int place, int type_place);
	// Метод брони беста
	void Set_private(int day, int direction, int type_wagon, int wagon, int place, int type_place);
	GorkyRailway();
	~GorkyRailway();
};

