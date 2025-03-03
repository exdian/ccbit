#pragma once

#include <stdbool.h>
#include <stdio.h>

bool chk_endian();
void test_char_ptr();
void test_ptr_arr();
void test_arr_ptr();
void test_function_ptr();
void test_sort();
void bubble_sort(void* ptr, int num, int width, int (*pf)(const void*, const void*));
