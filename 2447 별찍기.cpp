#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
 
#define MAX_SIZE 16
#define INF 0x7fffffff
using namespace std;

char arr[7000][7000];
int n;
void draw(int x, int  y, int n, char c){
   if (n == 1) {
      arr[x][y] = c;
      return;
   }
   int len = n/3;
	if(c == '*'){
      draw(x,y,len,'*');
      draw(x,y+len,len,'*');
      draw(x,y+len*2,len,'*');
      draw(x+len,y,len,'*');
      draw(x+len,y+len,len,' ');
      draw(x+len,y+len*2,len,'*');
      draw(x+len*2,y,len,'*');
      draw(x+len*2,y+len,len,'*');
      draw(x+len*2,y+len*2,len,'*');
   }
	else{
      for(int i = x; i < x + n; i++) {
         for(int j = y; j < y + n; j++) 
            arr[i][j] = ' ';
      }
  }
   return;
}

int main() {
   cin>>n;
   draw(0, 0,n,'*');

   for (int i = 0; i < n; i++) {
      for(int j = 0 ; j < n ; j++)
      	printf("%c", arr[i][j]);
    printf("\n");
   }
}
