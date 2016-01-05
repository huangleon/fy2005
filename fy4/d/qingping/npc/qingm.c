//XXDER/TIE
inherit SMART_NPC;
inherit F_MASTER;
void create()
{
    set_name("��������", ({ "shu sheng"}) );
    set("gender", "����" );
    set("age", 39);
    set("int", 30);
    set("long",
        "һ��Ӣ��ͦ�ε������ˣ�����ȥ����ζ�����أ��������űʣ����ڶ���һ"
        "���������˼��\n");
	set("reward_npc", 1);
	set("difficulty", 2);
	set("combat_exp", 2000000);
	set("class","shenshui");
	
		set_skill("dodge", 150);
        set_skill("sword", 160);
        set_skill("parry",150);
        set_skill("qingpingsword", 170);
        set_skill("force", 160);
        set_skill("qingpingforce", 150);
        set_skill("chaos-steps", 150);
        set_skill("unarmed",150);
        set_skill("bai-quan",220);
        
        map_skill("unarmed","bai-quan");
        map_skill("parry","qingpingsword");
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");

		set("perform_busy_w", "shenshui/sword/qingpingsword/fengzijue");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
    
	    create_family("��ƽɽׯ", 2, "����");
	    set("rank_nogen",1);
	    set("ranks",({"��ͯ","����","��ʿ","����","����","����"}));
	    set("rank_levels",({64000,256000,1536000,3456000,26244000})); 
	    
	    setup();
	    carry_object(__DIR__"obj/pcloth")->wear();
	    carry_object(__DIR__"obj/shoe")->wear();
	    carry_object(__DIR__"obj/pen")->wield();
}

void attempt_apprentice(object me)
{
	command("shake");
	command("say ��ͽ���£�ֻ�а���ׯ������������\n");
}


