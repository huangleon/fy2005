// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "ǧɮ��");
        set("long", @LONG
�����󷹵����ڣ��������ڴ��������������������������������֮�ϣ���
�־ް���������з�ʳ��������ǧɮ��ÿ��ʳ�������������ϸ������ɮ�ˣ���
��������������Ȼ���޲��ʣ��������Ǵ�����ѧ�ĺ÷�����
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"fanting",
 "north" : __DIR__"bohuo",  
]));
        set("objects", ([
                __DIR__"obj/wok" : 3,
       ]) );
	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",10);
	setup();
	create_door("east", "door","ľ��", "west", DOOR_CLOSED);

}
