#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"�޺���"NOR, ({ "stone"}) );
        set_weight(500); 
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��СС�ķ��飬�ƺ�������Ƕ��ʲô�ϡ�\n");
                set("value", 2000);
                set("ring-imbue","green");
        }
	::init_item();
}

