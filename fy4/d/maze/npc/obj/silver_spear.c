#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("���", ({ "spear" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "
����������������������ꪣ���ǹ��ǹ��Ⱦ���������ȵ���Ѫ����ֵ��ǣ�
��Ѫ����һ���������ɫ��ҡҷ��˸�������ûظ���������ϸ�鿴�鿴�ɡ�\n");
		set("value", 1);
		set("lu_spear",1);
		set("material", "steel");
		set("nodrop_weapon",1);
		set("wield_msg", "$N��ৡ���һ����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������¡�\n");
	}
	::init_spear(10);
}
