inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("�����", ({ "fire monster","monster"}) );
        set("long","һ���ߴ�ģ�ȫ��ͨ��ľ��ˡ�\n");
        set("age", 51);

        set("combat_exp", 2500000);
	
        set("attitude", "aggressive");
        set_skill("move",200);
		set("group","giant");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
                	
//	set_temp("damage_shield",1);
	set_temp("damage_shield/amount",300);
	set_temp("damage_shield/type","kee");
	set_temp("damage_shield/msg",HIR"��������������ޱȣ�$nֻ���������棬���û���˹�ȥ��\n"NOR);
	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","bat-blade",1);	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
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
			case 300: 	data["msg"] = WHT"��$N��"+weapon->name() + NOR WHT"�������ǣ���ס$n����\n"NOR;
					me->set_temp("damage_shield/amount",200);
					break;
			case 200: 
					data["msg"] = WHT"��$N��"+weapon->name() + NOR WHT"�³�һ�Ű���$n���ٱ��ߣ���\n"NOR;
					me->set_temp("damage_shield/amount",100);
					break;
			case 100:
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