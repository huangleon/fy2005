#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("�����µ�����",({"bangpu lama","lama"}));
	set("long", "���ǰ����´�ɨ��Ժ��С���\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 1200000);
		
	
   	set("inquiry", ([
		"ת��":		"����ǧת���������ã�\n", 
		"����":		"������������ι���������ֻ���������\n",	
   		"���":		"������������ι���������ֻ���������\n",
   		"˾������": "��ﾫ��ͷ���Եģ��Ҿ�֪����û�����ġ�\n",
   	]));
	
	set("chat_chance", 1);
        set("chat_msg", ({
		"�����������������飬���²������ӵ������ʱ����Ǿͻ�Ծ��������\n",  
		
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("wang",120,160,0,"/obj/weapon/","fighter_u","yiyangzhi",1);
	
	setup();
	carry_object(__DIR__"obj/lamacloth")->wear();
	
}
