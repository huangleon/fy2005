
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("��ʯ��", ({ "box", "stone box"}) );
    set_weight(800);
    set_max_encumbrance(500);
    if (clonep())
    	set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("long", "һ������ɫ��Сʯ�С���������Ű�����(open)\n");
		set("value", 0);
		set("no_stack",1);
       	set("prep", "in");
    }
	::init_item();
}

int is_container() {return 1;}

void init()
{
   add_action("do_open","open");
}

int do_open(string arg)
{
	object me, ob, item;
	
	me = this_player();
	ob = this_object();
    if( !arg || arg != "box" ) {
    		return notify_fail("��Ҫ��ʲô��\n");
    	}
    	if(ob->query_temp("marks/opened")) {
    		return notify_fail("ʯ���Ѿ����򿪹��ˡ�\n");
	}
	
	if(query("box_owner")!= me) {
		message_vision("$N���Ŵ�Сʯ�У�С������һ����ʯͷ����˿������\n", me);
		return 1;
	}	
	
	if(me->query("force_factor")<50) {
		tell_object(me,"���۵���ͷ�󺹣���������������С����ʯͷ����˿������
��������50�������\n");
		return 1;
	}
		
	message_vision("$N������$n�򿪣�����\n", me, ob);
    	set("long", "һ����ɫ��Сʯ�У��и��Ѿ������ˡ�\n");

	item = new(__DIR__"paper");
	message_vision("$N����$n��Ķ��������ȵ�˵����������\n", me, ob);
	item->move(ob);

	me->set("annie/gstone",1);	
	me->delete_temp("marks/search_turtle");
	me->delete("marks/turtle_room");
	
   	ob->set("value", 0);
	ob->set_temp("marks/opened",1);
    return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
