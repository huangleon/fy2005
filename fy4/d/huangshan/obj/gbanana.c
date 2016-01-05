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
        set("value", 80);
        set("skin_remain", 10);
    }
	::init_item();
}

void init () {
	if(this_player()==environment()) {
		add_action("do_peel", "peel");
	}
}

int do_peel(string arg)
{
	object banana, me, weapon, obj;
	
	if (!arg || arg != "banana" && arg != "���㽶" && arg != "�㽶") {
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	me = this_player();
	if((int)query("skin_remain") >=1) {
		message("vision", "���Ȳ������ذ������㽶���Ծ��ط������澹Ȼ����һ���㽶Ƥ��\n", me);
		message("vision", me->name() + "�Ȳ������ذ������㽶������¶���Ծ�����ɫ��\n",
				environment(me), me);
		add("skin_remain", -1);
	} else {
		tell_object(me, "����������һ���㽶������ʲô��û�С�������¶���������ɫ��\n");
		message("vision", me->name() + "���������㽶Ƥ������¶���������ɫ��\n",
				environment(me), me);
		obj = new(__DIR__"bananaskin");
		obj->move(me);
		destruct(this_object());
	}
	return 1;
}
