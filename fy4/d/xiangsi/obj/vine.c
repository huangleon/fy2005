// annie. 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
	set_name("����", ({ "vine", "����" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","inside");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "Ƭ");
	    set("long", "ï�ܵ�������������Ƭ���±ڡ�\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


void init()
{
	add_action("do_climb", "climb");
}


int do_climb(string arg)
{
	object me;
	me = this_player();
	if (arg == "cliff" || arg == "ɽ��")
		return notify_fail("ɽ�ڶ�����˵̫���ˣ���ô��������ȥѽ��\n");
		
	if(arg != "����" && arg != "vine")
		return notify_fail("��Ҫ��ʲô��\n");
	
	if (me->is_fighting() || me->is_busy())
		return notify_fail("��������æ��\n");
	
	message_vision("$Nץס��������������ɽ�����ʵǶ�ȥ��\n",me);
	me->move(load_object("/d/xiangsi/shipai"));
	me->perform_busy(1);
	message("vision",me->name()+"��ɽ������������������",environment(me),me);
	return 1;
}

