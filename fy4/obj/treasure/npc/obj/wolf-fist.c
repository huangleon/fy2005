#include <weapon.h>
#include <ansi.h>

inherit FIST;
void create()
{
	set_name(HIB"����ץ"NOR, ({ "shred claw","claw" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���殐��צ�ӣ�צ�Ϸ�����������Є�����צ���b�е�����׌�����Ų�Փ
ץ��ʲ�N������׌���ķ����ѡ�\n");
		set("value", 50);
//	set("weapon_prop/spirituality",5);
		set("material", "steel");
		set("level_required",100);
	}
	init_fist(100);
	set("wield_msg", "$N˫��һ�������Ϸ������ĵ����⡣\n");
	set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");

}

int query_autoload() { return 1; }