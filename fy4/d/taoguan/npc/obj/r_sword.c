#include <weapon.h>
inherit SWORD;

void create()
{
    	set_name("��ľ��", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", "һ��������ĺ�ľ���ɵı�����\n");
        	set("value", 200);
		set("material", "wood");
		set("for_taoist",1);
	}
    	::init_sword(10);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");


}
