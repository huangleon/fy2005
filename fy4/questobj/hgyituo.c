#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"บ่นยาลอะ" NOR, ({ "hgyituo" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ีล");
            set("material", "stone");
            set("long", "าปีลบ่นยาลอะกฃ\n");
          }
    ::init_item();
}
