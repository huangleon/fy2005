#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( CYN"���ν���"NOR, ({ "forcesword" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "����");
		set("long", "��������������Ϊ������\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 1000);
		set("wield_msg", "$N�����Ƽ䣬$n�����������ֻ�������ӹ�������絶��\n");
		set("unwield_msg", "$n��$N����һ�����š�\n");
	}
	::init_sword(110);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int badint=0;
	badint = 
	victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth") * 2  ;
	badint += badint /(2+ random(3));
	if( badint && !random(3)){
	 message_vision( HIC "$N�������ۣ�˿˿����͸ָ������ֱȡ$n�����ţ�\n"NOR,me,victim);
	}
	else badint = badint/5;
        return badint;
}