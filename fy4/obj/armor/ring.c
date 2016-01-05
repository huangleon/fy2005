// ring.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit FINGER;

void create() {
	set_name("��ָ", ({ "ring"}) );
	set_weight(10);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ֧�ں����İ�ָ��\n");
		set("unit", "֧");
		set("value", 15);
		set("wear_msg", "$N����ذ�һ��$n������ָ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n����ָ�ϳ���������\n");
	}
	::init_finger();
}

