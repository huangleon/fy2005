// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(WHT"��Ӱ"NOR, ({ "chengying sword","sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "��ʱ������֮һ����Ϊ���⣬���������У�\n�ƻ�����֮ʱ���Խ�ָ������Ӱ�鼰���У�����΢��֮������նɱ�ߺ���ʹ����\n");
        set("value", 20);
		set("material", "steel");
	}
    ::init_sword(20);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");


}
