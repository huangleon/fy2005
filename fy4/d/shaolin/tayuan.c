// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
���������ֳ�סԺ����Ժ����������������������Ϊ���߷������������շ�����
����Ķ������շ�����˫��̤������������̹Ȼ����̬��ׯ�����ߵ�С��ͨ��
��¶̨����ɮ���Ǽ�ˮ�ĵط���
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"lixue",
  "westup" : __DIR__"ganlu",
]));
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	create_door("westup","door", "ľ��", "eastdown", DOOR_CLOSED);
}
