// axe_short.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit AXE;

void create() {
    	set_name("���Ƹ�", ({ "axe" }) );
    	set_weight(40000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("value", 2000);
		set("material", "iron");
        	set("wield_msg", "$N���$n������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
    	::init_axe(10);
}

