// sword_long.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
	set_name(HIG"���̴�"NOR, ({ "snake sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѱ������ͨ��Ө�̵��������������ղ����µı̲���һ��һ���ĵ��ź��⡣
������ȴ���ŷ������µ����ӻ��ơ������У�������̵�����������С����β���Σ����ڽ���֮�ϡ�
�ݴ�����ԭ�����Ϲ�ʱ����������������������а���������������������������,������������\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��������ӯ��һ����Χ����$N�����$n��ʱ֮�仯�����ߺ�����\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	::init_sword(80);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object snake;
	if (random(4))
	{
		if (me->query_temp("max_snake")<3)
		{
			message_vision( HIG "$N����"+name()+ HIG "�������ǣ�һ����ӨӨ��С�ߴӽ�����Ȼ�����������������$n��\n"NOR,me,victim);
			snake = new(__DIR__"spiritsnake.c");
			snake->invocation(me);
			snake->move(environment(me));
			snake->kill_ob(victim);
			me->add_temp("max_snake",1);
		}
	}
    return 0;
}
