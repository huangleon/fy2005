#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();

void create()
{
    	set_name("������",({"hua mantian","hua"}));
    	set("title","������");
    	set("long","
���������Ѿ�վ�˺ܾ��ˣ�ѩ�׵��·��ϻ���ɳ����ͷ��Ҳ�ѱ�Ⱦ�ƣ�
����������ȴ�ǲ԰׵ģ��԰׵�ȫ��һ˿Ѫɫ��\n");
     	set("gender","����");
    	set("age",42);
    	 	
    	set("combat_exp",8000000);  
    	set("attitude", "friendly");
    	
    	set("reward_npc",1);
    	set("difficulty",10);
    	
    	set("inquiry", ([
        		"������" : 	(: show_me :),
             	"���Ⱥ" :	 (: show_me :),
   		]));
    	
    	set("death_msg", CYN"\n$N˵������һ���Ҳ����İ��� \n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"�����컹վ����ҹͬ���ĵط������������ƶ�û�иı����\n"
    	}) );    	    	
    	
    	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","musician",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("obj/weapon/sword/sword_hua")->wield();    
}


int show_me(){
	object me,ob;
	int norm;
	
	me=this_player();
	ob=this_object();	
	
	if (me->get_id()=="yekai" || me->get_id()=="fu hongxue") {
		command("puke");
		command("say ����Ϊ����������ߴ������ģ�");
		return 1;
	}
	
	norm = (REWARD_D->check_m_success(me,"�����θ���")
			+ REWARD_D->check_m_success(me,"����Сϱ��")
			+ REWARD_D->check_m_success(me,"��������ʵ")
			+ REWARD_D->check_m_success(me,"��������")
			+ REWARD_D->check_m_success(me,"�����ƺ�")
			+ REWARD_D->check_m_success(me,"ɨ����ʬ"));
	// һ����6��;�������������������6�����ܽ��������á�
	if (norm < 5) {
		command("hmm");
		command("say �Һ���û��˵���㣬���ϰ�����ˣ�����������ͷ���������");
		command("say �㻹�����뷨�������������������Ұɡ�");
		tell_object(me,WHT"��������������Ҫ����������������ڱ߳ǵ�����Ϊ"+chinese_number(norm)+"�㡣\n"NOR);
		return 1;
	}
	
	REWARD_D->riddle_done( me, "����߳�", 100, 1);
		
	message_vision(CYN"$N��$nһ���֣����������´������������ֿڣ��������г���ӭ����\n"NOR,ob,me);
	return 1;
}