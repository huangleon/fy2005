#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("����", ({ "seed" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cotton");
            set("long", "һ���Ϻõ����ѡ�\n");
          }

    ::init_item();
}
