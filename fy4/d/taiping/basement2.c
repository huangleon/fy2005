#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
̧ͷ��ȥ������Ҳ��һƬ�ڰ����ڰ���ȴ�г����һƬ���������⡣��һƬ��
��ڰ���͸����ɫ�����м����Ƶ���������˸�����ǹ⡣��������ա��ǹ����
���������ղ������棬�Ǹ�������Χȴ�յ÷ǳ������ÿһ��ʯ�ڶ����ɹ��⣬��
��ʯ�ںϳ�����һ�����ɶ��ʯ�Ρ�
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"basement",
		"north": __DIR__"basement3",
		"up": 	__DIR__"yuanzi",
	]));
	set("objects", ([
        	__DIR__"npc/daniang2": 1,       	
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
	
	if( userp(me) && dir == "up" ) {
		evil=present("li daniang",this_object());
		if (evil) {
			message_vision(evil->name()+"��ס������Ծ��ȥ�ơ�\n",me);
			return notify_fail("");
		}
	}
	return 1;
}