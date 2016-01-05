// blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit BLADE;

void create() {
	set_name("�����䵶", ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("level_required",70);
		set("material", "iron");
		set("long", "����һ�������ڱ��������䵶��\n");
		set("wield_msg", "$N�������г��һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������������ʡ�\n");
	}
	::init_blade(85);
}
