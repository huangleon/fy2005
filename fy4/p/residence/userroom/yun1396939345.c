#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "yun"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1396939345"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "云和山的彼端");
set("long", @LONG
游戏横跨欧亚大陆，贯穿法兰克、阿拉伯、中国三个文明。游戏也针对不同文明做了不同的设计。如在水城威尼斯、大马士革、以及最后的长安三地的建筑、行人的服饰风格都各有不同，背景音乐也符合当地风格，对白也有各自的文化背景。游戏历史背景选择在东西方文化碰撞的一个时期，将许多世界历史上的大事件如怛罗斯之战、阿拉伯革命、十字军东征、安史之乱等穿插于剧情当中。

LONG
);
        set("exits", ([
"out" : "/p/residence/smile1.c",
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
