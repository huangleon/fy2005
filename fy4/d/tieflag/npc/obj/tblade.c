// tblade.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIG"����һ��"NOR, ({ "tblade" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",

"����һ��������ˮ��������Ҷ���䵶\n"
);
                set("value", 0);
                set("material", "steel");
                set("rigidity", 1000000);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
                set("weapon_prop/agility", 10); 
                set("weapon_prop/personality", 10);
                set("female_only", 1);
                set("no_get",1);
                set("no_drop",1);
        }

        ::init_blade(10);

}


void owner_is_killed(object killer)
{
        message_vision(HIG"\n \n ���� "NOR +"���ڵ��ϣ�ת�˼���Ȧ�ӣ���Ȼ��ʧ�ˡ�
\n\n");
        destruct(this_object());
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    return HIR "�䵶���£�ӳ��$N�����绨��$n���ɵó���\n"NOR;
   
}
 
