// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���Ź�");
        set("long", @LONG
��һ���ѣ��������ڹ��Źأ��ߴ�ĳ�ǽ��μˮ���ƣ�����ɭɭ��������Ŀ��
����ţͷ�������ֳ��������س��ţ��������ֳ�����������ק�ż�����Ӱ���˽�ȥ
��������������������¥�ϸ���һ�����ң�
[31m

			���Ź�
[32m
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "south" : __DIR__"naihe",
		"east" : __DIR__"aihe2",
        ]) );
        set("objects", ([
		__DIR__"npc/panguan" : 1,
        ]) );
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}
