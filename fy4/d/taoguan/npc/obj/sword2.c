// sword.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("跽�����", ({ "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ����ľ��ɵĹŽ�����������һ����ζ���������������δ��������
�ģ�ֻ�н���������������ϡ���Ա��ϵ�׭�֣��� �� �� �������������ֹ���
��������Ȼֻ��һ�ѷ��յ�ģ�͡�
\n");
                set("value", 18000);
                set("material", "wood");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
                set("weapon_prop/spirituality", 3);
         }

        ::init_sword(14);
}