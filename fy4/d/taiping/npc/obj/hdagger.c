#include <weapon.h>
inherit DAGGER;

void create() {
	set_name("����ľС��", ({ "dagger" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ�Ļ���ľ��\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���뻳�С�\n");
	}
	::init_dagger(20);
}
