#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"��Ũ�μ���"NOR);
        set("long", @LONG
������֮�У��һ��뺮��֮�䣬������һ�����ε�·�����������һ�����ε�
·֮�ϡ�̧ͷ������һ�ۡ����沢û�����죬ֻ�к����ڹ������һ��ڷ��裬����
��Х������Ʈ�������ںη������ںδ���û��ͷ�ϵ����죬û�н��µĴ�أ�ֻ��
��������������档
LONG
        );
        set("exits", ([ 
		"south":  __DIR__"dream5",
		"north":  __DIR__"dream3",
	]));
        set("objects", ([
        	__DIR__"npc/evil4": 1,
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