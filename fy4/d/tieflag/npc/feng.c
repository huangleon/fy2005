// feng.c

inherit NPC;

void create()
{
    	set_name("�����",({"feng jiuyou","feng"}));
    	set("long","�������ģ����������߻���ħ��һ��Ҳ���ܶ��ˡ�\n");
    	set("nickname","��������");
    	set("gender","����");
    	set("age",42);
    	set("no_arrest",1);
    
    	set("sen",0);    
    	
    	set("no_heal",1);
    	set("combat_exp",400000);  
    
    	set_skill("nine-moon-claw",100);
    	set_skill("force",100);
    	set_skill("demon-force",150);
    	set_skill("unarmed",100);
    	set_skill("parry",150);
    	set_skill("dodge",150);
    	
    	map_skill("force","demon-force");
    	map_skill("unarmed","nine-moon-claw");
    
    	set("force",10000);
    	set("max_force",10000);
    	set("force_factor",20);
    
    	set("attitude", "friendly");
    	setup();
    	carry_object("/obj/armor/cloth")->wear(); 

}


int accept_fight(object me)
{
		return notify_fail("������Ѿ�����ս���ˡ�\n");
}              
