// katana.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit BLADE;

void create() {
	set_name( "��ʿ��", ({ "katana" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ƽ��Ķ����ʿ����\n");
		set("value", 1);
		set("material", "steel");
		set("rigidity", 2000);
		set("wield_msg", "$N�ӵ����г��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	::init_blade(8);
}
