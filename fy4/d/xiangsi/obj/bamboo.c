#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("��������", ({ "bamboo","����"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ƭ");
		set("long", "һƬ�������͸��ɫ������pick��\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

int do_pick(string arg)
{
	object bamboo,me = this_player();
	if ( !arg && arg != "bamboo" && arg != "����" )
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision(CYN"$N�����ȥ���������ӡ�\n"NOR,me);
	if (me->query_str() < 40 /*|| environment()->query("picked")*/)	// 
		return notify_fail("�������Ӽ�Ӳ�쳣�����ǰ��۲�����\n");
	environment()->set("picked",1);
	message_vision(CYN"ֻ����������һ����һ�����Ӧ�����ϡ�\n"NOR,me);
	bamboo = new(__DIR__"bamboo2");
	bamboo->move(this_player());
	destruct(this_object());
    return 1;
}

void init()
{
	add_action("do_pick","pick");
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

