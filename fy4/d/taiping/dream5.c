#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"��Ũ�μ���"NOR);
        set("long", @LONG
��߲��һ����һ���һ�ͻȻ�������ǰ���£������������ſ���һ����������
��Ļ���֮��վ�������������ˣ�Ҳ�����ޡ���ͨ��͸����ȴ�ֲ������Ρ�һ����
�Ĺ��������ɼ�����ߵ�����֮�ϸ���һ��ȭ��ĺ��ġ��ĺ����Ҫ��Ѫ��ȴû��
Ѫ���£�����������һ��Ѫ��û�С�������Ļ����Ȼ��£�����ֻ���һ�Ż����
Ͷ�����ɽ��Ҳ�Ƶ����档
LONG
        );
        set("exits", ([ 
		"south":  __DIR__"dream6",
		"north":  __DIR__"dream4",
	]));
        set("objects", ([
        	__DIR__"npc/evil5": 1,
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