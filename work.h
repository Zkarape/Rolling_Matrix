#ifndef WORK_H
#define WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

typedef struct arr_change_for_each_etap
{
	int num;
	int i_nerka;
	int j_nerka;
	int pos_x_nerka;
	int pos_y_nerka;
} fake_arr;

void move_right_down(int i, int j, int m, int n, COORD pos, HANDLE the_console, int num);
void move_up_right(int i, int j, int m, int n, COORD pos, HANDLE the_console, int num);
int rolling_right(fake_arr change[], COORD pos, int start_x, int start_y, int n, int m, HANDLE the_console, int **arr);
int rolling_left(fake_arr change[], COORD pos, int start_x, int start_y, int n, int m, HANDLE the_console, int **arr);

#endif