#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"����" NOR, ({ "kaoti" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�����ԵĿ��⣬���Ե���Ŀ������Ӣ����");
          }

    ::init_item();
}
