// blade_gui_tou.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit BLADE;

void create() {
	set_name("��ͷ��", ({ "blade" }) );
	set_weight(5000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("material", "iron");
		set("long", "���ֺ��صĴ󵶣�ǿ��ϲ���ã�������Լʮ���ء�\n");
		set("wield_msg", "$N���һ�ѱ���߲���$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
	}
	::init_blade(15);
}
