// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�����޵�");
        set("long", @LONG
���۵�������������������Ϊ������Ϊͭ����Ϊ�������ͽ����档
��Ϊ�����µĻ���٤��������𴦷����Ϊ����٤�����в�ͬ����ν٤����������
�����б�����Ժ����˼���������٤����Ĺ�ģʵ�ڲ�С�������ֳ������Ľ����ޣ�
�㲻������������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"jinna",
]));
        set("objects", ([
                BOOKS"skill/jinna_100" : 1,
                __DIR__"npc/laomonk" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();

}
