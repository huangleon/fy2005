#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("���߰�" NOR, ({ "needle bag","bag" }) );
    set_weight(800);
    set_max_encumbrance(800);
			if( clonep() )
            set_default_object(__FILE__);
    else {

            set("unit", "��");
            set("material", "cloth");
            set("long", "һ��СС�����߰����������ţ������ľ�������\n");
			set("value",3000);
			set("closed", 1);
		  }
    ::init_item();
}

void init()
{
	if(environment()==this_player())
		add_action("do_open","open");
}

int is_container() {return 1;}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}


int do_open(string arg)
{
	object gold;
	if(arg != "bag" && arg != "needle bag" && arg != "���߰�") return 0;
	if(!query("closed"))
		return notify_fail("������߰����������ǿյģ�\n");
	if (!this_player()->query("m_success/����ͭ��"))
		return notify_fail("������߰�����������Ǽ���������ɫ�����롣\n���ƺ����ò�����Щ������\n");

	set("closed",0);
	set("value", 0);
	gold = new(__DIR__"sp_needle");
	gold->set("name","����ɫ��ϸ��");
	gold->move(this_object());

	gold = new(__DIR__"sp_needle");
	gold->set("name","����ɫ��ϸ��");
	gold->move(this_object());

	gold = new(__DIR__"sp_needle");
	gold->set("name","����ɫ��ϸ��");
	gold->move(this_object());

	gold = new(__DIR__"sp_needle");
	gold->set("name","����ɫ��ϸ��");
	gold->move(this_object());

	gold = new(__DIR__"sp_needle");
	gold->set("name","����ɫ��ϸ��");
	gold->move(this_object());

	return notify_fail("������߰�����������Ǽ���������ɫ�����롣\n��һת�ͻȻ�����˹������ƺ������õõ����ǡ�\n");
}
