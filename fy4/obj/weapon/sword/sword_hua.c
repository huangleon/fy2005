#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( "���޽�", ({ "qixiu sword","sword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�ݴ��ý��ȳ����ܻó��������֮�⣬�⵽֮����ɱ������ǿ��\n");
		set("value", 3000);
		set("timbre",40);
		set("level_required",100);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N�ӱ������г��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ı����ʡ�\n");
	}
	::init_sword(70);
}

