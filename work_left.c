#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>

typedef struct arr_change_for_each_etap
{
	int num;
	int i_nerka;
	int j_nerka;
	int pos_x_nerka;
	int pos_y_nerka;
} fake_arr;

void move_left_down(int i, int j, int m, int n, COORD pos, HANDLE the_console, int num)
{
	int i1 = 0;
	int j1 = 0;
	while (++i1 <= m + n - i - j - 2)
	{
		printf("   ");
		pos.X -= 8;
		SetConsoleCursorPosition(the_console, pos);
		printf("%d", num);
		pos.X += 3;
		Sleep(200);
		SetConsoleCursorPosition(the_console, pos);
		printf("   ");
	}
	while (++j1 <= m - n - i + j)
	{
		printf("   ");
		pos.X -= 3;
		pos.Y += 2;
		SetConsoleCursorPosition(the_console, pos);
		printf("%d", num);
		//pos.X += 2;
		Sleep(200);
		SetConsoleCursorPosition(the_console, pos);
		//printf("   ");
	}
}

void move_up_left(int i, int j, int m, int n, COORD pos, HANDLE the_console, int num)
{
	int i1 = 0;
	int j1 = 0;
	while (--j1 >= m - n - i + j)
	{
		printf("   ");
		pos.X -= 3;
		pos.Y -= 2;
		SetConsoleCursorPosition(the_console, pos);
		printf("%d", num);
		pos.X += 3;
		Sleep(200);
		SetConsoleCursorPosition(the_console, pos);
		printf("   ");
	}
	while (++i1 <= m + n - i - j - 2)
	{
		printf("   ");
		pos.X -= 8;
		SetConsoleCursorPosition(the_console, pos);
		printf("%d", num);
		pos.X += 3;
		Sleep(200);
		SetConsoleCursorPosition(the_console, pos);
		printf("   ");
	}
}

