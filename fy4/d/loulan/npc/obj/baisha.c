#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIW"��ɴ"NOR, ({ "baisha" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", "һ�����˵İ�ɴ��װ���ƺ�ʲôҲ�ڲ�ס��\n");
		set("material", "cloth");
		set("value", 2);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
