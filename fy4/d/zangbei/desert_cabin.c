inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "������");
        set("long", @LONG
�⼸��ľ�ݱ�������Ѳ�����������������ʮ�ֳ¾ɣ��м��ȴ���û�йأ���
������������˵ƹ⣬����������һֱ�����˵ġ�ʮ�����������ô��������ѿ���
�����ˡ�[37mľ��[32m����Լ��һ����Ե�������������ת���꣬����������
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"desert_cabin2",
		"south" : __DIR__"yangguan1c",
	]));
        set("objects", ([
        	
	]) );
	set("item_desc", ([
		"ľ��": "һ��ľ��ͨ��ľ�ݡ�\n",
		"cabin": "һ��ľ��ͨ��ľ�ݡ�\n",
	]));
	set("outdoors", "zangbei");
        set("coor/x",-90);
        set("coor/y",310);
        set("coor/z",0);
        set("map","zbeast");
	setup();
	create_door("north", "door","ľ��", "south", DOOR_CLOSED);

}
