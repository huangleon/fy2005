// hat.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create() {
	set_name(HIW"����"NOR, ({ "silver hat" }) );
	set_weight(1000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ɫ��ͷ����������ź�ӧ��\n");
		set("value", 2000);
		set("material", "iron");
	}
	::init_head();
}
