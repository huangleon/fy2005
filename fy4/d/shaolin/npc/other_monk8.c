// TIE@FY3

inherit SMART_NPC;
void create()
{
        //string *name = ({"ɽ����","�˹�����","����","ӡ��","��ɽ��","������","��ɽ","̩��"});
        set_name("̩��ĺ���", ({ "taimiao monk", "monk"}) );
        set("gender", "����");
        set("age", random(90)+10);
        set("long",
                "һ�������ֵ����º��С�\n");
		set("combat_exp", 3000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        		name()+"̾�������ֲ���Ϊ������ͥѽ����\n",
				name()+"�����ҿ�����Ҳ�������������ߣ�\n",
                name()+"����˵������λС�ܣ���������Σ�\n",
        }) );

        set("attitude", "friendly");
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		     (: auto_smart_fight(50) :),
     	}) ); 		

		auto_npc_setup("wang",180,180,0,"/obj/weapon/","fighter_w","dabei-strike",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();

}