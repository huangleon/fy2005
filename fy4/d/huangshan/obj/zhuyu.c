#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( "���ǹ�", ({ "zhu yu", "���ǹ�" }) );
    set_weight(10);
    if( clonep() )
            set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "���ɫ�Ĺ���Բ��ɰ���\n");
    	set("value", 1000);    
    }
	::init_item();
}
