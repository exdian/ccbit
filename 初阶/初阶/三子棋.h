#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3
#define RULE 3

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static void menu();
static void inside();
static void chess_board(const char arr[ROW][COL], int row, int col);
static void player_step(char arr[ROW][COL], int row, int col);
static void computer_step(char arr[ROW][COL], int row, int col);
static char chk_board(const char arr[ROW][COL], int row, int col);
void press_enter();