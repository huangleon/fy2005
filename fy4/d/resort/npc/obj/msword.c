// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name("�ݼ���", ({ "wangsword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѽ���ֻ����ָ���������\n");
		set("value", 200);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N�ӳ�Ƥ�����г��һ��ֻ����ָ���$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ĳ�Ƥ���ʡ�\n");
	}
	init_sword(80);
}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
	if(damage_bonus < 300 ) return 0;
        badint = victim->query_skill("blade") * 10;
        if(badint && victim->query_temp("weapon") && 
		victim->query_skill_mapped("blade") == "bat-blade")
        message_vision(HIR"$N�˽���һ�����е�"+name()+ HIR"ͻȻ����$n��������\n" NOR,me,victim);
        return badint;
}
*/