// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create() {
	set_name(MAG"ڤ��"NOR, ({ "hell whip","whip" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���������ٱ�͵ĳ��ޣ�������ħ�̽�������ħ�����֮һ��\n");
		set("material", "bronze");
		set("no_get",1);
		set("no_sell",1);
		set("no_stack",1);
		set("no_drop",1);

		set("weapon_prop/attack",80);

		set("nodrop_weapon",1);
	}
	::init_whip(120);	
}
