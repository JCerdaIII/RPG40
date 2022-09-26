//Fill out this comment with your names and which bullet points you did
//Partners:Johnnie Cerda, Baron Lopez, Hebah Fadah, Elena Mohler, Jesse Allen
//Bullet Points:1)World Map-Johnnie,Baron 2)Combat-Johnnie,Baron 3)Color-Whole Group 4)5 Puzzles-Elena 5)Dialoge/World descriptions-Jesse,Hebah
//Extra Credit: Inventory-Elena
//URL to cover art and music:
#include <iostream>
#include "/public/colors.h"
#include "/public/read.h"
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;
vector<string> world_map = {
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
	"~************************~~~~~~~~~~~~~~~~~~~*****************~~",
	"~*  1                   *~~~~~~~~~~~~~~~~~~~*               *~~",
	"~*                   a  *~~~~~~~~~~~~~~~~~~~*               *~~",
	"~*      2               *~~~~~~~~~~~~~~~~~~~*               *~~",
	"~*                      bt******************~               *~~",
	"~*                5     bt                  T         R     *~~",
	"~*  h                   bt******************~               *~~",
	"~*                      *~~~~~~~~~~~~~~~~~~~*               *~~",
	"~*   3          4       *~~~~~~~~~~~~~~~~~~~*               *~~",
	"~*                      *~~~~~~~~~~~~~~~~~~~*               *~~",
	"~************************~~~~~~~~~~~~~~~~~~~*****************~~",
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"


};


char get_world_location(size_t x, size_t y) {
	if (x >= world_map.size()) return ' ';
	if (y >= world_map.at(x).size()) return ' ';
	return world_map.at(x).at(y);
}

void set_world_location(size_t x, size_t y, char c) {
	if (x >= world_map.size()) return;
	if (y >= world_map.at(x).size()) return;
	world_map.at(x).at(y) = c;
}

void print_world(size_t player_x, size_t player_y) {
	clearscreen();
	movecursor(0, 0);
	for (size_t x = 0; x < world_map.size(); x++) {
		for (size_t y = 0; y < world_map.at(x).size(); y++) {
			if (x == player_x and y == player_y) cout << 'H';
			else
				cout << world_map.at(x).at(y);
		}
		cout << endl;
	}
}




