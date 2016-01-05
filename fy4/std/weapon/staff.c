// staff.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//	ն""��"	"��""��""��""��""��"
//	"��" post_action:  "bash_weapon"
//	"��" post_action : "throw_weapon,

#include <weapon.h>
inherit WIELD;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
	}
}

varargs void init_staff(int damage, int flag) {
	if(!clonep()) {
		set("weapon_prop/damage", damage);
		set("flag", (int)flag | LONG | TWO_HANDED);
		set("weapon_wielded", W_STAFF);
		set("skill_type", "staff");
		if(!query("verbs")) {
			set("verbs", ({ "��","��" }) );
		}
	}
	::init_wield();
}

