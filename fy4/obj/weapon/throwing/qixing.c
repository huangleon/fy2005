#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create() {
	set_name(BLU"������"NOR, ({ "dart" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"���㴨�İ�������˵�к���ҩ�ɾȡ�\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 40);
		set("base_value", 1);
		set("volumn",80);
	}
	set_amount(80);
	::init_throwing(85);
}
