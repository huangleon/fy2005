// hat.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit HEAD;

void create() {
	set_name("���ǻ�", ({ "zhuyu flower", "flower" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ǻ�ɢ���ŵ�����������\n");
		set("value", 8);
		set("material", "wood");
		set("holiday", "������");
	}
	::init_head();
}
