

#include <weapon.h>
inherit THROWING;

void create() {
	set_name("ͭ�㶹", ({ "bean" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
//		set("long",	"������һ��ʮ�ֳ����İ�����\n");
		set("unit", "��");
		set("base_unit", "ö");
		set("base_weight", 40);
		set("base_value", 200);
		set("weapon_prop/attack",15);
		set("level_required",20);
		set("volumn",50);
	}
	set_amount(50);
	::init_throwing(30);
}
