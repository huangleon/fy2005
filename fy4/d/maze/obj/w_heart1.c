#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"����"NOR, ({ "iron"}) );
        set_weight(500); 
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��ڲӲӵĽ����������Ʊ����ĸ������ϡ�\n");
                set("value", 2000);
                set("w-material",60);
        }
	::init_item();
}

