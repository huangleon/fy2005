// bamboo_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("��", ({ "bamboo sword", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 5);
                set("material", "bamboo");
                set("long", 
"����һ����ϰ�����õ��񽣣����⴦�ò�����������������ͬ�顣\n");
                set("wield_msg", "$N�ó�һ�������õ�$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(10);
}
 
