inherit NPC;
void create()
{       
        object armor;
        set_name("�ֽ���������Ů", ({ "sword girl" }) );
        set("long", "һ������������������µ���Ů��\n");
        set("age", 16);
        set("per",20);
        set("gender", "Ů��");
        set("attitude", "friendly");
        set("combat_exp", 1800000);  
	
        set_skill("ill-quan",150);
        set_skill("unarmed",150);
        set_skill("force",150);
        set_skill("jiayiforce",150);
        set_skill("dodge",150);
        set_skill("parry",130);
        set_skill("tie-steps",100);
		set_skill("sword",100);
		set_skill("fy-sword",120);
	        
        map_skill("force","jiayiforce");
        map_skill("dodge","tie-steps");
        map_skill("unarmed","ill-quan");                         
        map_skill("sword","fy-sword");
        map_skill("parry","fy-sword");
        map_skill("move","tie-steps");
        
        set("no_busy",4);
        
        create_family("������", 4, "����");
        setup();
        
        armor=new(__DIR__"obj/corclot");
	armor->set_name("����ȹ",({"cloth"}) );
	armor->move(this_object());
	armor->wear();
        carry_object("/obj/weapon/sword")->wield();

}
