#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("�滨ǹ", ({ "spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���Ѫɳ���ϵĽ�ʿ���õĳ�ǹ��\n");
                set("value", 1);
                set("material", "steel");
        }
        init_spear(2);
}
