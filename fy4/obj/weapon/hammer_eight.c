// hammer_eight_corners.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit HAMMER;

void create() {
	set_name("�˽Ǵ�", ({ "eighthammer" }) );
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѱ˽�ͭ���������ġ�\n");
		set("value", 1);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	::init_hammer(3);
}
