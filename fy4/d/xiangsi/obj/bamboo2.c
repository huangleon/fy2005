#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(HIG"�������"NOR, ({ "bamboo" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���������͸��һ˿����ɫ����͡�\n");
		set("value", 0);
		set("rigidity", 5);
        set("material", "wood");
        set("wield_msg", "$N�ó�һ��$n�������С�\n");
        set("unwield_msg", "$N�������е�$n��\n");
		set("count",10+random(20));
    }
    ::init_staff(1);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int damage;
	if( random(me->query_kar()) < victim->query_kar()) return 0;
	if (query("count")<=0) return 0;
	add("count",-1);
	damage = me->query_kar();
	if (damage>40) damage = 40;
	victim->receive_wound("gin", damage*5);
	victim->receive_wound("sen", damage*5);
	victim->receive_wound("kee", damage*10);
	me->receive_heal("gin", damage*3);
	me->receive_heal("kee", damage*5);
	me->receive_heal("sen", damage*3);
	return HIG "��������ϵ�Ѫɫһ�ۣ�ȴ��������ɢ�˿�ȥ������\n"NOR;
}




/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

