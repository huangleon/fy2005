#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name(RED"��"BLU"��"HIG"���"NOR, ({ "5flower arrow" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����糤�Ķ̼����ϱ�����һЩ��ֵĻ��ƣ�\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 10);
		set("wield_msg","$N��֪������ͻȻ��ק��һ��$n�������\n");
		set("volumn",15);
	}
    set_amount(15);
	::init_throwing(10);
}
