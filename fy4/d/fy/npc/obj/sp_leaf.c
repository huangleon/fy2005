#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("С��Ҷ", ({ "leaf"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ƭ");
                set("long", "һƬСС��Ҷ��\n");
                set("value", 1100);
				set("annie_leaf",1);
        }
        ::init_item();
}
