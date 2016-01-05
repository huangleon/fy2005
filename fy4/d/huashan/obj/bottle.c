
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("С��ƿ", ({ "bottle", "jade bottle"}) );
    set_weight(800);
    set_max_encumbrance(100);
    if (clonep())
    	set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("long", "һ������͸����ɫ��С��ƿ��ƿ�ǽ��ա�\n");
		set("value", 1);
        	set("prep", "in");
    		set("value", 1);
    		set("is_closed", 1);
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
    	if( !arg || (arg != "bottle" && arg != "��ƿ") ) {
    		return notify_fail("��Ҫ��ʲô��\n");
    	}
    	if(!query("is_closed")) {
    		return 0;
	}
	message_vision("$NС������ذ�$n����ת��������һ��ҩ��Ʈ����\n", me, ob);
	item = new("/d/wolfmount/npc/obj/ginyao");
	if(objectp(item)){
		item->move(ob);
		item->set("base_value",0);
	} 
    	set("long", "һ������͸����ɫ��С��ƿ��ƿ���Ѿ����򿪡�\n");
	set("is_closed",0);
    	return 1;
}