int main() {
	char ans1;
	char inventoryAns;
	int weaponSword = 1;
	bool weaponAxe = false;
	bool weaponHalberd = false;
	int i;
	int keyCount = 0;
	int combatChance;
	int userHealth = 100;
	int miniBossHealth = 100;
	int bossHealth = 200;
	vector <string> inv(5);
	inv.at(0) = "Sword";
	string ans2;
	srand(time(NULL));
	for (int i = 0; i < 1; i++) {

		cout << YELLOW << "The Death of Rok" << endl;
		cout << RESET;
		sleep(2);
		clearscreen();
	}

	for (int i = 0; i < 1; i++) {
		cout << "The main island of the character lives on is called Tropical Paradise." << endl;
		cout << "This island has been around for many years and has been replaced by Kings and queens." << endl;
		cout << "This island has been in peace for a very long time until the day that Rok arrived." << endl;
		cout << "He came to the island and stole all of the wealth from the people in the village and kidnapped the king and queen." << endl;
		cout << "Hence who is a trained warrior is on the quest to defeat Rok and gets the village's wealth" << endl;
		cout << CYAN << "Hence: “I will take you down, freak.” minion: “ ha, don’t make me laugh.” (battle starts)" << RESET << endl;
		cout << RED << "Minion: “ you will never beat Rok.”" << RESET << endl;
		cout << CYAN << "Hence: “ I will and save my village.”" << RESET << endl;
		cout << RED << "Minion: “ How will you do that, you’re a weak creature." << RESET << endl;
		cout << CYAN <<  "Hence: “you’re all talk, actions will prove who’s stronger.”" << RESET << endl;
		cout << RED << "Minion: “ Ok, we’ll have a battle on the other part of the island and if you win you’ll get the village’s wealth back but if we win then we will keep the wealth we've stolen and control the whole village”" << RESET << endl;
		cout << CYAN << "” Hence: “ Ok, see you then loser”" << RESET << endl;
		sleep(20);
		clearscreen();
	}


	for (int i = 0; i < 1; i++) {
		cout << WHITE << "Because Hence felt responsible for everyone in the village, he felt he should win, but he didn't know how to get past the gate and traps set on the bridge. So he was highly stressed out just at the thought of it." << endl;
		cout << "During a night walk, he met a strange man who told him that the the village next to the bridge had people who had keys that can open the gate and disarm the traps." << RESET << endl;
		cout << CYAN << "Hence: “Wow, how would I get the keys from them these people?”" << RESET << endl;
		cout << GREEN << "A strange man: “They will ask you a riddle if you get the riddle right then you get one of five keys. Once you have all five keys you will be able to open the gate and dissarm the traps. There will also be weapons there that can help you with your battle.”" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << RESET;
		sleep(20);
		clearscreen();
	}


	const int ROWS = world_map.size(); 
	const int COLS = world_map.at(0).size();
	const int FPS = 60;
	int row = ROWS / 5, col = COLS / 5;
	int last_row = -1, last_col = -1;
	set_raw_mode(true);
	show_cursor(false);
	while (true) {
		int c = toupper(quick_read());
		if (c == 'Q') break;
		if (c == 'I') {
			cout << "Your inventory has 3 spots for wepons." << endl;
			for (i = 0; i < inv.size(); ++i) {
				cout << inv.at(i) << endl;
			}
			cout << "Keys: " << keyCount << "/5" << endl;
		}
		if (c == 'W') row--;
		if (c == 'S') row++;
		if (c == 'A') col--;

		if (c == 'D') col++;
		if (!(row == last_row and col == last_col)) {
			print_world(row, col);
			last_row = row;
			last_col = col;
			movecursor(2, COLS + 5);
			cout << YELLOW << "Movement key: W,A,S,D/ " << "Riddles: 1,2,3,4,5/ " << "Optional Weapons: a,h/ " << "Enemies: T, R " <<  RESET << endl;
			movecursor(ROWS + 2, 0);
			cout << "Welcome to the game" << endl;
			cout << "Press 'I' to check inventory" << endl;
			cout.flush();
		}
	


		if (get_world_location(row, col) == '*') {
			movecursor(ROWS + 2, 0);
			cout << YELLOW << "YOU ARE AT THE EDGE OF THE ISLAND TURN BACK OR YOU WILL DIE!!!" << endl;
			cout << RESET;
		}


		if (get_world_location(row, col) == '~') {
			movecursor(ROWS + 2, 0);
			clearscreen();
			cout << YELLOW << "YOU DIED!!!" << endl;
			cout << RESET;
			usleep(3);
			break;
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
				keyCount++;
				cout << "Keys: " << keyCount << "/5" << endl;
				set_raw_mode(true);
			}

		}


		if (get_world_location(row, col) == '2') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "What has a head and tail but no body?" << endl;
			cout << YELLOW << " a: cat, b: dog, c: coin    " << endl;
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
				keyCount++;
				cout << "Keys: " << keyCount << "/5" << endl;
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
				keyCount++;
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
				keyCount++;
				cout << "Keys: " << keyCount << "/5" << endl;
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
				keyCount++;
				cout << "Keys: " << keyCount << "/5" << endl;
				set_raw_mode(true);
			}

		}


		if (get_world_location(row, col) == 'a') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "Hence found a sturdy axe!!!" << endl;
			inv.at(1)  = "Axe";
			weaponAxe = true;
		}
		if (get_world_location(row, col) == 'h') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "Hence found a halberd!!!" << endl;
			inv.at(2) = "Halberd";
			weaponHalberd = true;
		}
		 		
	
		if (get_world_location(row, col) == 'b') {
			movecursor(ROWS + 2, 0);

			if (keyCount == 5) {
				cout << "Traps are now disarmed you can now cross the bridge safely." << endl;
			} else {
				cout << "You do not have 5 keys yet" << endl;
				cout << "If you step on 't' (trap) with out the 5 keys to disarm them you will die!!!" << endl;
			}
		}


		if (get_world_location(row, col) == 't' and keyCount == 5) {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "You unarmed the trap" << endl;
		} else if (get_world_location(row, col) == 't' and keyCount != 5) {
			clearscreen();
			cout << YELLOW << "YOU DIED!!!" << endl;
			cout << RESET;
			usleep(3);
			break;

		}

	

		if (get_world_location(row, col) == 'T') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "You have enetered a duel with Thrak who is Rok's favorite commander!!!" << endl;
			cout << YELLOW << "Thrak: “You must be the warrior name Hence that mater Rok was talking about.”" << endl;
			cout << RESET;
			cout << CYAN << "Hence: “Thats Right, and I came here to take back what belongs to the village.”" << endl;
			cout << RESET;
			cout << YELLOW << "Thrak: “Hehe good luck with that, you can’t beat me and master Rok.”" << endl;
			cout << RESET;
			cout << CYAN << "Hence: “We will see about that.”" << endl;
			cout << RESET;
			set_raw_mode(false);
			while (miniBossHealth > 0) {
				cout << "f: Fight or i: Inventory" << endl;
				cin >> ans1;
				if (ans1 == 'f') {


					cout << "s. Sword, a. Axe, or h. halberd" << endl;
					cin >> ans1;
					if (ans1 == 's') {
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
						}
					}
					if (ans1 == 'a' and weaponAxe == true) {
						cout << "Hence tries to strike the enemy axe!!!" << endl;
						combatChance = rand() % 100;
						if (combatChance <= 14 && combatChance >= 0) {
							cout << "Hence's strike made contact!!!" << endl;
							miniBossHealth = miniBossHealth - 45;
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

						}
					} else if (ans1 == 'a' and weaponAxe == false) {
						cout << "You do not have an axe in your inventory!" << endl;
					}

					if (ans1 == 'h' and weaponHalberd == true) {
						cout << "Hence tries to strike the enemy halberd!!!" << endl;
						combatChance = rand() % 100;
						if (combatChance <= 79 && combatChance >= 0) {
							cout << "Hence's strike made contact!!!" << endl;
							miniBossHealth = miniBossHealth - 10;
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

						}
					} else if (ans1 == 'h' and weaponHalberd == false) {
						cout << "You do not have a halberd in your inventory!" << endl;
					}


				}
	
			}
						
			cout << RED  << "Thrak: “Thats impossible I LOST!”" << endl;
			cout << "Thrak: “You maybe good kid but your power will never compared to Master Rok.”" << RESET << endl;
			cout << CYAN << "Hence: “Sure bud and now go back to the underworld freak”" << RESET << endl;
			cout << YELLOW << "DO NOT MOVE UP OR DOWN BECAUSE YOU WILL FALL OFF THE ISLAND!!!" << RESET << endl;
			cout << "Thrak went back where he came from and Hence continued his journey" << endl;
			cout << "Press 'a' or 'd' to contiune." << endl;
			if (userHealth < 80) {
				cout << "Hence treated his wounds to prepare for the final battle against Rok" << endl;
				userHealth = 80;
			}
			set_raw_mode(true);

		}


		if (get_world_location(row, col) == 'R') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "Now it's time that Rok and Hence fight!!!" << endl;
			cout << RED << "Rok: “Today everyone will know that I am the boss of the village and no one can beat me.”" << RESET << endl;
			cout << CYAN << "Hence: “Stop dreaming this village will be free and no one can control us.”" << RESET << endl;
			cout << RED << "Rok: “Ha, we will see”" << RESET << endl;
			set_raw_mode(false);
			while (bossHealth > 0) {
				cout << "f: Fight or i: Inventory" << endl;
				cin >> ans1;
				if (ans1 == 'f') {
					cout << "s. Sword, a. Axe, or h. halberd" << endl;
					cin >> ans1;
					if (ans1 == 's') {
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
								userHealth = userHealth - 10;
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
					if (ans1 == 'a') {
						cout << "Hence tries to strike the enemy axe!!!" << endl;
						combatChance = rand() % 100;
						if (combatChance <= 14 && combatChance >= 0) {
							cout << "Hence's strike made contact!!!" << endl;
							bossHealth = bossHealth - 45;
							if (bossHealth > 0) {
								cout << "Rok's health is " << bossHealth << "/200 HP" << endl;
							}
						} else {
							cout << "OH NO!!! Hence's strike made no contact" << endl;
							cout << "Rok lunges at Hence!!!" << endl;
							combatChance = rand() % 100;
							if (combatChance <= 49 && combatChance >= 0) {
								cout << "Rok inflicted damage on Hence!!!" << endl;
								userHealth = userHealth - 10;
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

					if (ans1 == 'h') {
						cout << "Hence tries to strike the enemy halberd!!!" << endl;
						combatChance = rand() % 100;
						if (combatChance <= 79 && combatChance >= 0) {
							cout << "Hence's strike made contact!!!" << endl;
							bossHealth = bossHealth - 10;
							if (bossHealth > 0) {
								cout << "Rok's health is " << bossHealth << "/200 HP" << endl;
							}
						} else {
							cout << "OH NO!!! Hence's strike made no contact" << endl;
							cout << "Rok lunges at Hence!!!" << endl;
							combatChance = rand() % 100;
							if (combatChance <= 49 && combatChance >= 0) {
								cout << "Rok inflicted damage on Hence!!!" << endl;
								userHealth = userHealth - 10;
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
				}




			}
			set_raw_mode(true);
			clearscreen();
			cout << "Hence wins!!!" << endl;
			cout << RED << "Rok: “I will come back and destroy the whole village”" << RESET << endl;
			cout << CYAN << "Hence: “Second time we will kill you, so my advice to you is do not come back freak.”" << RESET << endl;
			sleep(5);
			clearscreen();
			cout << "Everyone was happy in the village." << endl;
			cout << GREEN << "King and Queen: “Thanks Hence you save our lives and brought back all the wealth to the village.”" << RESET << endl;
			cout << CYAN << "Hence: “This is my duty to my village”" << RESET << endl;
			sleep(5);
			cout << "YOU WIN!!!" << endl;
			sleep(5);
			break;
			//set_raw_mode(true);
		}

	}
}
