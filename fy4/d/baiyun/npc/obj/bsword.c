// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(CYN"ī�ӽ�"NOR, ({ "mozi sword","sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "��ѽ����ɲ��������ж�������ʽ���ӣ����Ǵ���ʱī�Ҿ��ӵ��彣����ֵ���ǡ�\n");
        set("value", 2000);
        set("no_get",1);
		set("material", "steel");
	}
    ::init_sword(60);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");


}