int rolling_left(fake_arr change[], COORD pos, int start_x, int start_y, int n, int m, HANDLE the_console, int **arr)
{
	int i = -1;
	int j = 0;
	int a = 0;
	int start_x_for_left = start_x;
	//start_x_for_left = start_x - (n - 1) * 5;
	while (start_x_for_left > 2)
	{
		// 1st etap
		// changing indices of numbers as they are items of "generated" matrix
		a = 0;
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				change[a].num = arr[i][j];
				a++;
			}
		}
		a = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			for (int i = 0; i < m; i++)
			{
				change[a].i_nerka = i;
				change[a].j_nerka = j;
				a++;
			}
		}
		int i2 = 0;
		int j2 = 0;
		a = 0;
		while (a < m * n)
		{
			i2 = change[a].i_nerka;
			j2 = change[a].j_nerka;
			pos.X = start_x_for_left - 5 * j2 + 1;
			pos.Y = start_y + 2 * i2;
			SetConsoleCursorPosition(the_console, pos);
			printf("  ");
			// in case of < 0, moving up then left
			if (m - n - i2 + j2 < 0)
			{
				move_up_left(i2, j2, m, n, pos, the_console, change[a].num);
			}
			// in case of > 0, move left then down
			else
			{
				move_left_down(i2, j2, m, n, pos, the_console, change[a].num);
			}
			a++;
		}
		// 2nd etap
		a = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			for (int i = 0; i < m; i++)
			{
				change[a].num = arr[i][j];
				a++;
			}
		}
		// changing indices of numbers as they are items of "to right generated" matrix
		a = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				change[a].i_nerka = i;
				change[a].j_nerka = j;
				a++;
			}
		}
		a = 0;
		start_x_for_left = start_x_for_left - 5 * (n - 1);
		start_y = start_y + 2 * (abs(m - n));
		while (a < m * n)
		{
			i2 = change[a].i_nerka;
			j2 = change[a].j_nerka;
			pos.X = start_x_for_left - 5 * j2 + 1;
			pos.Y = start_y + 2 * i2;
			SetConsoleCursorPosition(the_console, pos);
			printf("  ");
			// in case of < 0, moving up then right
			if (n - m - i2 + j2 < 0)
			{
				move_up_left(i2, j2, n, m, pos, the_console, change[a].num);
			}
			// in case of > 0, move right then down
			else
			{
				move_left_down(i2, j2, n, m, pos, the_console, change[a].num);
			}
			a++;
		}
		// 3rd etap
		a = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			for (int i = m - 1; i >= 0; i--)
			{
				change[a].num = arr[i][j];
				a++;
			}
		}
		// changing indices of numbers as they are items of "new generated" matrix
		a = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			for (int i = 0; i < m; i++)
			{
				change[a].i_nerka = i;
				change[a].j_nerka = j;
				a++;
			}
		}
		a = 0;
		start_x_for_left = start_x_for_left - 5 * (m - 1);
		start_y = start_y - 2 * (abs(m - n));
		while (a < m * n)
		{
			i2 = change[a].i_nerka;
			j2 = change[a].j_nerka;
			pos.X = start_x_for_left - 5 * j2 + 1;
			pos.Y = start_y + 2 * i2;
			SetConsoleCursorPosition(the_console, pos);
			printf("  ");
			// in case of < 0, moving up then right
			if (m - n - i2 + j2 < 0)
			{
				move_up_left(i2, j2, m, n, pos, the_console, change[a].num);
			}
			// in case of > 0, move right then down
			else
			{
				move_left_down(i2, j2, m, n, pos, the_console, change[a].num);
			}
			a++;
		}
		// 4th etap
		a = 0;
		for (int j = 0; j < n; j++)
		{
			for (int i = m - 1; i >= 0; i--)
			{
				change[a].num = arr[i][j];
				a++;
			}
		}
		// changing indices of numbers as they are items of "new generated" matrix
		a = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				change[a].i_nerka = i;
				change[a].j_nerka = j;
				a++;
			}
		}
		a = 0;
		start_x = start_x - 5 * (n - 1);
		start_y = start_y + 2 * (abs(m - n));
		while (a < m * n)
		{
			i2 = change[a].i_nerka;
			j2 = change[a].j_nerka;
			pos.X = start_x_for_left - 5 * j2 + 1;
			pos.Y = start_y + 2 * i2;
			SetConsoleCursorPosition(the_console, pos);
			printf("  ");
			// in case of < 0, moving up then right
			if (n - m - i2 + j2 < 0)
			{
				move_up_left(i2, j2, n, m, pos, the_console, change[a].num);
			}
			// in case of > 0, move right then down
			else
			{
				move_left_down(i2, j2, n, m, pos, the_console, change[a].num);
			}
			a++;
		}
		// for starting 1st etap again with fake matrix
		start_x_for_left = start_x_for_left - 5 * (m - 1);
		start_y = start_y - 2 * (abs(m - n));
	}
	return (start_x_for_left);
}


int main()
{
	int n, m;
	int i = -1;
	int j;
	printf("Enter m & n: ");
	scanf("%d %d", &m, &n);
	fake_arr change[m * n];
	int **arr;
	// generating matrix
	arr = malloc(sizeof(int *) * m);
	while (++i < m)
	{
		arr[i] = malloc(sizeof(int) * n);
		j = -1;
		while (++j < n)
			arr[i][j] = 50 - rand() % 8;
	}
	// filling array of structs with indices and arr[j][j]
	int a = 0;
	// printing matrix
	COORD pos;
	HANDLE the_console = GetStdHandle(STD_OUTPUT_HANDLE);
	SHORT tabKeyState = GetAsyncKeyState(VK_TAB);
	int start_x = 153;
	int start_y = 5;
	pos.X = start_x;
	pos.Y = start_y;
	for (int i = 0; i < m; i++)
	{
		SetConsoleCursorPosition(the_console, pos);
		for (int j = 0; j < n; j++)
		{
			printf("%d", arr[i][j]);
			pos.X += 7;
			SetConsoleCursorPosition(the_console, pos);
			Sleep(400);
		}
		pos.X = start_x;
		pos.Y += 2;
	}
	//
	CONSOLE_CURSOR_INFO info;
	info.bVisible = FALSE;
	info.dwSize = 1;
	SetConsoleCursorInfo(the_console, &info);
	//
	while (1)
	{
		//start_x = rolling_right(change, pos, start_x, start_y, n, m, the_console, arr);
		rolling_left(change, pos, start_x, start_y, n, m, the_console, arr);
	}
	return 0;
}