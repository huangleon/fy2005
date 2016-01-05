#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("��ɫ����", ({"red ball", "redball", "ball"}) );
    set_weight(30);
	set("unit", "��");
	set("long", "һ������ɫ��������������Ű�����(open)\n");
	set("value", 200);
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
		message_vision("$N΢һ������ֻ��һ�����죬�����鿪��һ��ҩ�������˿�����\n", me);
        seteuid(getuid());
		medicine = new(__DIR__"medicine");
		if(objectp(medicine)){
		    medicine->move(me);
		}
		destruct(ob);
	} else {
		message_vision("�����������������������ѵ���ʹ��\n", this_object(),me);
	}
    return 1;
}

