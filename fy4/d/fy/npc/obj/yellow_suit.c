#include <armor.h>
#include <ansi.h>
inherit CLOTH;


void create()
{
	set_name(YEL"��ɫ�ĳ���"NOR, ({ "yellow suit", "suit" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ɫ�Ĳ��������ǳ������档\n");
		set("unit", "��");
		set("value", 2000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}

