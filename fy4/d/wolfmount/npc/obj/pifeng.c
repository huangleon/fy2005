#include <armor.h>

inherit SURCOAT;

void create()
{
    set_name("��Ƥ����", ({"wolf pifeng", "pifeng"}));
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "һ����Ұ��Ƥ���ƶ��ɵ����硣\n");
		set("material", "leather");
		set("unit", "��");
		set("value", 700);
		set("armor_prop/armor", 10);
	}
	::init_surcoat();
}
