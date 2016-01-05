// bracelet.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit WRISTS;

void create() {
	set_name("����", ({ "bracelet"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ֧����\n");
		set("unit", "֧");
		set("value", 0);
		set("wear_msg", "$N����ذ�һ��$n���������ϡ�\n");
		set("unequip_msg", "$N����ذ�$n�������ϳ���������\n");
	}
	::init_wrists();
}

