#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIY"ɽ�ַ�"NOR, ({ "cloth" }) );
	set_weight(1000);
	set("long", "��ɫ�����������ð�˿�����Ÿ���ɽ���֡�\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("value", 1000);
	}
	::init_cloth();
}
