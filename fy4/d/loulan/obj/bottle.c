inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
        set_name(HIC"����ȸ������"NOR, ({"peacock"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�������ߴ����ƻ�ϵ����������ƣ���֮������������֮�⡣\n");
                set("unit", "ƿ");
                set("value", 0);
                set("max_liquid", 100);
        }

	set("liquid", ([
		"type": "alcohol",
		"name": "��ȸ����",
		"remaining": 100,
		"drunk_apply": 1,
	]) );
//	::init_item();
}