#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( HIW"���ƽ�"NOR, ({ "sword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������ı�����\n");
		set("value", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N�ӱ������г��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ı����ʡ�\n");
	}
	::init_sword(24);
}

