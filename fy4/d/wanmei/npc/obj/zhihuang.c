#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"ָ����"NOR, ({ "zhihuan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ��С�ɵ�ָ����\n");
          }

    ::init_item();
}
