inherit SMART_NPC;

void create()
{
        set_name("�ض�����", ({ "guandong haoke", "haoke" }) );
        set("gender", "����" );
        set("age", 32+ random(10));
        set("long", "����һλ�Ӱ�ɽ��ˮ���Ĵ󺺣����´���һȺ�������ˡ�\n");
        set("combat_exp", 3200000);
        set("class","knight");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ض����ͺ�ˬ�������Ц��\n",
        }) );
        	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","zhangjian",1);
		setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/xuechang");
}