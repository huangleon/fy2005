inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
        set_name(HIG"��̳"NOR, ({"jiutan"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����ɾ�̯�����ƾ�ϸ����������װ��Ҳ�����ơ�\n");
                set("unit", "��");
                set("value", 100);
                set("max_liquid", 10);
        }

	set("liquid", ([
		"type": "alcohol",
		"name": "��Ҷ��",
		"remaining": 1500,
		"drunk_apply": 6,
	]) );
	::init_item();
}
