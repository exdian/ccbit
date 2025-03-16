#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define MAX_LST 64
#define MAX_NAME 16
#define MAX_ARRD 16
#define MAX_TELE 12
#define MAX_NOTE 20

struct contact_list
{
	char name[MAX_NAME];
	char addr[MAX_ARRD];
	char tele[MAX_TELE];
	char note[MAX_NOTE];
};

typedef struct contacts
{
	struct contact_list list[MAX_LST];
	int count;
} contact;

static void menu(int count);
static void init_contact(contact* pc);
static int find_contact(const contact* pc, const char* str);
static void show_contact(const struct contact_list* pcl, int start, int end);
static void add_contact(contact* pc);
static void rmv_contact(contact* pc);
static void mod_contact(contact* pc);
static void scr_contact(contact* pc);
static void lst_contact(contact* pc);
static void sor_contact(contact* pc);
static int sort_name(const void* elem1, const void* elem2);
