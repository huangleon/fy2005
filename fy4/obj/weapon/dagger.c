// dagger.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit DAGGER;

void create() {
	set_name("ذ��", ({ "dagger" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ��ذ�ס�\n");
		set("value", 1);
		set("material", "steel");
		set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���뻳�С�\n");
	}
	::init_dagger(5);
}
