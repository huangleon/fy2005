
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(BLK"��������"NOR, ({ "flower"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long","һ������ĺ������㡣ɢ���ŵ����ķ��㡣��\n");
        set("value",4000);
	}
}



