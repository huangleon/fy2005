#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(HIR"��ʯ"NOR, ({ "red stone", "stone" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",HIR"ʯͷ����Ѫ��ɫ�ģ���ÿ��¡�\n"NOR);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(30);
}
