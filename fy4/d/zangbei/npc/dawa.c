inherit SMART_NPC;
inherit F_VENDOR;
#include <ansi.h>

int bite();

void create()
{
	set_name("����", ({ "dawa" }) );
	set("title","�����Ĺ���");
	set("gender", "Ů��" );
	set("cor",20);
	set("age", 22);
	set("long","
�����ĺ�ɫ���������ɫ�������ֱۻ�Բ����ɫ��ͭ������ͭ�ζ�����
���شֱ�������ɳ�͹��ĺ��몲��۴�����ֱ׹�ű���\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("chat_chance",1);
    	set("chat_msg",({
		CYN"\n���޳���������ɫ����ïʢ��ʱ�����׵ĸ������֮ʱ��
     	     ��ţʢ�����̵�ʱ��������Ĺ������֮ʱ����\n\n"NOR,
     	     CYN"\n���޳�������ɽ��ϲ����ʯ������ϲ����ԭ������ϲ���賡��Ѱ������"HIR"����"NOR+CYN"����\n\n"NOR,
    	}) );  
	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		100:	(: bite() :),
        ]) );  
	
	set("inquiry", ([
 		"����":"���ʵ�����һ��?\n",
   	]));
   	
	set_skill("thunderwhip",100);
	set_skill("whip",100);
	set_skill("dodge",100);
	set_skill("zuixian-steps",150);
	set_skill("parry",100);
	set_skill("unarmed",100);
	set_skill("pofeng-strike",100);
	map_skill("unarmed","pofeng-strike");
	map_skill("whip","thunderwhip");
	map_skill("parry","thunderwhip");
	map_skill("dodge","zuixian-steps");
	
	set("vendor_goods", ([
		__DIR__"obj/ricecake" : 80,
		__DIR__"obj/drymeat" : 80,
		"/d/guanwai/npc/obj/wineskin":	80,
	]) );
	setup();
	carry_object(__DIR__"obj/dawacloth")->wear();
	carry_object(__DIR__"obj/whip")->wield();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision( CYN"���޳�������Զ�����Ŀ���ѽ���ȿ���������Ͳ�ɡ���\n"NOR,this_object());
}

int bite(){
	object dog,ob=this_object();
	object *enemy=ob->query_enemy();
	int i;
	
	if (!dog=present("wolfdog",environment(ob))) return 1;
	
	for (i=0;i<sizeof(enemy);i++){
		if (dog->is_fighting(enemy[i])) continue;
		message_vision(WHT"\n��������һ����������$N��ݺݵ�����������\n"NOR,enemy[i]);
		dog->kill_ob(enemy[i]);
	}
	return 1;
}


void reset(){
	set("vendor_goods", ([
		__DIR__"obj/ricecake" : 80,
		__DIR__"obj/drymeat" : 80,
		"/d/guanwai/npc/obj/wineskin":	80,
	]) );
}