// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
�ؾ������������á�����ŷ𾭺͸�ɮ˵�������������������������ڴ˴���
һ¥ͨ��������˵���ĳ�����Խ���Ϸ𾭱�Խ���أ���������ÿ������¶����ڴ�
����˵�����ն�����������ľ��,�ź�¥��ͨ��¥�ϡ�
LONG
        );
        set("exits", ([ 
  "northdown" : __DIR__"fangnan",
  "up"	: __DIR__"changjing2",
  "southdown" : __DIR__"yonglu2",
  "eastdown": __DIR__"least",
  "westdown": __DIR__"lwest",
]));
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        create_door("up", "door","ľ��", "down", DOOR_CLOSED);
}
