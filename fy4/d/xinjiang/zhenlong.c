#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����λ�ں�ɽɽ��������߹�ʮ�ɣ�������������ɫ��Ƭ����������ʮ��ҫ�ۡ�
������Χ�Ǻ�ש�أ��Ѿ��ܾ��ˣ��������Ѻۡ�����ܾ�������һЩ������������
��������֮�⣬�ƺ�û�����������ˡ�
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"hongshan",
]));

        set("objects", ([
        __DIR__"npc/xiechangqing" : 1,
	]) );

        set("outdoors", "xinjiang");
	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",20);
	setup();
}

