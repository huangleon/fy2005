
#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name(RED"С��ɵ�"NOR, ({ "flying blade" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ���˼����µ�С��ɵ���\n");
		set("unit", "��");
		set("value", 1000);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
		set("wield_msg","$N��֪������ͻȻ��ק��һ�ѱ�����$n�������\n");
	}
	set_amount(1);
	::init_throwing(100);
}
