

#include <weapon.h>
inherit THROWING;

void create() {
	set_name("��Ϣ����", ({ "needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
//		set("long",	"������һ��ʮ�ֳ����İ�����\n");
		set("unit", "��");
		set("base_unit", "ö");
		set("base_weight", 40);
		set("base_value", 3000);
		set("weapon_prop/attack",30);
		set("level_required",50);
		set("volumn",120);
	}
	set_amount(120);
	::init_throwing(60);
}
