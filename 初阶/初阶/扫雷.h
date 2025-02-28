#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define ROWS 11
#define COLS 11

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

static void menu();
static void inside();
static int put_mine(char mine[ROWS][COLS], int row, int col);
static void print(const char arr[ROWS][COLS], int rows, int cols);
static void sweep(char mine[ROWS][COLS], char show[ROWS][COLS], int mine_num, int row, int col);
static void chk_inp(const char show[ROWS][COLS], int* inp_row, int* inp_col, int rows, int cols);
static char mine_around(const char mine[ROWS][COLS], int row, int col);
static int auto_sweep(const char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
static void print_end(const char mine[ROWS][COLS], const char show[ROWS][COLS], int rows, int cols);
