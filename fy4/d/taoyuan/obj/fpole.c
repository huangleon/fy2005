
inherit ITEM;

void create()
{
	set_name("�����", ({ "fish pole" , "pole", "�����"}) );
	set_weight(400);
    set_max_encumbrance(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("prep", "on");
		set("long", "һ�����������ɵĵ���ˣ�����ͨ�����ʮ�ֺÿ��� \n");
		set("value", 150);
	}
    ::init_item();
}

void init()
{
        add_action("do_use", "fishing");
}

int do_use(string arg){
	object me;
	me = this_player();
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("����������æ��\n");
	}
    tell_object(me,"���ͳ�һ��" + this_object()->name() + "��\n");
    environment(me)->fish_notify(this_object());

    return 1;
}

int is_container() { return 1; }

