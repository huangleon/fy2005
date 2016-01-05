// blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit BLADE;

void create() {
	set_name("����", ({ "blade" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
		set("long", "����һѰ���ĵ�����������Լʮ�����߽��ء�\n");
		set("wield_msg", "$N���һ���弣�߰ߵ�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	set("value", 0);

	::init_blade(5);
}
