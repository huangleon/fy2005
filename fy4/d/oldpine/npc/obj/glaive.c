// glaive.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("��ͷ��", ({ "glaive" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 15);
                set("material", "steel");
                set("level_required",25);
                set("long", "����һ�ѳ��صĹ�ͷ���������ϵ���һ����ª�ɲ��Ĺ�ͷ���ѿ������Ц��\n");
                set("wield_msg", "$N���һ�ѱ����б���$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
        init_blade(45);
}
