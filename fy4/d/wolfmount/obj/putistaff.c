#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIY"���ᷨ��"NOR, ({ "puti staff", "staff" }) );
	set_weight(60000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
		set("rigidity", 1000);
		set("value", 10000);
		set("long", "һ����������ľ���Ƶķ��ȣ������֣��ɱܰ�а���ݴ����Ƿ���ʥ�\n");
		set("wield_msg", "$N�ó�һ��$n�������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	::init_staff(150);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    int pro;
    int dam_m, dam_f, dam_a;
    dam_m = (int) me->query("mana");
    dam_f = (int)me->query("force");
    dam_a = (int)me->query("atman");
    if((int)victim->query("mana") > (int)victim->query("max_mana")*1/2){
    	victim->add("mana",-dam_m/5);
    	me->add("mana", dam_m/100);
    }
    
    if((int)victim->query("force") > (int)victim->query("max_force")*1/4){
    	victim->add("force", -dam_f/5);
    	me->add("force", dam_f/100);
    }
    if((int)victim->query("atman") > (int)victim->query("max_atman")*1/3){
    	victim->add("atman", -dam_a/5);
    	me->add("atman", dam_a/100);
    }
    return HIY"���ᷨ�ȷ��������𻪣���$n������ס��$nֻ�����������Ŷ�ȥ����\n"NOR;
}
 
