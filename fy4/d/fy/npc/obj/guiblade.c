// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("��ͷ��", ({ "blade" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "iron");
                set("long", "���ֺ��صĴ󵶣�ǿ��ϲ���ã�������Լʮ���ء�\n");
                set("wield_msg", "$N���һ�ѱ���߲���$n�������С�\n");
                set("unequip_msg", "$N�����е�$n������䡣\n");
        }
        ::init_blade(15);
}
