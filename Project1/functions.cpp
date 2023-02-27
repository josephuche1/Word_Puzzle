#include "functions.h"

//prints puzzle grid based on difficulty
void puzzle(int x, char difficulty[len][len], int& grid_size) { 
	int i, j;
	char letter;
	if (x == 1) {
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 6; j++) {
				letter = 65 + rand() % 26;
				difficulty[i][j] = letter;
				cout << difficulty[i][j] << " ";
			}
			cout << endl;
		}
		grid_size = 6;
	}
	else if (x == 2) {
		for (i = 0; i < 14; i++) {
			for (j = 0; j < 14; j++) {
				letter = 65 + rand() % 26;
				difficulty[i][j] = letter;
				cout << difficulty[i][j] << " ";
			}
			cout << endl;
		}
		grid_size = 14;
	}
	else if (x == 3) {
		for (i = 0; i < 20; i++) {
			for (j = 0; j < 20; j++) {
				letter = 65 + rand() % 26;
				difficulty[i][j] = letter;
				cout << difficulty[i][j] << " ";
			}
			cout << endl;
		}
		grid_size = 20;
	}

}

// searches for word vertically
void search_vertically(char word[len], int row, int column, int& alphabet_index, char game_grid[len][len], int& counter, int grid_size) {
	int row_save = row;
	while (row < grid_size) {
		while (alphabet_index < strlen(word)) {
			if (game_grid[row][column] == word[alphabet_index]) {
				alphabet_index++;
				break;
			}
			else { break; }
		}
		row++;
	}
	if (alphabet_index >= strlen(word)) {
		cout << "The word has been found." << endl;
		counter++;
	}
	else {
		cout << "The word has not been found in row " << row_save << ", and column " << column << ", and vertical direction." << endl;
	}
}

//searches for word horizontally
void search_horizontally(char word[len], int row, int column, int& alphabet_index, char game_grid[len][len], int& counter, int grid_size) {
	int column_save2 = column;
	while (column < grid_size) {
		while (alphabet_index < strlen(word)) {
			if (game_grid[row][column] == word[alphabet_index]) {
				alphabet_index++;
				break;
			}
			else { break; }
		}
		column++;
	}
	if (alphabet_index >= strlen(word)) {
		cout << "The word has been found." << endl;
		counter++;
	}
	else {
		cout << "The word has not been found in row " << row << ", and column " << column_save2 << ", and horizontal direction." << endl;

	}
}

//searches for word diagonally from upper left to lower right
void search_diagonal_upperLeft_to_lowerRight(char word[len], int row, int column, int& alphabet_index, char game_grid[len][len], int& counter, int grid_size) {
	int row_save3 = row;
	int column_save3 = column;
	while (row < grid_size && column < grid_size) {
		if (row - column <= column) {
			while (alphabet_index < strlen(word)) {
				if (game_grid[row][column] == word[alphabet_index]) {
					alphabet_index++;
					break;
				}
				else { break; }
			}
		}
		column++;
		row++;
	}
	if (alphabet_index >= strlen(word)) {
		cout << "The word has been found." << endl;
		counter++;
	}
	else {
		cout << "The word has not been found in row " << row_save3 << ", and column " << column_save3 << ", and left diagonal direction." << endl;
	}
}

//searches for word diagonally from upper right to lower left
void search_diagonal_upperRight_to_lowerLeft(char word[len], int row, int column, int& alphabet_index, char game_grid[len][len], int& counter, int grid_size) {
	int column_save4 = column;
	int row_save4 = row;
	while (row < grid_size && column < grid_size) {
		if (row + column >= column) {
			while (alphabet_index < strlen(word)) {
				if (game_grid[row][column] == word[alphabet_index]) {
					alphabet_index++;
					break;
				}
				else { break; }
			}
		}
		column--;
		row++;
	}
	if (alphabet_index >= strlen(word)) {
		cout << "The word has been found." << endl;
		counter++;
	}
	else {
		cout << "The word has not been found in row " << row_save4 << ", and column " << column_save4 << ", and right diagonal direction." << endl;

	}
}
