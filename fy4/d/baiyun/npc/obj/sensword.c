#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIG"ҡ��"NOR, ({ "sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "��ѽ�͸��Թ⣬����տȻ��һ����֪���Ƿ��\n");
        set("value", 200);
		set("material", "steel");
		set("no_get",1);
		set("nodrop_weapon",1);
	}
    ::init_sword(90);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");

}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

