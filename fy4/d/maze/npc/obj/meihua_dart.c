#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create() {
	set_name(HIR"Ѫ÷��"NOR, ({ "blood blossom","blossom" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ���ɫ��÷����ÿƬ��������һ�κ�ɫ��Ѫ�գ������쳣����\n");
		set("unit", "��");
		set("base_unit", "ö");
		set("base_weight", 40);
		set("base_value", 0);
		set("volumn",200);
	}
	set_amount(500);
	::init_throwing(20);
}
