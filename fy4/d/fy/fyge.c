#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
    set("short", "���Ƹ�");
    set("long", @LONG
���Ƹ�����˾��ǵ������´���������С��ɵ�����Ȼ��̽���Ѿ����˶�ʱ��
���ǻ��п���Ľ�������˸�����һ��֮Ե�����д�첨˹��̺�̵أ������ûʡ�
���Ĵ����������һ��ʯ�̵Ķ�������
[33m
                	һ���߽�ʿ
                	������̽��
[2;37;0m
LONG
    );
    set("valid_startroom", 1);
    set("item_desc", ([
//		"sign": (: look_sign :),
      ]) );

    set("exits", ([
	"west"    	: __DIR__"tiandoor",
	"up"		: __DIR__"fyyage",
      ]) );

    set("objects", ([
		__DIR__"npc/fywaiter" : 1,
      ]) );
    set("NONPC",1);
    set("coor/x",40);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fynorth");
    setup();

    // To "load" the board, don't ever "clone" a bulletin board.
    call_other( "/obj/board/common_fy", "???" );
}

