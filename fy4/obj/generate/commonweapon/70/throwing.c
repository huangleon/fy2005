#include <ansi.h>


#include <weapon.h>
inherit THROWING;

void create() {
	set_name(HIG"�������"NOR, ({ "needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
//		set("long",	"������һ��ʮ�ֳ����İ�����\n");
		set("unit", "��");
		set("base_unit", "ö");
		set("base_weight", 40);
		set("base_value", 5000);
		set("weapon_prop/attack",35);
		set("level_required",70);
		set("volumn",120);
	}
	set_amount(120);
	::init_throwing(70);
}
