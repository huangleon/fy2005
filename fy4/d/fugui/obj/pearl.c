inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIG"ҹ������"NOR, ({ "pearl"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "һֻ�ں�ҹ��Ҳ�����������ҹ���飬�����������ü�Ǯ��\n");
		set("value", 500);
		set("armor_prop/armor", 0);
		set("thief_obj",1);
	}
	::init_item();
}
