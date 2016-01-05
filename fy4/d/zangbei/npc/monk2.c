#include <ansi.h>
inherit SMART_NPC;

int loan();

void create()
{
	set_name("�����µ�����",({"tagong lama","lama"}));
	set("long", "�����µ���������ű��𸽽���������������ˣ���ü�������������ֳ���\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 3500000);
		
	set("inquiry", ([
 		"���":		(: loan() :),
 		"���Ǯ":	(: loan() :),
 		"��ʥ":		(: loan() :),
		"ת��":		"����ǧת���������ã�\n", 
		"˾������": "��ﾫ��ͷ���Եģ��Ҿ�֪����û�����ġ�\n",
   	]));
	
		set("chat_chance", 1);
        set("chat_msg", ({
		name()+"˵��ʩ������ʩ�����Ǯ�ɡ�\n",  
        }) );
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(50) :),    
        }) );

	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
	
	setup();
	carry_object(__DIR__"obj/lamacloth")->wear();
	carry_object(__DIR__"obj/nblade")->wield();
	
}


int loan(){
	object ob=this_object();
	
	message_vision(CYN"������̾�˿���˵�������������ʧ�ޣ���������ʥ������Խ��Խ���ˡ���\n"NOR,ob);
	message_vision(CYN"��������ϣ�����۹⿴��$N����ʩ����Ը��Щ��𣿡�\n\n"NOR,this_player());
	return 1;
}



int accept_object(object who, object ob){
	
	who->add_temp("marks/tagong",ob->query("value"));
	
	if (who->query_temp("marks/tagong")<5000) {
		message_vision(CYN"����������¶��һ˿ʧ�������ţ���лʩ������\n"NOR,this_object());
	} else if (who->query_temp("marks/tagong")<10000) {
		message_vision(CYN"������˫�ƺ�ʮ����ͷ��Ŀ�����ţ���лʩ������\n"NOR,this_object());
	} else {
		message_vision(CYN"������������Ȼ�ų�����������Ҳ��Щ������������һ���ᱣ��ʩ���ġ�
�������ȥ�������޷��������ܽ�����\n"NOR,this_object());
		tell_object(who,WHT"����������Ļ����ע�⵽��ԭ����������־þ����꣬�Ѿ�ʮ���ƾ��ˡ�\n"NOR);
		who->set_temp("zangbei/������ʩ��",1);
	}
	return 1;
} 