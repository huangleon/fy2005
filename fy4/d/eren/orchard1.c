inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��԰");
        set("long", @LONG
�����Ĺ���԰���Ũ�ܵ���Ҷ����չ��ȥ��֦����΢΢�İڶ�����ôҲ�ز�
ס��һ���۵����صĹ��ӡ����������ﻹ������ż�������¶�飬��������ҹ��ҫ
�۵�����һ������Щ��ɫ��Ƥ����һ����ë��������һ�㱡˪���Ե��������ʪ��
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad5",
	"northeast": __DIR__"orchard2",
	]));
        set("objects", ([

	]) );
	set("outdoors", "eren");
        set("coor/x",110);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
}
