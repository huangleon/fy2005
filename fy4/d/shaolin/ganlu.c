// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "��¶̨");
        set("long", @LONG
��˵�����뾭���콵��¶��������Ϊ��¶̨��̨������Űأ�̨�¼��ù�����
�Ѹ�¶̨���Ű�ס����¶̨�гɰ��Σ������һ����ˮ�������겻�ɿݡ�
LONG
        );
        set("exits", ([ 
  	"eastdown" : __DIR__"tayuan",	
	]));
        set("objects", ([
                __DIR__"npc/master_21" : 1,
       ]) );
	set("resource/water", 1);
	set("liquid/container", "��¶̨");
	set("liquid/name","��¶ˮ");
	
    set("outdoors", "shaolin");
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",10);
	setup();
	create_door("eastdown", "door","ľ��", "westup", DOOR_CLOSED);
}

