#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLK"̫��������"NOR, ({ "wuxingpai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "�䵱����ɽ֮����̫��������\n");
          }

    ::init_item();
}
