#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���г���", ({ "blue cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ����˿��֯�ɵ���ɫ���ۣ�һ��������Ǯ�˴��ġ�");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value",10);
	}
	::init_cloth();
}
