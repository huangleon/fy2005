#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
        set_name(RED"�ɻ�����"NOR, ({ "soul stealer" }) );
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("no_get",1);
                set("material", "iron");
        }
        ::init_blade(25);
}

