// blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
	set_name(WHT"���㵶"NOR, ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "iron");
		set("level_required",120);
		set("long", "
�����ǲ������÷�������һ��ͨ��͸�����㣬ǱӾ��������������ȫ���顣
��������ֻ����������֣���ν�����㡱��������㵶����һβ����������һ
�����к�Ƕ�뱳�����¡�\n");
		set("wield_msg", "$N�������г��һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������������ʡ�\n");
		set("experience",3000000);
	}
	::init_blade(105);
}
