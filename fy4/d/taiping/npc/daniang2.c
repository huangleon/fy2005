#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

		set_name("�����",({"li daniang","daniang","li"}));
//    	set("title",WHT"�Ĵ�����"NOR);
    	set("long", "����Ц���紺�����ţ������紺ݺ��ת����ı����ҵ�Ů�˸���������òҲ������
Ѫū���Ǻ��������ˣ���δ��������ȡ��������������������ѷ������֡�\n");
		set("age",47);
		set("combat_exp", 8000000);
        set("attitude", "friendly");	
	
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(40) :),    
        }) );
	

	
		auto_npc_setup("xuebin",250,180,0,"/obj/weapon/","fighter_w","sharen-sword",2);
		setup();
		carry_object("/obj/armor/cloth")->wear();
}
