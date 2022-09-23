//Fill out this comment with your names and which bullet points you did
//Partners:
//Bullet Points:
//Extra Credit:
//URL to cover art and music:

#include <iostream>
#include "/public/colors.h"
#include "/public/read.h"
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;
vector<string> world_map = {

	"***********************",
	"*   5                  *",
	"*                   b  *",
	"*   7                  *",
	"*             4        *",
	"*      3               *",
	"*          2           *",
	"* 1                    *",
	"*                  6   *",
	"*                      *",
	"***********************"


};

vector <string> world_map2 = {

	"***********************",
	"*   0                  *",
	"*                   v  *",
	"*                      *",
	"*             9        *",
	"*      8               *",
	"*          7           *",
	"* 6                    *",
	"*                      *",
	"*                      *",
	"***********************"

};

char get_world_location(size_t row, size_t col) {
	if (row >= world_map.size()) return ' ';
	if (col >= world_map.at(row).size()) return ' ';
	return world_map.at(row).at(col);
}

void set_world_location(size_t row, size_t col, char c) {
	if (row >= world_map.size()) return;
	if (col >= world_map.at(row).size()) return;
	world_map.at(row).at(col) = c;
}

void print_world(size_t player_row, size_t player_col) {
	clearscreen();
	movecursor(0, 0);
	for (size_t row = 0; row < world_map.size(); row++) {
		for (size_t col = 0; col < world_map.at(row).size(); col++) {
			if (row == player_row and col == player_col) cout << 'h';
			else
				cout << world_map.at(row).at(col);
		}
		cout << endl;
	}
}

