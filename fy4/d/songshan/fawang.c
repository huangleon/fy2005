// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
#include "/questnpc/lovestory1/event_place.h"
void create()
{
        set("short", "������");
        set("long", @LONG
������������ķ����Ժ֮һ���ഫ�Ǻ�����Ϊ�����ĸ�ɮ�÷����뾭������
������ĵڶ������£�ֻ�����������������ꡣ���۵�ǰ��ǧ��������Ҷ������
�����ǡ��¶�˫����죬�л����ţ������˵Ƿ�˾�֮�����Ŵ��¡��澰��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"shita", 
]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"obj/tree" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",0);
	setup();

}

int valid_enter(object me)
{

	if(me->query("lovestory1"))
		add_trigger_count(me);
	return 1;
}
