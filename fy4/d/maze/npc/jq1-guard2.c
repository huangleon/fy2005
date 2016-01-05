#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("����������", ({ "sentry"}) );
        set("gender", "����" );
        set("title","��Ǯ�� ��������");
        set("age", 32);
        set("maze","jq1");
        set("target_name","������");
	set("class","assassin");
        set("long", "
�����������ɾ���������ѵ���Ļ������ӣ���Ȼ������������������֮�����е�
��ν������ʿ������ѷɫ����ÿ�����ǲ�η��������ʿ����һ��ʮ������ͬ��
�ھ���\n");
        
        set("combat_exp", 700000);
        set("attitude", "aggressive");
        set("pursuer",1);
            
		set("chat_chance", 1);
        set("chat_msg", ({
                "�����������������˽�������ߣ�����\n",
        }) );
		
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
		auto_npc_setup("liaoyin",100,120,1,"/obj/weapon/","fighter_w","sharen-sword",1);
		delete_skill("iron-cloth");
		setup();
        carry_object("/d/fy/npc/obj/tangfu")->wear();
}

int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}