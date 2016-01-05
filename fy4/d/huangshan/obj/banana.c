inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���㽶", ({ "banana", "xiang jiao" }) );
        set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "�ô���㽶����һ���ǳ��óԡ���������������Уţţ̣�\n");
        set("unit", "��"); 
        set("food_remaining", 4);
        set("food_supply", 10);
        set("value", 80);
        set("peeled", 1);
    }
	::init_item();
}

void init () {
	if(this_player()==environment()) {
		add_action("do_peel", "peel");
		add_action("do_eat", "eat");
	}
}

int do_peel(string arg)
{
	object banana, me;
	
	if (!arg || arg != "banana" && arg != "���㽶" && arg != "�㽶") {
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	me = this_player();
	if(query("peeled")) {
		message_vision("$N�Ȳ������ذ������㽶��\n", me);
		set("long", "����Ƥ���㽶������ʲô������԰ɡ�\n");
		set("peeled", 0);
		return 1;
	} 
}

int do_eat(string arg)
{
	object banana, me;
	me = this_player();
	
	message_vision("$N���㽶���������\n", me);
    me->add("food", 2);
    destruct(this_object());
    return 1;
}
