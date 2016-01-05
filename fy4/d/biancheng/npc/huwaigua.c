#include <ansi.h>
inherit SMART_NPC;
inherit "/d/taiping/npc/timeshift";
inherit INQUIRY_MSG;

int show_me();
void time_greet(object ob);

void create()
{
    	set_name("�����",({"hu waigua","hu","waigua"}));
	set("title","��Ʀ");
   	set("long","
�����ԭ�����ϣ����������ϵ�һ��С��Ʀ���������������Դ��������ߣ�
�������Ǳ����͵͵�ؽ�������ϡ�\n");

     	set("gender","����");
    	
    	set("combat_exp",5000000);  
    	set("age",42);
    	 	
    	set("reward_npc",1);
    	set("difficulty",2);
    	 	
    	set("inquiry", ([
        		"������" : 	(: show_me :),
             	"protection" : 	(: show_me :),
             	"����ʵ":	"����ʵ�Ɀ�ϣ�һ���ӷ����˲ƣ�\n",
             	"������":	"�ǰ���������ʵ�Ɀ�ϣ�һ���ӷ����˲ƣ�\n",
   		]));
    	    	
		set("day_room",AREA_BIANCHENG"smallroad2");
		set("dinner_room",AREA_BIANCHENG"mianguan");
		set("shift/dinner_leave","$N���˸����������ɻ�ȥ�ˡ���˵�����뿪��\n");
		set("shift/dinner_arrive","$N����˹������˹�����\n");
		set("shift/after_dinner","$N�ٺ���Ц��������������ȥ��\n");
		set("shift/back_dinner","$N���ű������˹�����\n");
				
    	set("death_msg",CYN"\n$N˵����Ӣ�ۡ�������������\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		10: name()+"�е���������һȭ�����ɸ���ϣ���\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"����ϵ�������ص��������ˣ���Ҫ�ᶯ���ӣ����ɻ�ɡ���\n",
    	}) );    	    	
    	
    	
		auto_npc_setup("wang",180,200,0,"/obj/weapon/","fighter_w","birdiestrike",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "��ɫ�����",
    						"long": "һ����ɫ�������\n",
    						 ]))->wear();     
    
}

int show_me() {
		if (!this_player()->query_temp("marks/wanma/can_fight")) {
	        	command("say �����ѣ������⣬��������ô������е���ô�����������أ�");
	        	return 1;
	        }
	
		command("say ��ô����Ҳ�뽻Ǯ�����ǿ���˳�ۣ�");
		command("say ����˳�ۿ��ԣ����ʹ����ӵ�ȭͷ��Ҫ��Ҫ���Ȼ��Ȼ���");
		return 1;
}

int accept_fight(object me){
        if (!me->query_temp("marks/wanma/can_fight")) {
        	command("say �����������й���");
        	return 0;
        }
        if (!SMART_D->check_health(this_object(),99) || this_object()->is_fighting()) {
        	command("say ��ȺŹ�����������ȴ�������");
        	return 0;
        }   
        full_me();
        message_vision("����ϴ������˿����������쿩����Ц�ˡ�\n",this_object());
        command("say �ã���Ӯ���ң����ͷ��������ˣ�\n");
        return 1;
}


void win_enemy(object loser){
    	command("pk "+loser->get_id());
}

void lose_enemy(object winner){
    	if (!this_player()->query_temp("marks/wanma/can_fight"))
    		return;
    	command("say Ӣ�ۣ������Ұɣ���С����Ҳ�����ˡ�\n");
    	command("say �������Ѿ�������ʵǮ��������ߵ��������ˣ�ʵ���²������ˡ�");
    	winner->set_temp("marks/wanma/ʤ��Ʀ",1);
}

void init() {
	
	object me;
	::init();
	if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("shifting");
		call_out("shifting", 1, me);
	}
}


void time_greet(object ob) {
	object *inv;
	int i;
	inv=all_inventory(environment(ob));
	if (sizeof(inv)<=1) return;
	
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]->query("id")=="zhang laoshi") {
			message_vision(YEL"$N��$n˵��������ı�����׼������ô����\n"NOR,ob,inv[i]);
			message_vision(YEL"$n̾����������$N������Ʊ��\n"NOR,ob,inv[i]);
		}
		if (userp(inv[i]))
			inv[i]->set_temp("marks/wanma/can_fight",1);
	}
	
}
