// XXDER@FY3
inherit SMART_NPC;

void create()
{
    	set_name("Ҷ��" , ({ "swords man","man" }) );
    	set("long", "һ������ƮƮ��Ӣ�������İ��Ƴǽ�ʿ����\n");
    	set("nickname","���ƴ����");
    	set("age", 19);
        set("gender", "����" );
        create_family("���Ƴ�", 2, "��ʿ");
		set("combat_exp", 280000);
        set("class","baiyun");
        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",100,70,0,"/obj/weapon/","fighter_w","feixian-sword",1);
		setup();
		carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
