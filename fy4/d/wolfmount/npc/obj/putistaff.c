#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIY"���ᷨ��"NOR, ({ "putistaff", "puti staff", "staff" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
		set("rigidity", 1000);
		set("experience",6000000);
		set("value", 10000);
		set("long", "һ����������ľ���Ƶķ��ȣ������֣��ɱܰ�а���ݴ����Ƿ���ʥ�\n");
		set("wield_msg", "�����ҫ����ͬ���绮�Ƴ��գ�һ��$nԾ����$N���С�\n");
		set("unequip_msg", "���һ�����ţ�$N�������е�$n��\n");
	}
	::init_staff(150);
}

int query_autoload() { return 1; }

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
    	int pro;
    	int dam_m, dam_f, dam_a;
    	
    	dam_m = (int) me->query("mana");
    	dam_f = (int)me->query ("force");
    	dam_a = (int)me->query ("atman");
    	
    	if((int)victim->query("mana") > dam_m/5){
    		victim->add("mana",-dam_m/5);
    		me->add("mana", dam_m/5);
    	}
        
        if((int)victim->query("force") > dam_f/5){
    		victim->add("force", -dam_f/5);
    		me->add("force", dam_f/5);
    	}
    	
    	if((int)victim->query("atman") > dam_a/5){
    		victim->add("atman", -dam_a/5);
    		me->add("atman", dam_a/5);
    	}
    	
    	if (me->query("mana")>2*me->query("max_mana")) me->set("mana",2*me->query("max_mana"));
    	if (me->query("atman")>2*me->query("max_atman")) me->set("atman",2*me->query("max_atman"));
    	if (me->query("force")>2*me->query("max_force")) me->set("force",2*me->query("max_force"));
    	
    	return HIY"���ᷨ�ȷ��������𻪣���$n������ס��$nֻ�����������Ŷ�ȥ����\n"NOR;
}
 
*/

