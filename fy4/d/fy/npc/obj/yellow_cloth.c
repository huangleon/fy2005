// pink_cloth.c

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIY"ǳ��С��"NOR, ({ "yellow cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���ǳ��ɫ��С������������ֻ��ȵ������������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}

