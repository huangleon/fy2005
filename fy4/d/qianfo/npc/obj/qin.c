// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("������", ({ "qin" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "wood");
		set("long", "һ����ɫ����Ĺ����١�������10��\n");
		set("timbre",10);
		set("wield_msg","$N�ӻ���ȡ��һ��$n������һ����Ȫˮ���������ָ����к������\n");
		set("unwield_msg","$N��$n���������\n");
	}
	::init_staff(5);
}

void init()
{
	if (environment(this_object()) == this_player())
		add_action("do_play","play");
}


int do_play(string arg)
{
	object me;
	me = this_player();
	if (!arg || (arg!="qin" && arg!="������" && arg!="��"))
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$Nһ�������٣����к���������ָ����к��һ����Ȫˮ������ӡ�\n",me);
	me->set_temp("played_qin",1);
	me->set("annie/������",1);
	return 1;
}
