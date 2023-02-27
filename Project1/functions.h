#include <iostream>
#include <cstring>
using namespace std;
const int len = 20;
//prototypes for functions
void puzzle(int x, char difficulty[len][len], int& grid_size);

void search_vertically(char word[len], int row, int column, int& alphabet_index, char game_grid[len][len], int& counter, int grid_size);

void search_horizontally(char word[len], int row, int column, int& alphabet_index, char game_grid[len][len], int& counter, int grid_size);

void search_diagonal_upperLeft_to_lowerRight(char word[len], int row, int column, int& alphabet_index, char game_grid[len][len], int& counter, int grid_size);

void search_diagonal_upperRight_to_lowerLeft(char word[len], int row, int column, int& alphabet_index, char game_grid[len][len], int& counter, int grid_size);
