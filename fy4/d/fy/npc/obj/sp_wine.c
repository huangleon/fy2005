inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
        set_name(HIC"��ɽ��������"NOR, ({"wine"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һƿ˽������ƣ���֮������������֮�⡣\n");
                set("unit", "ƿ");
                 set("value", 10000);
                set("max_liquid", 100);
        }

	set("liquid", ([
		"type": "alcohol",
		"name": "ɽ������",
		"remaining": 100,
		"drunk_apply": 1,
	]) );
//	::init_item();
}
