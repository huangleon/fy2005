#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("��ɫ��˿�ʳ�ȹ", ({ "black skirt","skirt"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "gold");
		set("long", "һ����ɫ��˿�ʳ�ȹ��\n");
		set("value", 8000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
