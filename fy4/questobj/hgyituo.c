#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"�������" NOR, ({ "hgyituo" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ�ź�����С�\n");
          }
    ::init_item();
}
