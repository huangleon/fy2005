// tea_leaf.c

#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("�ϻ����", ({ "purple flower", "flower" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"���˵���ɫ���������һ�ɵ�����������\n");
		set("unit", "��");
		set("base_unit", "Ƭ");
		set("base_weight", 1);
		set("base_value", 1);
		set("volumn",7);
	}
	set_amount(7);
	::init_throwing(20);
}
