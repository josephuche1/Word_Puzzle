//Name:Uche Joseph Ugochukwu
//ID Number: U221N1068
// PROJECT 1

#include <iostream>
#include <cstring>
using namespace std;
const int len = 20;
void puzzle(int x,char difficulty[len][len], int &s) {
	int i, j;
	char c;
	if (x == 1) {
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 6; j++) {
				c = 65 + rand() % 26;
				difficulty[i][j] = c;
				cout << difficulty[i][j] << " ";
			}
			cout << endl;
		}
		s = 6;
	}
	else if (x == 2) {
		for (i = 0; i < 14; i++) {
			for (j = 0; j < 14; j++) {
				c = 65 + rand() % 26;
				difficulty[i][j] = c;
				cout << difficulty[i][j] << " ";
			}
			cout << endl;
		}
		s = 14;
	}
	else if (x == 3) {
		for (i = 0; i < 20; i++) {
			for (j = 0; j < 20; j++) {
				c = 65 + rand() % 26;
				difficulty[i][j] = c;
				cout << difficulty[i][j] << " ";
			}
			cout << endl;
		}
		s = 20;
	}

}
int main() {

	char word[len], difficulty[len][len];
	int x,s, counter = 0;
	cout << "Welcome" << endl;
	cout << "Press 1 if you would like to play the easy option,2 for the medium option, 3 for the hard option and 4 to exit the game : " << endl;
	cout << "1) Easy" << endl << "2) Medium" << endl << "3) Hard" << endl << "4)Exit the game" << endl;
	cin >> x;
	while (x != 4) {
		puzzle(x, difficulty,s);

		cout << "Enter the word that I should search for. Press 'X' if you will not like to search for another word: ";
		cin >> word;
		while (word[0] != 'x' && word[0] != 'X') {
			int row, col, m, o = 0;
			cout << "Enter the row and column number to search for: ";
			cin >> row;
			cin >> col;
			cout << "Enter 1 to search vertically (top to bottom), 2 to search horizontally (left to right), 3 to search diagonally(upper left to lower right) and 4 to search diagonally(upper right to lower left) :";
			cin >> m;
			while (m != 0) {
				if (m == 1) {
					int r1 = row;
					while (row < s) {
						while (o < strlen(word)) {
							if (difficulty[row][col] == word[o]) {
								o++;
								break;
							}
							else { break; }
						}
						row++;
					}
					if (o >= strlen(word)) {
						cout << "The word has been found." << endl;
						counter++;
					}
					else {
						cout << "The word has not been found in row " << r1 << ", and column " << col << ", and vertical direction." << endl;
					}
				}
				if (m == 2) {
					int c2 = col;
					while (col < s) {
						while (o < strlen(word)) {
							if (difficulty[row][col] == word[o]) {
								o++;
								break;
							}
							else { break; }
						}
						col++;
					}
					if (o >= strlen(word)) {
						cout << "The word has been found." << endl;
						counter++;
					}
					else {
						cout << "The word has not been found in row " << row << ", and column " << c2 << ", and horizontal direction." << endl;

					}
				}
				if (m == 4) {
					int c4 = col;
					int r4 = row;
					while (row < s && col < s) {
						if (row + col >= col) {
							while (o < strlen(word)) {
								if (difficulty[row][col] == word[o]) {
									o++;
									break;
								}
								else { break; }
							}
						}
						col--;
						row++;
					}
					if (o >= strlen(word)) {
						cout << "The word has been found." << endl;
						counter++;
					}
					else {
						cout << "The word has not been found in row " << r4 << ", and column " << c4 << ", and right diagonal direction." << endl;

					}
				}
				if (m == 3) {
					int r3 = row;
					int c3 = col;
					while (row < s && col < s) {
						if (row - col <= col) {
							while (o < strlen(word)) {
								if (difficulty[row][col] == word[o]) {
									o++;
									break;
								}
								else { break; }
							}
						}
						col++;
						row++;
					}
					if (o >= strlen(word)) {
						cout << "The word has been found." << endl;
						counter++;
					}
					else {
						cout << "The word has not been found in row " << r3 << ", and column " << c3 << ", and left diagonal direction." << endl;
					}
				}
				break;
			}
			cout << endl;
			cout << "Enter the word that I should search for. Press 'X' if you will not like to search for another word: ";
			cin >> word;
		}
		cout << "Press 1 if you would like to play the easy option, 2 for the medium option, 3 for the hard option and 4 to exit the game : " << endl;
		cout << "1) Easy" << endl << "2) Medium" << endl << "3) Hard" << endl << "4)Exit the game" << endl;
		cin >> x;
	}
	cout << counter << " word(s) found." << endl;
	if (word[0] == 'x' || word[0] == 'X') {
		cout << "Exiting game" << endl;
	}
	else if (x == 'd') {
		cout << "Exiting Game" << endl;
	}
}