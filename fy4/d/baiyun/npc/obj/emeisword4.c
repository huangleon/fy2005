// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(WHT"��֮��"NOR, ({ "yun sword","sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "���Ƕ�ü���Ŷ���һ�������ĸ�Ů���ӵķ���������
ÿһ���Ͼ���Ŀ����������������Ͽ̵��ǡ��ơ���\n");
        set("value", 10);
		set("material", "steel");
	}
    ::init_sword(15);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");


}
