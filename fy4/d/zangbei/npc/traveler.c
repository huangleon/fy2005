#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("��Į����",({"traveler","desert traveler"}));
	set("long", "
ɳĮ��������շ籩��Ҳ�д�ٵĴ�ͽ����������֮�˴���Ⱥ��ӣ�����
�����չˡ����Ǹ��ض��У��糾���͡�\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 1000000);
	set("group","traveler");
		
	set("chat_chance", 1);
        set("chat_msg", ({
                "����˵�������ɱ�������˲źá�\n"
                "����˵�����ǽ�Ӷ��У���ǿ���͸���ƴ����\n"
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(10) :),    
        }) );
	
	auto_npc_setup("guardian",100,100,1,"/obj/weapon/","fighter_w","cloudstaff",1);
		
	setup();
	set_skill("iron-cloth",150);
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/towel")->wear();
}


