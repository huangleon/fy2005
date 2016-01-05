// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ�ź������±��ϵ�С���������ڲ���֦Ҷʮ��ï�ܣ������̸������
���±ڣ��ɼ�����Ѿá��������ܣ��ƺ������ƣ��������С����Ͽ������˴���
�������ӣ��޿�����֮�
LONG
        );
 	set("objects", ([
		__DIR__"obj/treetop": 1,
	]) );
	set("outdoors", "huangshan");
	set("coor/x",-25);
	set("coor/y",-5);
	set("coor/z",10);
	setup();
}

void init() {
	add_action("do_climb", "climb");
}

int do_climb(string arg) {
    	object obj, me;
    	int i;
 
    	me = this_player();
    	if(!arg || arg=="") return notify_fail("��Ҫ��ʲô��\n");
    	if(me->is_busy()) return notify_fail("������æ��\N");
    	if(arg == "up" || arg == "����" || arg == "�ͱ�"){
		me->start_busy(2);
    	    	message_vision("$Nץ�����ӣ����ȵ�˳���ͱ�������ȥ��\n", me);
        	call_out("fliping",2,me);
	}
	return 1;
}

int fliping(object me){
	object rope, room;
		
    	if( objectp(me) && !me->is_ghost()) {   
	    	tell_object(me,HIY"\nͻȻ�䡰ž����һ�����Ӷ��ѣ���æ����̽��ץסһ��ͻ������ʯ����������ȥ��\n\n"NOR);
        	room = find_object(__DIR__"taoyuan");
        	if(!objectp(room))      	room = load_object(__DIR__"taoyuan");
        	room->set("marks/climb", 0);
        	me->move(__DIR__"taoyuan");
        	message_vision("$N������µش���������������\n", me);
    	}
        return 1;
}


void reset () {
    	object *inv;
    	object item1, treetop;
    	::reset();
    
    	treetop = present("treetop", this_object());
    	inv = all_inventory(treetop);
    	if( !sizeof(inv) ) {
    		item1 = new(__DIR__"obj/jianzi");
        	item1->move(treetop);
   	}   
}
