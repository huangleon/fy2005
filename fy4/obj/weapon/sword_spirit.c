// ��豹��棬�䵱����֮���¡�

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
#define TYPE_PERFORM	3

void create() {
	set_name("����", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ѻ���ͨ�ĳ������ƺ�һ��Ҳ�����ۡ�\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("unwield_msg", "$N���е�$nһ�����š�\n");
		set("wield_msg", "$N������һ������סһ�ѳ�����\n");
	}
	::init_sword(130);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object spirit;
	string msg;
	if (random(4))
	{
		msg =  HIC "$N����"+name()+ HIC "��Ȼ��â�������������ǣ��ӽ�������$n��\n"NOR;
		
	}
    	return 0;
}
