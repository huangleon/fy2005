// bamboo_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;


void create()
{
        set_name(GRN"����ǹ"NOR, ({ "bamboo spear", "spear" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 200);
                set("material", "bamboo");
                set("long", 
"����һ�Ѵ������ɵ���ǹ��ǹ�⴦�ò�����������������ͬ�顣\n");
                set("wield_msg", "$N���һ����ǹ�õ�$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        ::init_spear(10);
}
 
