#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(GRN"��ɫ��ɴ"+RED"����ȹ"NOR, ({ "qingsha" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", "һ�����ò����ٱ���͸�ò�����͸�Ĵ�ɫ��ɴ����ȹ��\n");
		set("material", "cloth");
		set("value", 5);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
