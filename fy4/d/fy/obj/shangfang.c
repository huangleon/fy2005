#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
	set_name( "�з�����", ({ "royal sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѹ�ɫ����ı�����һ���Ͳ��Ƿ�Ʒ��������š��մͣ��������������֡�\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
		set("shangfang",1);
		set("thief_obj",1);
	}
    ::init_sword(15);
}
