// CYNGIRL.C
inherit NPC;
void create()
{       
        object armor;
        set_name("��Ů", ({ "maid" }) );
        set("long", "������������Ų��£��պ�����ѡ��������Ů\n");
        set("age", 16);
        set("per",20);
        set("gender", "Ů��");
        set("attitude", "friendly");
        set("combat_exp", 2700000);  
	
        set_skill("ill-quan",180);
        set_skill("unarmed",180);
        set_skill("force",150);
        set_skill("jiayiforce",150);
        set_skill("dodge",180);
        set_skill("parry",180);
        set_skill("tie-steps",180);
		set_skill("sword",180);
		set_skill("fy-sword",180);
	      
        map_skill("force","jiayiforce");
        map_skill("dodge","tie-steps");
        map_skill("unarmed","ill-quan");                         
        map_skill("sword","fy-sword");
        map_skill("parry","fy-sword");
        map_skill("move","tie-steps");
        
        set("no_busy",10);
        
        create_family("������", 2, "����");
        setup();
        
        armor=new(__DIR__"obj/corclot");
	armor->set_name("����",({"cloth"}) );
	armor->move(this_object());
	armor->wear();
        carry_object("/obj/weapon/sword")->wield();

}
