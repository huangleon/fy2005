#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(BLU"ħ�۽�"NOR, ({ "mageye sword","sword" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long", "��������ˮ��Ľ����ϣ�ֻ��һ��Ͼ�ã�����������һֻħ�ۡ�\n");
                set("value", 0);
                set("material", "steel");

        set("wield_msg", "$N��������һ��������ˮ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_sword(10);
}
