#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "��");
        set("long",@LONG
��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ�����ڵ㶼û�С�
����ֻ�к��˵��Ĵ�����listen wave����
LONG
        );
	set("coor/x",-310);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
}
void init()
{
	add_action("do_look",({"look","listen"}));
}

int do_look(string arg)
{
 	object me,room;
 	
 	me = this_player();
 	
 	if(!arg || arg!= "wave") {
 		return 0;
 	} 	
 	
 	if(!random(5)) {
  		tell_object(me, BLU "ͻȻ�䣬��Ĵ������ˣ�һ�����˴������㱻������У�����\n"NOR);
  		room = load_object(__DIR__"anbian");
  		me->move(room); 
  		return 1;
 	} else {
 		tell_object(me, BLU "���˾�����һͷͷ���ǣ���ҧ����Ĵ���\n"NOR);
 		return 1;
 	}
}
