// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name("ͭ����", ({ "fozhong" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "wood");
		set("long", "һ���̰߰ߵ�ͭ���ӡ�\n");
		set("weapon_prop/karma",1);
	}
	::init_hammer(5);
}
