// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <weapon.h>
inherit DAGGER;
void create()
{
	string *order=({"��", "��", "��", "��","��"});
        set_name((order[random(5)]) +"ɫ���廨��", ({ "needle", "flower needle"}) );
    set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
        set("long", "һ��ϸ�������룬��ƮƮ���ƺ�Ҫ����ȥ��\n");
        set("value", 500);
		set("material", "steel");
	}
    ::init_dagger(20);
	set("wield_msg", "$N�ӻ�������һ֧$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");
}
