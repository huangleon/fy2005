
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
	set_name("���꺺��", ({ "hou", "hou er"}) );
	set("gender", "����" );
	set("age", 50);
	set("int", 25);
	set("per", 23);
	set("long","һ���������������꺺�ӡ�\n");
	
	 set("inquiry", ([
                "�������": 
"������������׿�ڣ����л���䣬������ʣ����ҿ��ֺ��䵱������������˵��ıֻ���������ˣ������˻��ﲻ������\n",
        ]) );
	        
	set("toughness",300);
	set("combat_exp", 20000000);
	
	set_skill("unarmed", 300);
	set_skill("sword", 300);
	set_skill("force", 300);
	set_skill("move", 400);
	set_skill("dodge", 300);
	set_skill("qiuzhi-sword", 300);
	set_skill("xianjing", 250);
	set_skill("liuquan-steps", 300);
	set_skill("dragonstrike",300);

	set("resistance/kee",90);
	set("resistance/gin",90);
	set("resistance/sen",90);
	    
	map_skill("unarmed","dragonstrike");
	map_skill("sword", "qiuzhi-sword");
	map_skill("force", "xianjing");
	map_skill("dodge", "liuquan-steps");
	map_skill("move", "liuquan-steps");
	
	set("chat_chance", 1);
	set("chat_msg", ({
	
	}) );
	setup();
	carry_object("/obj/armor/cloth", 
	    		([ 	"name" : "����",
	    			"long" : "һ����ɫ���ۡ�\n"]) 
	    		)->wear();
	carry_object("/obj/weapon/sword")->wield(); 
}

void init(){
	object ob;
	
    	::init();
    	if( interactive(ob = this_player()) && !is_fighting() ) {
        	remove_call_out("greeting");
            	call_out("greeting", 2, ob);
    }
}

void greeting(object ob){
	message_vision("$N������$nһ�£�����˿��û���κα��顣\n", this_object(), ob);
	if(ob->query("marks/÷ɽ��")) {
	if(ob->query("m_killer/����") && ob->query("m_killer/��������")
		&& ob->query("m_killer/��������") && ob->query("marks/л����"))
		tell_object(ob, "����һ��΢С������˵������ȥ�鷿���ƿ�����ש�������衡������壩���£������ѧ
���޵еĹ���\n");		
	}
}	

