#include <weapon.h>
inherit SWORD;

void create() {
	set_name("�ؽ�", ({ "heavy sword","sword" }) );
	set_weight(400000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ�ĳ�����ֻ�Ƿ���������ࡣ\n");
		set("rigidity", 300000); 
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	::init_sword(35);
}
