#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( "ӥצ���Ź�", ({ "mengui" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ����ϸ��ӥצ���Ź档\n");
          }
	::init_item();
}


