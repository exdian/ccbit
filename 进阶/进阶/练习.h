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
void select_sort(void* ptr, int num, int width, int (*pf)(const void*, const void*));
char* string_concat(char* dest, const char* src);
int string_compare(const char* str1, const char* str2);
char* string_num_copy(char* dest, const char* src, int num);
char* string_num_concat(char* dest, const char* str, int num);
int string_num_compare(const char* str1, const char* str2, int num);
char* string_find(const char* str1, const char* str2);
void test_string_function();
void* memory_copy(void* dest, const void* src, size_t num);
void* memory_move(void* dest, const void* src, size_t num);
int memory_compare(const void* ptr1, const void* ptr2, size_t num);
void* memory_set(void* ptr, int value, size_t num);
void test_contact();
void test_enum();
void test_union();
void test_alloc();
void test_softarr();
void test_file();
void test_pre();
void test_offsetof();
void* sort_linklist(void** start, size_t node_num, size_t next_ptr_offset, int (*pfunc)(const void* elem1, const void* elem2));
