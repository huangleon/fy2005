#include <weapon.h>
inherit FORK;

void create()
{
   	set_name("ȱ�ݵĶ���", ({ "broken rake","rake" }) );
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
         	set("long", "һ���ųݶ��ң��ü������Ѿ���ȱ��ȫ��\n");
		set("value", 800);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N������γ�һ��$n�������С�\n");
        	set("unwield_msg", "$N�����е�$n���ڼ��ϡ�\n");
	}
    ::init_fork(10);
}
