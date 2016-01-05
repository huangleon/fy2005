// mask.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit MASK;

void create() {
	set_name("��ɴ", ({ "mask"}) );
	set_weight(2);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ɴ��\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 3);
		set("armor_prop/personality", -10);
		set("armor_prop/id", ({ "unknown" }));
		set("armor_prop/name", ({ "������" }));
		set("wear_msg", "$N����ذ�$n�������ϡ�\n");
		set("unwield_msg", "$N����ذ�$n�����ϳ���������\n");
	}
	::init_mask();
}
