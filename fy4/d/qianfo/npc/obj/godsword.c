// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("��ɫ����", ({ "sword" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "stone");
		set("long", "һ�Ѽ�������ɫ������\n");
		set("weapon_prop/agility",1);
	}
	::init_sword(10);
}
