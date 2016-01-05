// cloth.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(HIW"����"NOR, ({ "silver armor" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
		set("armor_prop/armor", 10);
		set("long","һ����ɫ�Ŀ��ס�\n");
		set("value", 9000);
	}
	::init_cloth();
}
