// jiayi.c

inherit NPC;

void create()
{
    	set_name("��������",({"old woman","woman"}));
    	set("long","�����궨�������ɫ����������...\n");
    	set("gender","Ů��");
    	set("age",42);
    
    	set("no_arrest",1);
    	set("combat_exp",2000);  
    	
    	set("int",22);
    
    	set("gin",1000);
    	set("max_gin",1000);
    	set("eff_gin",1000);
    	set("max_sen",1000);
    	set("sen",1000);     
    	set("eff_sen",1000);
    	set("force",100000);
    	set("max_force",100000);
    	
    	set("attitude", "friendly");
		set("inquiry",	([
			"������":	"������ڣ������񹦣�����һ�����ճ�������\n",
			"����":	"���������������񹦣����������������޵С�\n",
		]));		
			
    	setup();
    
    	carry_object("/obj/armor/cloth")->wear();   
    	carry_object(__DIR__"obj/jiabook");  
}
