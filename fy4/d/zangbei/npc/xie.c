#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void throw_away(object ob);

void create()
{

	set_name("лС��",({"xie xiaoyu","xie","xiaoyu"}));
    	set("title",HIG"��ɽׯ"NOR);
    	set("long", "
лС����˵�ӡ���������Ů�����ڰ�ɴ��Լ�б�¶�����е�Ů�Ե�������ֻ��
������һ�����С�һ����ʥ��ׯ�ϵ����У��·���ȫ������һ��ʥ��Ĺ⣬ʹ��
���ұ��ӡ�ʹ��Ը�����һ�У���Ϊ��ǰ��������\n");

	set("gender","Ů��");
	set("age",20);
	set("combat_exp", 7500000);
	set("class","swordsman");        	
	set("attitude","friendly");
	set("reward_npc",10);
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) ); 		
		set("smartnpc_busy",1);
	
	auto_npc_setup("wang",300,180,0,"/obj/weapon/","fighter_w","softsword",1);
		
	setup();
	carry_object("obj/armor/cloth")->wear();
	carry_object("obj/weapon/sword",([	"name": "���Ǿ�����",
    						"long": "һ�����߳�������������Ƕ���߿���״�İ�����\n",
    						"value": 2,
    						"damage": 70,
    						"level_required": 100,
    						 ]))->wield();    

}


void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player())) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	object *inv;
	string my_position;
	if( !ob || environment(ob) != environment()) return;
	command("say ����ô�ᴳ���������ģ����ȥ�������û�����ˡ�");
	call_out("throw_away",10,ob);
}

void throw_away(object ob) {
	if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
	this_object()->kill_ob(ob);
	ob->kill_ob(this_object());
}	