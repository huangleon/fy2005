inherit SMART_NPC;
void create()
{
        set_name("Ԭ��ϼ", ({ "yuan zixia", "yuan"}) );
        set("gender", "Ů��" );
        set("age",22);
        set("per",50);
        set("long", "���˵��۾�����ɬ��Ц�ݣ��������ϲ�ʩ֬�ۣ�һ������ȴ������ϼ��\n");
        set("combat_exp", 1600000);
        
		set_skill("move",250);
		set_skill("unarmed",100);
		set_skill("force",60);
		set_skill("dodge",250);
		set_skill("liuquan-steps",100);
		set_skill("yunwu-strike",100);
		set_skill("parry",100);
		
		map_skill("unarmed","yunwu-strike");
		map_skill("dodge","liuquan-steps");
		map_skill("move", "liuquan-steps");
	
		set("perform_busy_u", "huangshan/unarmed/yunwu-strike/miwu");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
        	
        set("chat_chance", 1);
        set("chat_msg", ({
		"Ԭ��ϼ��Ŀ��ת�����𵶣��ֶ��˶�ŷ��µ�����\n",
        	"Ԭ��ϼ��Ŀһת�����������ߵ���ϼ���૵������񾩰����ҡ����ҡ���\n�Ҷ�����ô������Ӧ�������\n",
        }) );
        set("inquiry",([
        	"����"  :"���������������������ѵ�������������ͷô��\n",
        	"bai"  :"���������������������ѵ�������������ͷô��\n",
        	"bai yujing"  :"���������������������ѵ�������������ͷô��\n",
                ]) );
        
		setup();
    	carry_object("/d/chenxiang/npc/obj/purpleskirt")->wear();
}

