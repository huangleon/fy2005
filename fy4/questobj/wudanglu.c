#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLU"�䵱¼"NOR, ({ "wudanglu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "�����䵱¼��\n");
          }

    ::init_item();
}
