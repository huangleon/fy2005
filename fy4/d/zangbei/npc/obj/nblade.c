#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name( "����", ({ "spade" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ���ֱ��̵ܶĲ��ӡ�\n");
                set("value", 500);
                set("material", "wood");
        }
        ::init_blade(10);
}


