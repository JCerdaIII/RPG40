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
	"*                      *",
	"*             4        *",
	"*      3               *",
	"*          2           *",
	"* 1                    *",
	"*                      *",
	"*                      *",
	"***********************"


	};

char get_world_location(size_t row, size_t col){
	if ( row >= world_map.size()) return ' ';
	if (col >= world_map.at(row).size()) return ' ';
	return world_map.at(row).at(col);
}

void set_world_location(size_t row, size_t col, char c){
	if (row >= world_map.size()) return;
	if (col >= world_map.at(row).size()) return;
	world_map.at(row).at(col) = c;
}

void print_world(size_t player_row, size_t player_col){
	clearscreen();
	movecursor(0,0);
	for (size_t row = 0; row < world_map.size(); row++){
	for (size_t col = 0; col < world_map.at(row).size(); col++){
		if (row == player_row and col == player_col) cout << 'h';
		else
			cout << world_map.at(row).at(col);
	}
	cout << endl;
	}
}

int main() {
	int ans = 0;
	for (int i = 0; i < 1; i++) {
		
	cout << YELLOW << "Title" << endl;
		cout << RESET;
		sleep(2);
		clearscreen();
	}

	for (int i = 0; i < 1; i++){
	cout << CYAN << "The main island of the character lives on is called Tropical Paradise." << endl;
	cout << "This island has been around for many years and has been replaced by Kings and queens." << endl;
	cout << "This island has been in peace for a very long time until the day that Rok arrived." << endl; 
	cout << "He came to the island and stole all of the wealth from the people in the village and kidnapped the king and queen." << endl;
	cout << "Hence who is a trained warrior is on the quest to defeat Rok and gets the village's wealth" << endl;
	cout << RESET;
	sleep (2);
	clearscreen();
	}
	
	const int ROWS = world_map.size();
	const int COLS = world_map.at(0).size();
	const int FPS = 60;
	int row = ROWS/2, col = COLS/2;
	int last_row = -1,last_col = -1;
	set_raw_mode(true);
	show_cursor(false);
	while(true){
		int c = toupper(quick_read());
		if (c == 'Q') break;
		if (c == 'W' /*or c == UP_ARROW*/) row--;
		if (c == 'S' /*or c == DOWN_ARROW*/) row++;
		if (c == 'A' /*or c == LEFT_ARROW*/) col--;
		if (c == 'D' /*or c == RIGHT_ARROW*/) col++;
		if (!(row == last_row and col == last_col)) {
			print_world(row,col);
			last_row = row;
			last_col = col;
			movecursor(2,COLS+5);
			cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
			movecursor(ROWS+2,0);
			cout << "Welcome to the game" << endl;
			cout.flush();
		}
		if (get_world_location(row, col) == '1'){
			set_world_location(row,col,' ');
			movecursor(ROWS+2,0);
			cout << "What is 1 + 1?" << endl;
			cin >> ans;
			while (ans != 2){
			if (!cin) {
			cout << "Wrong answer" << endl;
			cin >> ans;
			}
			cout << "Wrong answer" << endl;
			cin >> ans;
			}
			if (ans == 2){
				cout << "Good Job" << endl;
			}
			
		}
		if (get_world_location(row, col) == '5'){
			movecursor(ROWS+2,0);
			cout << "YOU WIN!!!!" << endl;
			usleep(3);
			break;
		}
		if (c == ERR) usleep(1'000'000 / FPS);
		}
	}
	


