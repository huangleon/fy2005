inherit SMART_NPC;
void create()
{
        set_name("����", ({ "huafei" }) );
        set("gender", "����" );
        set("long","
����������£������������԰׶��忡�������ϣ�����һ�ݹ°���
��֮ɫ���·�δ���κ��˿������\n");
        set("age", 18);
        set("per", 58);
        set("no_arrest",1);
         set("fly_target",1);
              
        create_family("������", 2, "����");            
                      
        set("combat_exp", 8100000);
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
		"��������Ķ�����һ�ۡ�\n",
        }) );
        
	    auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","pangu-hammer",1);
		setup();
		
		set_skill("liangyi-force",200);
		set("perform_busy_w","yinshi/hammer/pangu-hammer/rufengsibi");
		set("smartnpc_busy",1);
		
		carry_object(BOOKS"skill/qidaoforce_11")->wear();
		carry_object(__DIR__"obj/9ring")->wield();
}
