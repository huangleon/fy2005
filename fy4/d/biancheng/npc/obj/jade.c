#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"����"NOR, ({ "jade" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("parrot",1);
            set("no_drop",1);
            set("unit", "��");
            set("material", "jade");
            set("long", "��Ө��覵ı��񣬱���̫ƽ�������ϵģ���ֵ���ǡ�\n");
          }

    ::init_item();
}
