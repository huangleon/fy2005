#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( HIY"�ֽ�"NOR, ({ "palmsword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����Ϊ��.��������.�������߳�֮��.\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N������Ȼ�������Ȼ��"+HIY"��"+HIW"ʯ"NOR+"�Ĺ�â��\n");
		set("unwield_msg", "$N���ϵĹ�â������ȥ��\n");
	}
	::init_sword(100);
}
