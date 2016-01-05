inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("�����", ({ "fire giant","giant"}) );
        set("long","һ���ߴ�ģ�ȫ��ͨ��ľ��ˡ�\n");
        set("age", 51);
        set("combat_exp", 1500000);
	set("group","giant");
        set("attitude", "aggressive");    	
//	set_temp("damage_shield",1);
	set_temp("damage_shield/amount",200);
	set_temp("damage_shield/type","kee");
	set_temp("damage_shield/msg",HIR"��������������ޱȣ�$nֻ���������棬���û���˹�ȥ��\n"NOR);
	
	set("NO_CORPSE",RED"�����ҽ�һ��������һ�ź��棬�����������ң����һ��ը��ǧ��������ʧ���١���\n\n\n"NOR);
	
	auto_npc_setup("wang",150,120,0,"/obj/weapon/","fighter_w","bat-blade",1);	
	setup();
    	carry_object(__DIR__"/obj/firespirit");    
    	carry_object(__DIR__"obj/fireblade")->wield();
}


mapping ob_hit(object ob, object me, int damage) {
	
	int amount;
	object weapon;
	mapping data =([]);
	
	if (damage <=0 || !me->query_temp("damage_shield"))	
		return 0;
	
	weapon = ob->query_temp("weapon");
	if (objectp(weapon) && weapon->query_temp("icy_dipped"))
	{
		
		amount = me->query_temp("damage_shield/amount");
		switch (amount)
		{
			case 200: 	data["msg"] = WHT"��$N��"+weapon->name() + NOR WHT"�������ǣ���ס$n����\n"NOR;
					me->set_temp("damage_shield/amount",100);
					break;
			case 100: 
					data["msg"] = WHT"��$N��"+weapon->name() + NOR WHT"�³�һ�Ű���$n���ٱ��ߣ���\n"NOR;
					me->set_temp("damage_shield/amount",50);
					break;
			case 50:
					data["msg"] = WHT"��$N��"+weapon->name() + NOR WHT"ը��ǧ��ѩ����$n���澡�𣡣�\n"NOR;	
					me->delete_temp("damage_shield");
					break;
			default:	return 0;
		}
		data["damage"] = 0;
		return data;
	}
	
	return 0;
		
}
