#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT"����"NOR, ({ "jade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�鴥���������ʯ�������һƥ��ͷ�Բݵ���\n");
		set("value", 300);
		set("material", "stone");
	}
	::init_item();
}
