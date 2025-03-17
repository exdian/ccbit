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
static int sort_name_asc(const void* elem1, const void* elem2);
static int sort_name_desc(const void* elem1, const void* elem2);
static int sort_addr_asc(const void* elem1, const void* elem2);
static int sort_addr_desc(const void* elem1, const void* elem2);
static int sort_tele_asc(const void* elem1, const void* elem2);
static int sort_tele_desc(const void* elem1, const void* elem2);
static int sort_note_asc(const void* elem1, const void* elem2);
static int sort_note_desc(const void* elem1, const void* elem2);
/*
我没想到，用7个文字描述事实也会被喷，今天总算是体验了一回，还被拉黑了，道歉的机会都没有。
我反省，我说的话是中性的，但是在那个视频底下说这段话就有问题，如果是我揣着恶意去理解这段话，那确实也会觉得说这段话的人该喷。
这件事也给了我一些教训，可以让我做得更好，我接受他们的批评，他们都是我为人处世的老师，不断地引导我做得更好，跟他们接触也收获了一些东西。
这件事情过后，不管是现实还是网络，我说话都会更加谨慎了，这也是件好事space.1472584696
*/