int main() {
	char ans1;
	char inventoryAns;
	int combatChance;
	int userHealth = 100;
	int miniBossHealth = 100;
	int bossHealth = 200;
	string ans2;
	srand(time(NULL));
	for (int i = 0; i < 1; i++) {

		cout << YELLOW << "Title" << endl;
		cout << RESET;
		sleep(2);
		clearscreen();
	}

	for (int i = 0; i < 1; i++) {
		cout << CYAN << "The main island of the character lives on is called Tropical Paradise." << endl;
		cout << "This island has been around for many years and has been replaced by Kings and queens." << endl;
		cout << "This island has been in peace for a very long time until the day that Rok arrived." << endl;
		cout << "He came to the island and stole all of the wealth from the people in the village and kidnapped the king and queen." << endl;
		cout << "Hence who is a trained warrior is on the quest to defeat Rok and gets the village's wealth" << endl;
		cout << "Hence: “I will take you down, freak.” minion: “ ha, don’t make me laugh.” (battle starts)" << endl;
		cout << "Minion: “ you will never beat Rok.” Hence: “ I will and save my village.”" << endl;
		cout << "Minion: “ How will you do that, you’re a weak creature. Hence: “you’re all talk, actions will prove who’s stronger.”" << endl;
		cout << "Minion: “ Ok, we’ll have a battle in 3 days and if you win you’ll get the village’s wealth back but if I win then I’ll keep the wealth I’ve stolen and control the whole village”" << endl;
		cout << "” Hence: “ Ok, see you then loser”" << endl;
		cout << RESET;
		sleep(2);
		clearscreen();
	}


	for (int i = 0; i < 1; i++) {
		cout << CYAN << "Hence: “I will take you down, freak.”" << endl;
		cout << "minion: “ ha, don’t make me laugh.” (battle starts)" << endl;
		cout << "Minion: “ you will never beat Rok.”" << endl;
		cout << "Hence: “ I will and save my village.”" << endl;
		cout << "Minion: “ How will you do that, you’re a weak creature." << endl;
		cout << "Hence: “you’re all talk, actions will prove who’s stronger.”" << endl;
		cout << "Minion: “ Ok, we’ll have a battle in 3 days and if you win you’ll get the village’s wealth back but if I win then I’ll keep the wealth I’ve stolen and control the whole village”" << endl;
		cout << "” Hence: “ Ok, see you then loser”" << endl;
		cout << RESET;
		sleep(2);
		clearscreen();
	}

	for (int i = 0; i < 1; i++) {
		cout << CYAN << "Because Hence felt responsible for everyone in the village, he felt he should win, but he knew he wasn't strong enough to win, so he was highly stressed out just at the thought of losing." << endl;
		cout << "During a night walk, he met a strange man who told him there was a faraway island and that if he went there and solved all the puzzles, he would have a special power that enabled him to defeat anyone." << endl;
		cout << "Hence: “Wow, but how can I get there? I need to go fast because the battle is in 3 days.”" << endl;
		cout << "A strange man: “At the highest point of this mountain, there is a magic carpet that you can take if you answer the question correctly, and it will take you there and back in two days.”" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << RESET;
		sleep(2);
		clearscreen();
	}


	const int ROWS = world_map.size();
	const int COLS = world_map.at(0).size();
	const int FPS = 60;
	int row = ROWS / 2, col = COLS / 2;
	int last_row = -1, last_col = -1;
	set_raw_mode(true);
	show_cursor(false);
	while (true) {
		int c = toupper(quick_read());
		if (c == 'Q') break;
		if (c == 'W' /*or c == UP_ARROW*/) row--;
		if (c == 'S' /*or c == DOWN_ARROW*/) row++;
		if (c == 'A' /*or c == LEFT_ARROW*/) col--;
		if (c == 'D' /*or c == RIGHT_ARROW*/) col++;
		if (!(row == last_row and col == last_col)) {
			print_world(row, col);
			last_row = row;
			last_col = col;
			movecursor(2, COLS + 5);
			cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
			movecursor(ROWS + 2, 0);
			cout << "Welcome to the game" << endl;
			cout.flush();
		}

		if (get_world_location(row, col) == '1') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "I am an odd number. Take away a letter and I become even. What number am I?" << endl;
			cout << YELLOW << " a: seven, b: nine, c: three " << endl;
			cout << RESET;
			set_raw_mode(false);
			cin >> ans1;
			while (ans1 != 'a') {
				if (ans1 == 'b') {
					cout << "Try again!!" << endl;
					cin >> ans1;
				}
				if (ans1 == 'c') {
					cout << "Try again!!" << endl;
					cin >> ans1;
				} else {
					cout << "Only answer with a, b, or c" << endl;
					cin >> ans1;
				}
			}
			if (ans1 == 'a') {
				cout << "Good Job" << endl;
				set_raw_mode(true);
			}

		}


		if (get_world_location(row, col) == '2') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "What has a head and tail but no body?" << endl;
			cout << YELLOW << " a: cat, b: dog, c: coin " << endl;
			cout << RESET;
			set_raw_mode(false);
			cin >> ans1;
			while (ans1 != 'c') {
				if (ans1 == 'b') {
					cout << "Try again!!" << endl;
					cin >> ans1;
				}
				if (ans1 == 'a') {
					cout << "Try again!!" << endl;
					cin >> ans1;
				} else {
					cout << "Only answer with a, b, or c" << endl;
					cin >> ans1;
				}
			}
			if (ans1 == 'c') {
				cout << "Good Job" << endl;
				set_raw_mode(true);
			}

		}


		if (get_world_location(row, col) == '3') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "Three times what number is no larger than two times that same number " << endl;
			cout << YELLOW << " a: seven, b: nine, c: zero " << endl;
			cout << RESET;
			set_raw_mode(false);
			cin >> ans1;
			while (ans1 != 'c') {
				if (ans1 == 'b') {
					cout << "Try again!!" << endl;
					cin >> ans1;
				}
				if (ans1 == 'a') {
					cout << "Try again!!" << endl;
					cin >> ans1;
				} else {
					cout << "Only answer with a, b, or c" << endl;
					cin >> ans1;
				}
			}
			if (ans1 == 'c') {
				cout << "Good Job" << endl;
				set_raw_mode(true);
			}

		}


		if (get_world_location(row, col) == '4') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "What can you break, even if you never pick it up or touch it." << endl;
			cout << YELLOW << " a: A stick, b: Ice, c: A promise  " << endl;
			cout << RESET;
			set_raw_mode(false);
			cin >> ans1;
			while (ans1 != 'c') {
				if (ans1 == 'a') {
					cout << "Try again!!" << endl;
					cin >> ans1;
				}
				if (ans1 == 'b') {
					cout << "Try again!!" << endl;
					cin >> ans1;
				} else {
					cout << "Only answer with a, b, or c" << endl;
					cin >> ans1;
				}
			}
			if (ans1 == 'c') {
				cout << "Good Job" << endl;
				set_raw_mode(true);
			}

		}


		if (get_world_location(row, col) == '5') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "What is yours but mostly used by others?" << endl;
			cout << YELLOW << "  a: your shoes , b: your name, c: your book " << endl;
			cout << RESET;
			set_raw_mode(false);
			cin >> ans1;
			while (ans1 != 'b') {
				if (ans1 == 'a') {
					cout << "Try again!!" << endl;
					cin >> ans1;
				}
				if (ans1 == 'c') {
					cout << "Try again!!" << endl;
					cin >> ans1;
				} else {
					cout << "Only answer with a, b, or c" << endl;
					cin >> ans1;
				}
			}
			if (ans1 == 'b') {
				cout << "Good Job" << endl;
				set_raw_mode(true);
			}

		}

		if (get_world_location(row, col) == 'b') {
			movecursor(ROWS + 2, 0);
			cout << "YOU WIN!!!!" << endl;
			usleep(3);
			break;
		}
		if (c == ERR) usleep(1'000'000 / FPS);



		if (get_world_location(row, col) == '6') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "You have enetered a duel with the mini Boss of Rok, Thrak!!!" << endl;
			cout << YELLOW << "What will Hence do?" << endl;
			cout << RESET;
			set_raw_mode(false);
			while (miniBossHealth > 0) {
				cout << "f: Fight or i: Inventory" << endl;
				cin >> ans1;
				if (ans1 == 'f') {
					cout << "Hence tries to strike the enemy!!!" << endl;
					combatChance = rand() % 100;
					if (combatChance <= 49 && combatChance >= 0) {
						cout << "Hence's strike made contact!!!" << endl;
						miniBossHealth = miniBossHealth - 15;
						if (miniBossHealth > 0) {
							cout << "Thrak's health is " << miniBossHealth << "/100 HP" << endl;
						}
					} else {
						cout << "OH NO!!! Hence's strike made no contact" << endl;
						cout << "Thrak lunges at Hence!!!" << endl;
						combatChance = rand() % 100;
						if (combatChance <= 49 && combatChance >= 0) {
							cout << "Thrak inflicted damage on Hence!!!" << endl;
							userHealth = userHealth - 10;
							if (userHealth > 0) {
								cout << "Hence's health is " << userHealth << "/100 HP" << endl;
							} else if (userHealth <= 0) {
								cout << "Hence has been defeated!!!" << endl;
								cout << "GAME OVER" << endl;
								return 0;
							}
						} else {
							cout << "Thrak's attack missed!!!" << endl;
						}
						if (ans1 == 'i') {
							cout << "Would you like to change your weapon, take a potion, or raise stats?" << endl;
							cin >> inventoryAns; // Must fix later!!!
						}
					}
				}
			}
			cout << "Thrak: Argh I'm dying" << endl;
			cout << "Hence defeated Thrak!!!" << endl;
			set_raw_mode(true);

		}
		if (get_world_location(row, col) == '7') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "You have enetered a duel with the Boss, Rok!!!" << endl;
			cout << YELLOW << "What will Hence do?" << endl;
			cout << RESET;
			set_raw_mode(false);
			while (bossHealth > 0) {
				cout << "f: Fight or i: Inventory" << endl;
				cin >> ans1;
				if (ans1 == 'f') {
					cout << "Hence tries to strike the enemy!!!" << endl;
					combatChance = rand() % 100;
					if (combatChance <= 49 && combatChance >= 0) {
						cout << "Hence's strike made contact!!!" << endl;
						bossHealth = bossHealth - 15;
						if (bossHealth > 0) {
							cout << "Rok's health is " << bossHealth << "/200 HP" << endl;
						}
					} else {
						cout << "OH NO!!! Hence's strike made no contact" << endl;
						cout << "Rok lunges at Hence!!!" << endl;
						combatChance = rand() % 100;
						if (combatChance <= 49 && combatChance >= 0) {
							cout << "Rok inflicted damage on Hence!!!" << endl;
							userHealth = userHealth - 20;
							if (userHealth > 0) {
								cout << "Hence's health is " << userHealth << "/100 HP" << endl;
							} else if (userHealth <= 0) {
								cout << "Hence has been defeated!!!" << endl;
								cout << "GAME OVER" << endl;
								return 0;
							}
						} else {
							cout << "Rok's attack missed!!!" << endl;
						}
					}
				}
				if (ans1 == 'i') {
					cout << "Would you like to change your weapon, take a potion, or raise stats?" << endl;
					cin >> inventoryAns; // Must fix later!!!
				}
			}
			cout << "Rok: Argh I'm dying" << endl;
			cout << "Hence defeated Rok!!!" << endl;
			set_raw_mode(true);
		}

	}
}
