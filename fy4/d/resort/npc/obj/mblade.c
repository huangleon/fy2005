
#include <weapon.h>
#include <ansi.h>
inherit BLADE;


void create()
{
        set_name("���µ�", ({ "wangblade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ѩƬ����������ı�����\n");
                set("value", 200);
		set("rigidity", 200);
                set("material", "steel");
        }
        init_blade(30);

        set("wield_msg", "$N����Ƥ�����г��һ��ɱ�����˵�$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�����Ƥ�����С�\n");


}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
	if(damage_bonus < 300 ) return 0;
        badint = 
        victim->query_skill("sword") * 10;
        if(badint && victim->query_temp("weapon") && 
	victim->query_skill_mapped("sword") == "doomsword")
        message_vision( HIR "$N�˵���һ�����е�"+name()+ HIR "ͻȻ����$n��������\n" NOR,me,victim);
        return badint;
}

*/