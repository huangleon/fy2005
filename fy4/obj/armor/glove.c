// gloves.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit HANDS;

void create() {
	set_name("����", ({ "gloves"}));
	set_weight(10);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "һ˫�ڲ����ס�\n");
		set("value", 9);
		set("material", "cloth");
	}
	::init_hands();
}

