#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"��ɽ�羰ͼ"NOR, ({ "hstu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�Ż�ɽ�羰�ļ��ͼ\n");
          }
	::init_item();
}
