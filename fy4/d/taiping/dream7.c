#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"��Ũ�μ���"NOR);
        set("long", @LONG
Ҳ��֪���˶�ã����˶�Զ����Χ���Ƿ���������뺮�������ҵ����溮��
��Ȼ�������һ����˻�ǽ�����������˱��ڡ����ڻ�ǽ��Ⱥħ���֣����������ԡ�
һ�������Ѽ��Ĺ����ͬʱ�����������ǰ�����������ֱ���������������ȴ
���ϲ����죬�²����أ��·�Ʈ���ڷ����С�
LONG
        );
        set("exits", ([ 
		"up":  __DIR__"dream8",
		"north":  __DIR__"dream6",
	]));
        set("objects", ([
        	__DIR__"npc/evil7": 1,
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
	
	if( userp(me) && dir == "up") {
		evil=present("evil",this_object());
		if (evil) 
		if (!evil->query("statue")){
			message_vision(HIW+evil->name()+"��ס��$Nǰ���ĵ�·��\n"NOR,me);
			return notify_fail("");
		}
	}
	return 1;
}