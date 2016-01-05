#include <ansi.h>
inherit SMART_NPC;

int suicidal();

void create()
{
    	set_name("�����",({"old fishman","fishman"}));
    	set("title","Ը���Ϲ�");
    	set("long","�����ң������£�б��ϸ�겻��顣����䲻�ǽ��ϣ�ȴҲ�д��������̡�\n");
    	set("gender","����");
    	
    	set("age",72);
    	set("combat_exp",3200000);  
    	    	 	
		set("inquiry", ([
        	"������" :	"ʲô�����㣬û��˵����\n",
            "������" :	"�����㰡����������������꣬����û����һ����\n",
            "����":		"���Ƿ��Ƴ����Ǹ���򰡣�����Ҳ���������֣�ץ������һ�ϲ�ͨ�������Ļ�����ϵ��ˡ�\n",
			"*":		"���������������ҵ��������\n",
   		]));
    	   
    
    	set("death_msg",CYN"\n$N˵�����������������⡣������\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		50: (: suicidal() :),
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"����򳪵����������ң������£�б��ϸ�겻��顣����\n",
    	}) );  
    	
		auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","fumostaff",1);
	
		setup(); 
    	carry_object(__DIR__"obj/shuocloth")->wear();
        carry_object(__DIR__"obj/staff2")->wield();  
}


int suicidal() {
	object ob,*enemy;
	int i;
	ob=this_object();
	
	if (SMART_D->check_health(ob,50)) return 1;
	
	enemy=ob->query_enemy();
	for (i=0;i<sizeof(enemy);i++){
		if (enemy[i]->query("combat_exp")>4500000) {
			command("say �������������������ȥ���ҵ�������ѡ�");
			message_vision(WHT"ֻ����ͨһ����$N�����˺����Ҳû�и�����������\n"NOR,ob);
			destruct(ob);
			return 1;
		}
	}
	return 1;
}

