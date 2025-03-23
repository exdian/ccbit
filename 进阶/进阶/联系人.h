#pragma once
/*
´ýÍê³É£º
ÅÅÐò
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_NAME 24
#define MAX_ARRD 24
#define MAX_TELE 12
#define MAX_NOTE 36
#define CONTINUE 1

struct contact_list
{
	char name[MAX_NAME];
	char addr[MAX_ARRD];
	char tele[MAX_TELE];
	char note[MAX_NOTE];
};

typedef struct contact
{
	struct contact_list data;
	struct contact* next;
} contact;

struct link
{
	contact* last;
	contact* node;
};

static void menu(size_t count);
static contact* init_contact(size_t* count, contact** start);
static struct link find_contact(const contact* start, const char* str);
static void show_contact(const contact* start, const contact* end);
static int save_contact(size_t count, const contact* start);
static void free_contact(contact* start);
static int quit_contact(size_t count, contact* start);
static void add_contact(size_t* count, contact** start, contact** end);
static void rmv_contact(size_t* count, contact** start, contact** end);
static void mod_contact(size_t* count, contact** start, contact** end);
static void scr_contact(size_t* count, contact** start, contact** end);
static void lst_contact(size_t* count, contact** start, contact** end);
static void sor_contact(size_t* count, contact** start, contact** end);
static int sort_name_asc(const void* elem1, const void* elem2);
static int sort_name_desc(const void* elem1, const void* elem2);
static int sort_addr_asc(const void* elem1, const void* elem2);
static int sort_addr_desc(const void* elem1, const void* elem2);
static int sort_tele_asc(const void* elem1, const void* elem2);
static int sort_tele_desc(const void* elem1, const void* elem2);
static int sort_note_asc(const void* elem1, const void* elem2);
static int sort_note_desc(const void* elem1, const void* elem2);
