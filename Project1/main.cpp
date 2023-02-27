//Name:Uche Joseph Ugochukwu
//Word Puzzle

#include "functions.h" // importing functions from external file


int main() { // main

	char word[len], game_grid[len][len];
	int difficulty_choice,grid_size, counter = 0;
	cout << "Welcome" << endl;
	cout << "Press 1 if you would like to play the easy option,2 for the medium option, 3 for the hard option and 4 to exit the game : " << endl;
	cout << "1) Easy" << endl << "2) Medium" << endl << "3) Hard" << endl << "4)Exit the game" << endl;
	cin >> difficulty_choice;

	while (difficulty_choice != 4) {

		puzzle(difficulty_choice, game_grid,grid_size);
		cout << "Enter the word that I should search for. Press 'X' if you will not like to search for another word: "; 
		cin >> word;

		while (word[0] != 'x' && word[0] != 'X') {

			int row, column, search_direction, alphabet_index = 0;
			cout << "Enter the row and column number to search for: ";
			cin >> row;
			cin >> column;
			cout << "Enter 1 to search vertically (top to bottom), 2 to search horizontally (left to right), 3 to search diagonally(upper left to lower right) and 4 to search diagonally(upper right to lower left) :";
			cin >> search_direction;

			while (search_direction != 0) {

				if (search_direction == 1) {

					search_vertically(word, row, column, alphabet_index, game_grid, counter,grid_size);

				}

				else if (search_direction == 2) {

					search_horizontally(word, row, column, alphabet_index, game_grid, counter, grid_size);

				}

				if (search_direction == 4) {

					search_diagonal_upperRight_to_lowerLeft(word, row, column, alphabet_index, game_grid, counter, grid_size);

				}

				if (search_direction == 3) {

					search_diagonal_upperLeft_to_lowerRight(word, row, column, alphabet_index, game_grid, counter, grid_size);

				}

				break;
			}
			cout << endl;

			cout << "Enter the word that I should search for. Press 'X' if you will not like to search for another word: ";
			cin >> word;
		}

		cout << "Press 1 if you would like to play the easy option, 2 for the medium option, 3 for the hard option and 4 to exit the game : " << endl;
		cout << "1) Easy" << endl << "2) Medium" << endl << "3) Hard" << endl << "4)Exit the game" << endl;
		cin >> difficulty_choice;
	}

	cout << counter << " word(s) found." << endl;

	if (word[0] == 'x' || word[0] == 'X') {

		cout << "Exiting game" << endl;

	}
	else if (difficulty_choice == 4) {

		cout << "Exiting Game" << endl;

	}
}