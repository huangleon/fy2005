// pink_cloth.c

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIG"ǳ��С��"NOR, ({ "green cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���ǳ��ɫ��С������������ֻ��ȵ������������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	::init_cloth();
}

