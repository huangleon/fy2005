#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"��Ũ�μ���"NOR);
        set("long", "��һ���������ͻȻƳ���˳��ҵĹ�â��"+HIR"��⣡"NOR+"����Ļ��棬��ɽ����������
����ҷ�ӿ�����ֻ���ˣ���û�л��棬ֻ�б���"+HIW"������"NOR+"������ɳһ���ĺ�����
ӳ�Ż�⣬�����������������������ѹ������һ𺮱�֮��ȴ��������ɵ�һ�ο�
϶������������϶֮�С�\n"NOR
        );
        set("exits", ([ 
//		"down":  __DIR__"dream2",
		"south":  __DIR__"dream4",
	]));
        set("objects", ([
        	__DIR__"npc/evil3": 1,
    	]) );
        set("no_fly",1);
        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


int valid_leave(object me,string dir) {
        object evil;
	
	if( userp(me) && dir == "south") {
		evil=present("evil",this_object());
		if (evil) 
		if (!evil->query("statue")){
			message_vision(HIW+evil->name()+"��ס��$Nǰ���ĵ�·��\n"NOR,me);
			return notify_fail("");
		}
	}
	return 1;
}