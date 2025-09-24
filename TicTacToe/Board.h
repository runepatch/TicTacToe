#pragma once
#include <iostream>

namespace Game {
	void drawBoard(char* spaces);
	void playerOMove(char* spaces, int& turn);
	void playerXMove(char* spaces, int& turn);
	std::string determineWin(char* spaces);
	bool determineTie(char* spaces);
}