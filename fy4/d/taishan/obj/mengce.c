#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�����˲�"NOR, ({ "meng ce", "ce"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("long",
"һ��˿�����ᣬ���׶˶�����д�š������˲᡿�ĸ��֡�\n"NOR);
        }
	::init_item();
}

