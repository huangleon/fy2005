inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ�嶫��");
        set("long", @LONG
ɽ��Ķ��滹�����ҵ��̣�һ���ſ��и��ܴ��ʯĥ�̣�һͷë¿����������
����ת��������Ů��һ����ĥ����Ӷ��ӣ�һ�����������ش��֣�������д�š�ŷ
�������̡�����һ���ſ����Ǹ��յ�ͨ�����¯����������������ĺ������ڶ���
�����ش�����
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad3",
	"east" : __DIR__"vroad5",
	"north" : __DIR__"tofupu",
	"south":  __DIR__"weaponstore",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",80);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
