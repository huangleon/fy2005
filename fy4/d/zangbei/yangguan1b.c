inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��Į");
        set("long", @LONG
����ǰ�ߣ�ɳĮ�ޱ��޼ʣ�����ããһƬѩ��ʲôҲû�У���һ������Ҳ�Ҳ�
����Զ����������Ⱥɽ��������ѩ����������ֱ����ʡ�������������ж�����
���ߣ�٪��Ҳ����˾��ˣ�������������ж��������ߣ�����Ҳ�����٪�塣
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"yangguan2",
		"south" : __DIR__"yangguan1",
		"east":	__FILE__,
		"north": __FILE__,
			
	]));
        set("objects", ([

	]) );
	set("outdoors", "zangbei");
    set("coor/x",-100);
    set("coor/y",300);
    set("coor/z",0);
	set("map","zbeast");
	setup();
}


void init() {
	add_action("do_south","go");
}

int do_south (string arg)
{
   	object me, room;
   	me = this_player();
	
	if (arg != "west" && arg != "south" && arg !="north" && arg!="east")	return 0;
		
	if (random(3) || arg ==" west" )	return 0;
   	
   		tell_object(me,YEL"�������ţ��㾪�ֵط��֡��������Ѿ���·�ˣ�����\n"NOR);
      	room = find_object(__DIR__"yangguan1c");
		if (!room) room = load_object(__DIR__"yangguan1c");
		me->move(room);
      	return 1; 	
}
