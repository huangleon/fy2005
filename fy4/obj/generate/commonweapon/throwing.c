

#include <weapon.h>
inherit THROWING;

void create() {
	set_name("����", ({ "dart" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"������һ��ʮ�ֳ����İ�����\n");
		set("unit", "��");
		set("base_unit", "֦");
		set("base_weight", 40);
		set("base_value", 2);
		set("volumn",50);
	}
	set_amount(50);
	::init_throwing(10);
}
