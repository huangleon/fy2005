#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("��Զ��", ({ "sun yuanchao", "sun" }) );
	set("gender", "����" );
	set("age", 28);
	set("class","shaolin");
	set("nickname", HIW"�������"NOR);
	set("long", "�����������˫Ŀ��Ȼ������ȥһ���˲ġ�\n");
	
	set("combat_exp", 1300000);
	
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
    	 (: auto_smart_fight(50) :),
    }) );
        
	auto_npc_setup("wang",170,160,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
	setup();
	carry_object("/obj/armor/cloth",
		([ "name": "����" ])
		)->wear();
	carry_object("/obj/weapon/blade")->wield();
}


void die(){
	object me;
	
	if(objectp(me=query_temp("last_damage_from") ))
	{ 
		if (objectp(me->query("possessed")))
			me = me->query("possessed");
		environment(this_object())->check_rescue(me);	
	}	
	::die();
}

