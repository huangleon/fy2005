// laoni.c
#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("��������" , ({ "laoni" }) );
	set("long", "
һ���������ϵ������ᣬ��ü��Ŀ����ϥ������ǰ�������ϣ���Ȼ�����ţ�
�̿ɿ�����ĺܸߴ������۾�����ȫ�ǻ�ɫ�ģ����ݷ���ˮ�еĺ�������
������������һ����ˮ��������ִ��ų������������");
	
	set("attitude", "friendly");
	set("class","shenshui");
   	set("age", 65);
        set("gender", "Ů��" );
	set("combat_exp", 6600000);
	set("per", 2);
	
	set_temp("apply/parry", 100);
	set_temp("nine-moon-force_poison", 340);
    	set_temp("damage_shield/type","kee");
	set_temp("damage_shield/amount",250);
	set_temp("damage_shield/msg",MAG"$n�ƺ�մ����$N��Χ�Ķ����ֽſ�ʼ�����������\n"NOR);
    	
    	set("reward_npc", 1);
	set("difficulty", 25);	
		
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
	
	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","nine-moon-claw",1);
	setup();
	carry_object(__DIR__"obj/cyan_cloth")->wear();
}
