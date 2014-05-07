/*
 * Build with:
 *     gcc -lncurses puzzle.c
 */

#include <curses.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include <termios.h>

#include <stdio.h>
#include <stdlib.h>

#define X_SIZE	4
#define Y_SIZE	4

#define red	"\033[1;31m"	/* 0 -> normal ;  31 -> red */
#define cyan	"\033[1;36m"	/* 1 -> bold ;  36 -> cyan */
#define green	"\033[4;32m"	/* 4 -> underline ;  32 -> green */
#define blue	"\033[1;34m"	/* 9 -> strike ;  34 -> blue */

#define black	"\033[0;30m"
#define brown	"\033[0;33m"
#define magenta	"\033[0;35m"
#define gray	"\033[0;37m"

#define none	"\033[0m"	/* to flush the previous property */

static char map_target[Y_SIZE][X_SIZE] = {
	{'W', 'R', 'B', 'B'},
	{'R', 'R', 'B', 'B'},
	{'R', 'R', 'B', 'B'},
	{'R', 'R', 'B', 'B'}
};

static char map[Y_SIZE][X_SIZE] = {
	{'W', 'B', 'R', 'B'},
	{'B', 'R', 'B', 'R'},
	{'R', 'B', 'R', 'B'},
	{'B', 'R', 'B', 'R'}
};

static int x_cur, y_cur;
static int steps = 0;
static char sequence[256] = {0};

static long original_term_flags;
static long original_filemode;

static void keyboard_open(void)
{
	long filemode;
	struct termios terminal_settings;

	tcgetattr(STDIN_FILENO, &terminal_settings);
	original_term_flags = terminal_settings.c_lflag;

	/* turn off line buffering (ICANON) and local echo. */
	terminal_settings.c_lflag &= (~(ICANON | ECHO));
	tcsetattr(STDIN_FILENO, TCSANOW, &terminal_settings);

	filemode = fcntl(STDIN_FILENO, F_GETFL);
	original_filemode = filemode;
	filemode |= O_NDELAY;
	fcntl(STDIN_FILENO, F_SETFL, filemode);
}

static void keyboard_close(void)
{
	struct termios terminal_settings;

	tcgetattr(STDIN_FILENO, &terminal_settings);
	terminal_settings.c_lflag = original_term_flags;
	tcsetattr(STDIN_FILENO, TCSANOW, &terminal_settings);
	fcntl(STDIN_FILENO, F_SETFL, original_filemode);
}

static unsigned int keyboard_getkey(void)
{
	int key;
	unsigned int rawkeycode;

	key = getchar();

	if (key == -1) {
		rawkeycode = 0;
		return rawkeycode;
	}

	rawkeycode = key;

	if (key == 0x1b) {
		key = getchar();
		if (key != -1) {
			rawkeycode = ((rawkeycode << 8) | key);
			if (key == 0x5b) {
				key = getchar();
				if (key != -1) {
					rawkeycode = ((rawkeycode << 8) | key);
				}
			}
		}
	}

	return rawkeycode;
}

static int find_cur_point(const char map[Y_SIZE][X_SIZE], int *x, int *y)
{
	int i, j;
	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			if (map[i][j] == 'W') {
				*x = j;
				*y = i;
			}
		}
	}
	return 0;
}

static void print_map(const char map[Y_SIZE][X_SIZE])
{
	int i, j;
	system("clear");
	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			if (map[i][j] == 'R')
				printf("%s%c%s", red, map[i][j], none);
			else if (map[i][j] == 'B')
				printf("%s%c%s", blue, map[i][j], none);
			else
				printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < Y_SIZE; i++) {
		for (j = 0; j < X_SIZE; j++) {
			if (map_target[i][j] == 'R')
				printf("%s%c%s", red, map_target[i][j], none);
			else if (map_target[i][j] == 'B')
				printf("%s%c%s", blue, map_target[i][j], none);
			else
				printf("%c", map_target[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("steps: %d\n", steps);
	printf("sequence: %s\n", sequence);
}

static int match_map(const char map[Y_SIZE][X_SIZE], const char map_target[Y_SIZE][X_SIZE])
{
	return memcmp(map, map_target, Y_SIZE * X_SIZE);
}

static int letsmove(unsigned int dir)
{
	char tmp;

	switch (dir) {
	case 'h':
		if (x_cur != 0) {
			tmp = map[y_cur][x_cur];
			map[y_cur][x_cur] = map[y_cur][x_cur - 1];
			map[y_cur][x_cur - 1] = tmp;
			x_cur -= 1;
			sequence[steps] = 'L';
			steps++;
		}
		print_map(map);
		break;
	case 'j':
		if (y_cur != Y_SIZE - 1) {
			tmp = map[y_cur][x_cur];
			map[y_cur][x_cur] = map[y_cur + 1][x_cur];
			map[y_cur + 1][x_cur] = tmp;
			y_cur += 1;
			sequence[steps] = 'D';
			steps++;
		}
		print_map(map);
		break;
	case 'k':
		if (y_cur != 0) {
			tmp = map[y_cur][x_cur];
			map[y_cur][x_cur] = map[y_cur - 1][x_cur];
			map[y_cur - 1][x_cur] = tmp;
			y_cur -= 1;
			sequence[steps] = 'U';
			steps++;
		}
		print_map(map);
		break;
	case 'l':
		if (x_cur != X_SIZE - 1) {
			tmp = map[y_cur][x_cur];
			map[y_cur][x_cur] = map[y_cur][x_cur + 1];
			map[y_cur][x_cur + 1] = tmp;
			x_cur += 1;
			sequence[steps] = 'R';
			steps++;
		}
		print_map(map);
		break;
	default:
		break;
	}

	return match_map(map, map_target);
}

static void process_user_input(void)
{
	unsigned int c;
	keyboard_open();
	while (1) {
		c = keyboard_getkey();
		if (c == 0)
			usleep(20000);
		if (letsmove(c) == 0)
			break;
	}
	keyboard_close();
}

int main(int argc, char *argv[])
{
	find_cur_point(map, &x_cur, &y_cur);
	printf("start point (%d, %d)\n", x_cur, y_cur);
	print_map(map);
	process_user_input();
	return 0;
}
