#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<utility>
#define MAX 20
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
using namespace std;
int r, c, x, y, n, dir, nx, ny;
int map[MAX][MAX];
int dice[7] = { 0,0,0,0,0,0,0};
void change_dice() {

	if (dir == EAST) {
		swap(dice[1], dice[4]);
		swap(dice[4], dice[3]);
		swap(dice[4], dice[6]);
	}

	else if (dir == WEST) {
		swap(dice[1], dice[3]);
		swap(dice[3], dice[6]);
		swap(dice[4], dice[6]);
	}

	else if (dir == SOUTH) {
		swap(dice[1], dice[2]);
		swap(dice[2], dice[6]);
		swap(dice[5], dice[6]);
	}
	else if(dir == NORTH){
		swap(dice[1], dice[2]);
		swap(dice[1], dice[5]);
		swap(dice[5], dice[6]);
	}
}
int main() {
	cin >> r >> c >> x >> y >> n;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &map[i][j]);
	while (n--) {
		scanf("%d", &dir);
		if (dir == EAST) {
			nx = x; 
			ny = y + 1;
		}
		else if (dir == WEST) {
			nx = x;
			ny = y - 1;
		}
		else if (dir == NORTH) {
			nx = x - 1;
			ny = y;
		}
		else {
			nx = x + 1;
			ny = y;
		}
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		x = nx; 
		y = ny; // renew current pos
		change_dice(); // renew dice
		if (map[x][y]) { 
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		else map[x][y] = dice[6];
		printf("%d\n", dice[1]);
	}
}