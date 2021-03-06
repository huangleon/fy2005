#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX 280
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "kana"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1395838262"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "戏言世界");
set("long", @LONG
阿伊和小友的小窝。
我的东西就应该放在我的身边。
即使是丢弃之物，我的就是我的。
丢弃之物被他人捡走也很不愉快。
死线之蓝占有欲是很强的哦。

LONG
);
        set("exits", ([
"out" : "/p/residence/sword1.c",
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
