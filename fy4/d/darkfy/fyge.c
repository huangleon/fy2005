// inn.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "���Ƹ�");
	set("long", @LONG
���Ƹ�����˾��ǵ�����������������С��ɵ�����̽�������������⣬������
�кܶ����Ľ�������˸�����һ��֮Ե�����д�첨˹��̺�̵أ������û͡����
�Ĵ����������һ��ʯ�̵Ķ�������
[33m
                	һ���߽�ʿ��
                	������̽����
[37m
LONG
	);
	set("valid_startroom", 1);
	set("item_desc", ([
		"sign": (: look_sign :),
	]) );
	
	set("exits", ([
		"west"    	: __DIR__"nwind1",
		"up"		: __DIR__"fyyage",
	]) );

	set("objects", ([
		__DIR__"npc/" : 1,

			]) );

	set("coor/x",10);
	set("coor/y",10);
        set("coor/z",-300);
	setup();

	// To "load" the board, don't ever "clone" a bulletin board.
	call_other( "/obj/board/common_fy", "???" );
}

string look_sign(object me)
{
	if( wizardp(me) )
		return "����д�������Ƹ��Ա�һ��С�֣������⡣\n";
	else
		return "����д�������Ƹ��Ա߿���һ��С�֣����񵽴�һ�Ρ�\n";
}
