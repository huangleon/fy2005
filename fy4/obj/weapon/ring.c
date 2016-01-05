// ring.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <weapon.h>
inherit RING;

void create() {
	set_name("��ָ", ({ "ring" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ʯ�İ�ָ\n");
		set("value", 1);
		set("material", "steel");
		set("wield_msg", "$N�ӻ�������һ��$n������ָ�ϡ�\n");
		set("unwield_msg", "$N����ָ�ϵ�$n���������뻳�С�\n");
	}
	::init_ring(4);
}
