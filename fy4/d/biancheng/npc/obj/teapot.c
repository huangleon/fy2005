#include <weapon.h>
inherit HAMMER;
inherit F_LIQUID;

void create() {
	set_name("����", ({ "teapot" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѳ��صĴ�����û�м����������಻�����ġ�\n");
		set("value", 100);
		set("material", "earth");
		set("max_liquid", 10);
		set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	set("liquid", ([
		"name": "��ˮ",
		"remaining": 10,
	]) );
	::init_hammer(10);
}
