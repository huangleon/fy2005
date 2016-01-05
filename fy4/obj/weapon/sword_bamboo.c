// sword_bamboo.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit SWORD;
	
void create() {
	set_name("��", ({ "bamboo sword", "sword" }) );
	set_weight(100);
	if(clonep()) {
		set_default_object(__FILE__);
	} else {
		set("unit", "��");
		set("value", 2);
		set("material", "bamboo");
		set("long", "����һ����ϰ�����õ��񽣣����⴦�ò�����������������ͬ�顣\n");
		set("wield_msg", "$N�ó�һ�������õ�$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	::init_sword(1);
}
 
