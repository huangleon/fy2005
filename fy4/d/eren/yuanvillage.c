inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����ɽׯ");
        set("long", @LONG
Ԭ�ұ���������׻�������Ԭ�ҵİ���ɽׯ����������Χ�˰��������˭��֪��
���أ����ο����첻ͬѰ������Ԭ�Ҵ���үԬ�����������ǧ��������׵Ĵ�ϲ֮
�ա���ǰ��ˮ����������ǰ����ϲ����Ⱥ��
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"yuanvillage2",
		"south": __DIR__"road1e",
	]));
        set("objects", ([
		__DIR__"npc/young1":	1,
		__DIR__"npc/young2":	1, 		
	]) );
	set("coor/x",-50);
        set("coor/y",20);
        set("coor/z",10);
	set("map","eren");
	setup();
	
}


int	valid_leave(object me, string arg) {
	object guard;
	
	if (arg == "north"){
		guard = present("guard",this_object());
		if (guard && guard->query("group")=="baiyunzhuang") {
			if (!me->query_temp("baiyunzhuang"))
				return notify_fail(guard->name()+"˵����λ"+RANK_D->query_respect(me)+"������ϲ�۵����\n");
		}
	}
	return 1;
}