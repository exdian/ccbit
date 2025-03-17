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
��û�뵽����7������������ʵҲ�ᱻ�磬����������������һ�أ����������ˣ���Ǹ�Ļ��ᶼû�С�
�ҷ�ʡ����˵�Ļ������Եģ��������Ǹ���Ƶ����˵��λ��������⣬������Ҵ��Ŷ���ȥ�����λ�����ȷʵҲ�����˵��λ����˸��硣
�����Ҳ������һЩ��ѵ�������������ø��ã��ҽ������ǵ����������Ƕ�����Ϊ�˴�������ʦ�����ϵ����������ø��ã������ǽӴ�Ҳ�ջ���һЩ������
���������󣬲�������ʵ�������磬��˵��������ӽ����ˣ���Ҳ�Ǽ�����space.1472584696
*/