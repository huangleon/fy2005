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
		set("value", 400);
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
        badint = COMBAT_D->magic_modifier(me, victim, "kee", victim->query_skill("unarmed")/3);
        victim->receive_wound("kee",badint, me);
        return HIR "$N�˵���һ�����е�"+name()+ HIR "ͻȻ����$n��������\n"NOR;

}
*/
