//  An example non-weapon type of weapon
#include <ansi.h>
#include <weapon.h>
inherit RING;
void create()
{
	set_name(HIB"��ħ��"NOR, ({ "devil hand", "hand" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "һֻ����ɫ�����ף����������������һЩ���֡������׵����ӹ��죬\nҲʵ�������ж���ʲô���ʣ�͸��һ��������״��а����\n");
        	set("lore",1);
		set("value", 50);
		set("material", "steel");
	}
    	init_ring(18);
	
	set("real", 1);
	set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
	set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");
        set("skill", ([
                  "name": "devil-spells",           // name of the skill
                  "exp_required": 2500000,  // minimum combat experience required
                  "sen_cost":     10,      // jing cost every time study this
                  "difficulty":   20,     // the base int to learn this skill
                  "max_skill":    59     // the maximum level you can learn
        ]) );


}
