#include <weapon.h>

inherit BLADE;
#include <ansi.h>

void create()
{
        set_name(HIY"�𱳴󿳵�"NOR, ({ "gold blade","blade" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѳ����Ľ𱳴󿳵���\n");
                set("value", 1000);
		set("rigidity", 2000);
                set("material", "steel");
        }
        ::init_blade(10);
}
