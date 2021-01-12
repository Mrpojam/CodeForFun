#include<bits/stdc++.h>
using namespace std;

int table[3][3];

int check () {
	for (int i = 0; i < 3; i++) {
		if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != 0)
			return table[i][0];
		if (table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[0][i] != 0)	
			return table[0][i];
	}
	if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != 0)
		return table[0][0];
	if (table[0][2] == table [1][1] && table[1][1] == table[2][0] && table[0][2] != 0)
		return table[0][2];
	return 0;
}

inline void show () {
	for (int i =0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			if (table[i][j] == 0)
				cout << "|   |";
			else if (table[i][j] == 1)
				cout << "| X |";
	       		else
				cout << "| O |";
	cout << endl;	
	}
}

void play (int i, int j, int player) {	
	table[i][j] = player == 1 ? 1:2;
}

bool possible (int i, int j) {
	return !(table[i][j] != 0);
}

inline void cls() {system("clear");}


inline void execute() {
	int who = 1;
	while (!check()) {
		L:cls();
		show();
		cout << who << "'s turn" << endl;
		int i, j;
		cin >> i >> j;
		if (possible(i, j))
			play (i, j, who);
		else {
			goto L;
		}
		who = who == 1 ? 2:1;
	}
	cls();
	show();
	cout << check() << " Wins!" << endl;
}

int main () {
	execute();
	return 0;
}
