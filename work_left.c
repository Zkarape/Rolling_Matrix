#include "work.h"

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
		pos.X += 3;
		pos.Y += 2;
		SetConsoleCursorPosition(the_console, pos);
		printf("%d", num);
		pos.X -= 3;
		Sleep(200);
		SetConsoleCursorPosition(the_console, pos);
		printf("   ");
	}
}

void move_up_left(int i, int j, int m, int n, COORD pos, HANDLE the_console, int num)
{
	int i1 = 0;
	int j1 = 0;
	while (--j1 >= m - n - i + j)
	{
		printf("   ");
		pos.X += 3;
		pos.Y -= 2;
		SetConsoleCursorPosition(the_console, pos);
		printf("%d", num);
		pos.X -= 3;
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
	int count = 0;
	int start_x_for_left;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			change[a].num = arr[i][j];
			a++;
		}
	}
	//	start_x_for_left = start_x + (n - 1) * 5;
	while (count < 3)
	{
		// 1st etap
		// changing indices of numbers as they are items of "generated" matrix
		a = 0;
		for (int j = 0; j < n; j++)
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
			pos.X = start_x - 5 * j2 + 1;
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
		// 2nd etap
		// changing indices of numbers as they are items of "new generated" matrix
		a = 0;
		for (int j = 0; j < m; j++)
		{
			for (int i = n - 1; i >= 0; i--)
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
			pos.X = start_x - 5 * j2 + 1;
			pos.Y = start_y + 2 * i2;
			SetConsoleCursorPosition(the_console, pos);
			printf("  ");
			// in case of < 0, moving up then right
			if (n - m - i2 + j2 < 0)
			{
				move_up_right(i2, j2, n, m, pos, the_console, change[a].num);
			}
			// in case of > 0, move right then down
			else
			{
				move_right_down(i2, j2, n, m, pos, the_console, change[a].num);
			}
			a++;
		}
		// 3rd etap
		// changing indices of numbers as they are items of "new generated" matrix
		a = 0;
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				change[a].i_nerka = i;
				change[a].j_nerka = j;
				a++;
			}
		}
		a = 0;
		start_x = start_x - 5 * (m - 1);
		start_y = start_y - 2 * (abs(m - n));
		while (a < m * n)
		{
			i2 = change[a].i_nerka;
			j2 = change[a].j_nerka;
			pos.X = start_x - 5 * j2 + 1;
			pos.Y = start_y + 2 * i2;
			SetConsoleCursorPosition(the_console, pos);
			printf("  ");
			// in case of < 0, moving up then right
			if (m - n - i2 + j2 < 0)
			{
				move_up_right(i2, j2, m, n, pos, the_console, change[a].num);
			}
			// in case of > 0, move right then down
			else
			{
				move_right_down(i2, j2, m, n, pos, the_console, change[a].num);
			}
			a++;
		}
		// 4th etap
		// changing indices of numbers as they are items of "new generated" matrix
		a = 0;
		for (int j = 0; j < m; j++)
		{
			for (int i = n - 1; i >= 0; i--)
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
			pos.X = start_x - 5 * j2 + 1;
			pos.Y = start_y + 2 * i2;
			SetConsoleCursorPosition(the_console, pos);
			printf("  ");
			// in case of < 0, moving up then right
			if (n - m - i2 + j2 < 0)
			{
				move_up_right(i2, j2, n, m, pos, the_console, change[a].num);
			}
			// in case of > 0, move right then down
			else
			{
				move_right_down(i2, j2, n, m, pos, the_console, change[a].num);
			}
			a++;
		}
		// for starting 1st etap again with fake matrix
		start_x = start_x + 5 * (m - 1);
		start_y = start_y - 2 * (abs(m - n));
		count++;
	}
	return (start_x);
}