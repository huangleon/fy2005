inherit SMART_NPC;
void create()
{
        set_name("һ��", ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("class","shaolin");
		set("nickname","��ɮ");
        set("long", "����������ר�����ŵ���ɮ��\n");
		set("vendetta_mark","shaolin");
        create_family("������", 19, "����");
        set("combat_exp", 1800000);
        set("attitude", "friendly");
        	
        set("chat_chance_combat", 100);
	    set("chat_msg_combat", ({
		     (: auto_smart_fight(20) :),
	     }) ); 		

		auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","tianlongwhip",1);
        setup();
		carry_object(__DIR__"obj/monk22_cloth")->wear();
		carry_object(__DIR__"obj/whip")->wield();
}

