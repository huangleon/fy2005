// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(YEL"ͺ��ͷ��ɨ��"NOR, ({ "bald broom","broom" }) );
    set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "����һ���Ѿ��Ƶ���ɨ��ͷ�ϵ���֦ȫ��������ֻʣ��ͺͺ��һ��ɨ��ѣ�����\n�ֵ��������߻��������ɨ��ɨ�Ž��֣�ɨ��Ҳ�쳣�ɾ�������ûʲô�ҳ���\n");
        set("value", 20);
        set("no_get",1);
		set("material", "steel");
	}
    ::init_sword(35);

// These properties are optional, if you don't set them, it will use the
// default values.

    set("wield_msg", "$N���һ��$n�������С�\n");
    set("unwield_msg", "$N�����̵����е�$n�������\n");


}
