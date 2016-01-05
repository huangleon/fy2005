// cloth_whitesilk.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name(HIW "ѩ�׳���" NOR, ({ "white silk cloth", "cloth" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ƿ��Ƴ�ʱ����ʱ�ֵ��·���\n");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
