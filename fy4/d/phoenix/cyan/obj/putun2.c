#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����", ({ "����","putuan"}) );
	set_weight(500);
	set_max_encumbrance(500);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","on");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��СС�����ţ��������ƺ�����ʲô���¡�\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }


void init()
{
	if (present("����",environment()) == this_object())
		if (present("���� 2",environment()))
			destruct(present("���� 2",environment()));
	add_action("do_move","move");
}

int do_move(string arg)
{
	object bamboo,me = this_player();
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (!bamboo = present(arg,environment()))
		return notify_fail("��Ҫ��ʲô��\n");
	if (bamboo != this_object())
		return notify_fail("��Ҫ��ʲô��\n");
	if (bamboo=present("liaohen",environment()))
		if (!bamboo->is_fighting())
			return notify_fail("�˺�ʦ̫���������������֮�ϡ�\n");
	if (me->is_fighting())
			return notify_fail("�����ڿղ����������ţ�\n");

	message_vision(CYN"$NС��������ƿ����š�\n"NOR,me);
	message_vision(CYN"ֻ�������·���ʲô���£�$Nʰ�����������뻳�С�\n"NOR,me);
	bamboo = new("/obj/book/chanting_51");
	bamboo->move(this_player());
	destruct(this_object());
    return 1;
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

