#include <weapon.h>
inherit AXE;

void create() {
	set_name("�ٸ�", ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("long", "ľ���õ�һ��С���ӡ�\n");
		set("material", "iron");
		set("wield_msg", "$N�ӱ�����$n���������а��˸����ơ�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	::init_axe(20);
}
