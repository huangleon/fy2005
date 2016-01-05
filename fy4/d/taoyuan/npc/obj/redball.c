#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"��ɫ����"NOR, ({"red ball", "redball", "ball"}) );
    set_weight(30);
	set("unit", "��");
	set("long", "һ������ɫ��������������Ű�����(open)\n");
	set("value", 1);
    set("unique_amount", 2);  
    ITEM_D->setup_unique(this_object());  
    ::init_item();
}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
}

int do_open(string arg)
{
	object me, ob, medicine, *inv, *players;
	int	str, i;
	
    if( !arg || arg != "��ɫ����" && arg != "red ball" && arg != "redball") 
    	return notify_fail("��Ҫ��ʲô��\n");
	
	me = this_player();
	ob = this_object();
	str = me->query_str();
	
	if(str > 20) {
		message_vision("$N΢һ������ֻ��һ�����죬�����鿪��һ����������ζ�����˿�����\n", me);
        inv = all_inventory(environment(me));
	    players = filter_array(inv, (: interactive($1) :));
        for(i=0; i<sizeof(players); i++) {
            players[i]->unconcious();
        }
		destruct(ob);
	} else {
		message_vision("�����������������������ѵ���ʹ��\n", this_object(),me);
	}
    return 1;
}

