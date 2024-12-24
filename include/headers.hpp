#ifndef HEADERS
#define HEADERS

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "raylib.h"

extern const int ANCHOR;
extern const int PARTS;
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const float BOARD_X;
extern const float BOARD_Y;
extern const float BOARD_SIZE;
extern const float CELL_SIZE;
extern const float GAP_SIZE;
extern const float BIG_GAP_SIZE;

extern const std::vector<std::vector<bool>> vector_for_testing;

bool operator==(const Color& lhs, const Color& rhs);

#endif