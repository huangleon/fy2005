inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��Ѽ", ({ "fried duck","duck" }) );
	set_weight(80);
	set_max_encumbrance(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ������Ŀ�Ѽ���Ĺ����ҵ�����ƺ��ж�����cut����\n");
		set("unit", "ֻ");
        	set("closed", 1);
		set("value", 0);
		set("food_remaining", 3);
		set("food_supply", 100);
	}
	::init_item();
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","cut");
}
int do_open(string arg)
{
	object me, ob;
        if( !arg ||( arg != "duck" && arg != "fried duck") )
                return notify_fail("��Ҫ�ʲô��\n");
	me = this_player();
	ob = this_object();
	if(ob->query("closed") == 1)
	{
		message_vision("$N�õ�С�ĵؽ�$n�п���������\n", me, ob);
		ob->set("long", "һֻ������Ŀ�Ѽ���Ѿ����п������������͡�\n");
		ob->set("closed",0);
     	  	return 1;
	}
	else
	{
		message_vision("$N�Ѿ����п��ˣ�������\n", ob);
	       	return 1;
       	}
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
