//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(HIC"Բ���䵶"NOR, ({ "moonblade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����״�����صĵ�������·��е�������\n");
		set("value", 1);
		set("material", "steel");
		set("wield_msg", "$N��$nͻȻ���ʣ��������û�п���$N�ε���\n");
		set("unwield_msg", "$N��$n�����ʡ�\n");
		set("for_modao",1);
	}
	::init_blade(25);
}


/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
		if(random(damage_bonus) < 250 ) return 0;
        badint = victim->query_skill("unarmed");
//      if(badint && !victim->query_temp("weapon")) 
//      && victim->query_skill_mapped("unarmed") == "dragonstrike")
//      message_vision( HIR "$N�˵���һ�����е�"+name()+ HIR "ͻȻ����$n��������\n"NOR,me,victim);
//        return badint;
        victim->receive_wound("kee",badint/3);
        return HIR "$N�˵���һ�����е�"+name()+ HIR "ͻȻ����$n��������\n"NOR;

}
*/
