#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"�޽��ķ�"NOR, ({ "wujianxinfa" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ���ƾɣ��ּ�ģ�����顣\n");
          }

    ::init_item();
}
