#include <ansi.h>
inherit ITEM;

void create()
{
    	set_name("����Ʒ", ({ "ghost item", "item"}) );
    	set_weight(5);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("long","������һ�ɸ������Ѿ��޷�����ԭ���������ˡ�\n");
        	set("value", 0);
    	}
    	::init_item();
}
