// axe_short.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit AXE;

void create() {
	set_name("�̸�", ({ "axe" }) );
	set_weight(6000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
		set("wield_msg", "$N�ӱ�����$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
		set("value", 0);
	::init_axe(5);
}
