// CYNGIRL.C
inherit NPC;
void create()
{       
        object armor;
        set_name("�˲��������Ů", ({ "girl" }) );
        set("long", "һ������������������µ���Ů��\n");
        set("age", 16);
        set("per",20);
        set("gender", "Ů��");
        set("attitude", "friendly");
        set("combat_exp", 2000000);  
	
        set_skill("ill-quan",120);
        set_skill("unarmed",150);
        set_skill("force",150);
        set_skill("jiayiforce",150);
        set_skill("dodge",160);
        set_skill("parry",160);
        set_skill("tie-steps",160);
		set_skill("sword",160);

        
        map_skill("force","jiayiforce");
        map_skill("dodge","tie-steps");
        map_skill("unarmed","ill-quan");                         
        map_skill("sword","fy-sword");
        map_skill("parry","fy-sword");
        map_skill("move","tie-steps");
        
        set("no_busy",3);
      
        create_family("������", 4, "����");
        setup();
        
        armor=new(__DIR__"obj/corclot");
	armor->set_name("��˿��",({"cloth"}) );
	armor->move(this_object());
	armor->wear();
        
}
