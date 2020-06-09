#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

using namespace std;
int main() {
	//opens txt file
	ofstream myfile;
	myfile.open("GameScores.txt");
	//init map and display where the user is at
	GameWorld map;
	
	string name;
	cout << "Enter Your name please: ";
	cin >> name;
	int quit = 0,points = 0;
	char choice;
	map.displaymove();
	do {
		//to get input
		cout << "\nEnter 'i' to move the playerup\nEnter 'k' to move the player down\n";
		cout << "Enter 'j' to move left\nEnter 'L' tp move right\nEnter 'V' to display the visible world\n";
		cout << "Enter c to cheat and see the whole world\nEnter r to restart the game with the same player\n";
		cout << "Enter n to restart with a new player\nenter q to end the game";
		cin >> choice;
		cout << endl;

		//check input, then do the corresponding task
		if (choice == 'i' || choice == 'I') {
			map.moveUp();
			map.displaymove();
			points += 5;
		}
		else if (choice == 'k' || choice == 'K') {
			map.moveDown();
			map.displaymove();
			points += 5;
		}
		else if (choice == 'j' || choice == 'J') {
			map.moveLeft();
			map.displaymove();
			points += 5;
		}
		else if (choice == 'l' || choice == 'L') {
			map.moveRight();
			map.displaymove();
			points += 5;
		}
		else if (choice == 'v' || choice == 'V') {
			map.displayVisibleWorld();
			points -= 2;
		}
		else if (choice == 'c' || choice == 'C') {
			map.displayEntireWorld();
			points -= 5;
		}
		else if (choice == 'r' || choice == 'R') {
			map = GameWorld();//wasnt sure if i was suppoused to set the players points back to zero so i left it
		}

		//prints pevious players score to the txt file then gets new player
		else if (choice == 'n' || choice == 'N') {
			myfile << name<<" had: "<<points<<" points"<<endl;
			points = 0;
			cout << "Enter Your name please: ";
			cin >> name;
			map = GameWorld();
		}
		else if (choice == 'q' || choice == 'Q') {
			quit = 1;
		}
		else
			cout << "\nEnter a valid input please\n";
	} while (map.amIAlive()==1 && map.haveIWon()==0&&quit==0);

	//prints to console depending on how the game ended
	if (quit == 1)
		cout << "\nyou quit\n";
	else if (map.amIAlive() != 1)
		cout << "\nyou died\n";
	else if (map.haveIWon() != 0)
		cout << "\nyou won!\n";
	
	//prints and closes to .txt file
	myfile <<endl<< name<<" had: " << points << "points";
	myfile.close();
	return 0;
}