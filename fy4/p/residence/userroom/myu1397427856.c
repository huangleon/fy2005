#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 80
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "myu"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1397427856"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "��ҹ");
set("long", @LONG

������γ��Ъ������
����¶��һ�����ޱ�
��������΢���³���
����������ҡ������
����˭��һ������ҹ
����Ѱ����ת��̨л
�����������̼�����
������ɫ����༤��


LONG
);
        set("exits", ([
"out" : "/p/residence/smile2.c",
]));
set("objects", ([
       ]) );
	set("coor/x",X_COOR);
	set("coor/y",Y_COOR);
	set("coor/z",Z_COOR);
	set("room_flag",R_FLAG);
	set("owner", OWNER);
	set("class", CLASS);
	set("timestamp",TIMESTAMP);
	set("timestamp2",TIMESTAMP2);
	set("free_space",FREE_SPACE);
	set("basic_tax",BASIC_TAX);
	set("basic_score_tax",BASIC_SCORE_TAX);
	set("tree",CONSTRUCT_TREE);
	set("total_gold",TOTAL_GOLD);
	set("total_score",TOTAL_SCORE);
	setup();

}
