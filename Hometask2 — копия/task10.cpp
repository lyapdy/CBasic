? /*
 ���� "������"

 �������� ������ ��������


 */

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	using namespace std;

// ���� � ����
const int play_field_width = 20;
const int play_field_height = 20;

const int size_of_field = play_field_width * play_field_height;

// ����
int play_field[size_of_field];

// ���������� � ������
int head_x_position;
int head_y_position;
int direction = 1;

int snake_length = 3;
int score = 0;

bool game_running;

int difficulty;

void run();
void print_play_field();
void initialize_play_field();
void move_snake(int x, int y);
void update_field();
void generate_food();
char get_play_field_value(int value);

int main()
{
	cout << "Choose difficulty: " << endl
		 << endl;
	cout << "1 - Easy" << endl;
	cout << "2 - Medium" << endl;
	cout << "3 - Hard" << endl;
	cout << "Enter option ( 1 - 3 ): ";
	cin >> difficulty;
	cout << endl;
	cout << "Loading..." << endl;

	run();
	return 0;
}

void run()
{
	// �������� ����
	initialize_play_field();
	game_running = true;
	while (game_running)
	{

		if (_kbhit())
		{
			char key = _getch();
			switch (key)
			{
			case 'w':
				if (direction != 3)
					direction = 1;
				break;
			case 'd':
				if (direction != 4)
					direction = 2;
				break;
			case 's':
				if (direction != 1)
					direction = 3;
				break;
			case 'a':
				if (direction != 2)
					direction = 4;
				break;
			}
		}
		// �������� ����
		update_field();
		system("cls");
		// ����� ����
		print_play_field();
		switch (difficulty)
		{
		case 1:
			Sleep(500);
			break;
		case 2:
			Sleep(400);
			break;
		case 3:
			Sleep(200);
			break;
		}
	}

	// ����� ����
	cout << "!Game over!" << endl
		 << "Your score is: " << score;

	cin.ignore();
}

// �������� ������
void move_snake(int x, int y)
{
	// ����� ���������� ������
	int newx = head_x_position + x;
	int newy = head_y_position + y;

	// �������� �� ���
	if (play_field[newx + newy * play_field_width] == -2)
	{
		// ���������
		snake_length++;
		score++;
		// �������� ����� ���
		generate_food();
	}

	// �������� �� ����� � ����������� �����
	else if (play_field[newx + newy * play_field_width] != 0)
	{
		game_running = false;
	}

	// +1 ��� ������������ ������� ����
	head_x_position = newx;
	head_y_position = newy;
	play_field[head_x_position + head_y_position * play_field_width] = snake_length + 1;
}

// ���
void generate_food()
{
	int x = 0;
	int y = 0;
	do
	{

		srand(time(NULL));
		x = rand() % (play_field_width - 2) + 1;
		y = rand() % (play_field_height - 2) + 1;

		// �������� �� ����������� ����
	} while (play_field[x + y * play_field_width] != 0);

	// �������� ���
	play_field[x + y * play_field_width] = -2;
}

// ���������� ���. ����
void update_field()
{
	// ��������
	switch (direction)
	{
	case 1:
		move_snake(-1, 0); // 1:�����
		break;
	case 2:
		move_snake(0, 1); // 2:�����
		break;
	case 3:
		move_snake(1, 0); // 3:����
		break;
	case 4:
		move_snake(0, -1); // 4:����
		break;
	}

	for (int i = 0; i < size_of_field; i++)
	{
		if (play_field[i] > 0)
			play_field[i]--;
	}
}

// �������� �����
void initialize_play_field()
{
	// ������ ���� � �������� ���� (play_field[210])
	head_x_position = play_field_width / 2;
	head_y_position = play_field_height / 2;
	play_field[head_x_position + head_y_position * play_field_height] = 1;

	// ������� � ������ �����
	for (int x = 0; x < play_field_width; x++)
	{ // ����� play_field[0] � play_field [380] � ������������ ��������� 'X' � ��, �� play_field[19] � play_field [399], �.� ������� � ������ ������
		play_field[x] = -1;
		play_field[x + (play_field_height - 1) * play_field_width] = -1;
	}

	// ����� � ������ ������
	for (int y = 0; y < play_field_height; y++)
	{ // ���� ����� �� ����� play_field[0] � play_field[19], ����� play_field[20] � play_field[39] �.�. ��������� 18 "������� �����" � ������ ���������
		play_field[0 + y * play_field_height] = -1;
		play_field[(play_field_width - 1) + y * play_field_width] = -1;
	}

	// �������� ����������� ���
	generate_food();
}

// ����� ����
void print_play_field()
{
	for (int x = 0; x < play_field_width; x++)
	{
		for (int y = 0; y < play_field_height; y++)
		{
			// �������� � ����������� x,y �����������
			std::cout << get_play_field_value(play_field[x + y * play_field_width]);
		}
		// ����� � ���� ����
		cout << endl;
	}
}

char get_play_field_value(int value)
{
	// ������
	if (value > 0)
		return 'o';

	switch (value)
	{
		// �����
	case -1:
		return 'O';
		// ���
	case -2:
		return '@';
	}
}