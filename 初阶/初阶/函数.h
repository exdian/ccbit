#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

bool is_prime(int n);
bool is_leap_year(int n);
int binary_search(int arr[], int num, int count);
void print_num(unsigned int n);
int fib(int n);
void sort_bubble(int arr[], int count);
int count_bin1(int n);