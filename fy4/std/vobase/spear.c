#include <weapon.h>

inherit SPEAR;
inherit F_VO;

void create()
{
        set_name("��ǹ", ({ "spear" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ǹ��\n");
                set("value", 100);
                set("material", "steel");
        }
        init_spear(10);
}
