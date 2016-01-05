inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��������");
        set("long", @LONG
���������������������ˣ�������ߡ����ɣ�������Ѿ֦�����εĴ�Ҷ����ס
�˰����ա������ŵ������ɹ������㣬������Χ������ģ�ʲôҲ�����壬ֻ��
��ߴߴ�������������
LONG
        );
        set("exits", ([ 
  		"down" : __DIR__"pine1",
	]));

        set("item_desc", ([
    	]));
        set("in_tree",1);
        set("nest",1);
        set("coor/x",-1900);
		set("coor/y",720);
		set("coor/z",25);
		set("map","zbeast");
		setup();
        
}

void init() {
	add_action("do_jump","jump");
	add_action("do_look","look");
	add_action("do_smell","smell");
	add_action("do_listen","listen");
}

int do_smell(){
	tell_object(this_player(),"�ۣ���һ����Ҷ�����㡣\n");
	return 1;
}

int do_listen(){
	tell_object(this_player(),"ߴߴ������������ò����֡�\n");
	return 1;
}

int do_look(string arg) {
	
	object me = this_player();
	
	if (arg == "Ѿ֦" || arg == "��Ҷ" || arg == "��Ҷ" || arg == "����") {
		if (me->query_temp("marks/zangbei/����")) {
			tell_object(me,"��Ҷ���ܵģ���ס��������գ�����������ָ���Ǹ�����
�����м������ѣ�ߴߴ�����ĺò����֣��������������ȥ������\n");
			me->set_temp("marks/zangbei/����",1);
		} else
			tell_object(me,"��Ҷ���ܵģ���ס��������ա�\n");
		return 1;
	}
	return 0;
}		



int do_jump(string arg){
	object me, room,item;
	
	me=this_player();
	
	if (!arg || (arg != "nest" && arg!="����") ) {
		tell_object(me,"��Ҫ���Ķ�����\n");
		return 1;
	}
		
	if (!me->query_temp("marks/zangbei/����")) {
		tell_object(me,"��������У��������Ķ���\n");
		return 1;
	}
			
	message_vision("\n$N��һ���������������ѵķ�������һԾ��\n\n",me);
	
	room = find_object(__DIR__"temple5");
	if (!objectp(room)) room= load_object(__DIR__"temple5");
	
	if (me->query_skill("move",1)<100) {
		message_vision("$Nһ�Ųȿգ�˫������к���ץ�˼��£�һ������������ȥ��\n\n",me);
		message("vision","ֻ����ͨһ�������ϵ���һ��������\n",room);
		me->move(room);
		me->unconcious();
		return 1;
	}
		
	tell_object(me,YEL"�㵥������֦��һ��һԾ����žһ������֦���ˣ�
���æ֮��������������һ����\n"NOR);
	
	if (query("nest")) {
		tell_object(me,YEL"ץ��һ��ӲӲ�Ķ�����\n\n"NOR);
		item = new(__DIR__"obj/t_item5");
        set("nest",0);
         	if (!item->move(me))
         		destruct(item);
         	else	{
         		tell_object(me,YEL"��Ҳ������ʲô���Ͻ��������\n\n"NOR);
         	}         		
	} else 
		tell_object(me,YEL"���ץ��һ����ࡣ������\n");
	
	message_vision("$N������������֮����ֱͨͨ����������ȥ��\n\n",me);
	message("vision","ֻ����ͨһ������������һ��������\n",room);
	me->move(room);
	return 1;
}

void reset(){
	set("nest",1);
	::reset();
}