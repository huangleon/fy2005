#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name(HIY"��"NOR, ({ "gold ball","ball" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ���ɻƽ����İ�����\n");
		set("unit", "��");
		set("value", 1000);
		set("base_unit", "��");
		set("base_weight", 50);
		set("wield_msg","$N��֪�������ͳ�һ��$n�������\n");
		set("volumn",5);
	}
	set_amount(5);
	::init_throwing(20);
}
