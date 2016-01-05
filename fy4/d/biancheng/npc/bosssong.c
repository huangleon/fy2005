#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();
int kill_him();

void create()
{
    	set_name("�θ���",({"song fugui","fugui","song"}));
	set("title","�޻����ϰ�");
   	set("long","
�θ�����ֻ�Ǹ������ʮ�����걻�޻����ϰ�Ĺ�Ů������������Ů����
��ô�������������㣬�Ѹ��޻��е�����Խ��Խ�죬Խ��Խ��\n");
     	
     	set("gender","����");
    	set("attitude", "friendly");
    	set("group","citizen");
    	
    	set("combat_exp",1800000);  
    	set("age",42);
	 	   	
    	set("inquiry", ([
    	    	"ɽ��" : 	(: show_me :),
             	"bandit" :	(: show_me :),
             	"�����嶾":	(: kill_him :),
             	"��������":	(: kill_him :),
   		]));

    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		10: name()+"�е��������˰���ǿ����ٵ���������\n",

        ]) );    	
    
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
    
    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"��ü������˵����ɽ��һ���һ���Ᵽ��������ô��������ȥ�ǣ���\n",
		name()+"�����鳣����˵ص��˼����޻���\n",
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","xingyi-stick",1);
	
	setup();
   	carry_object("/obj/armor/cloth")->wear();    
	carry_object("/obj/weapon/staff",([	"name": "���",
    						"long": "һ��һͷ��һͷС�İ�鳡�\n",
    						"value": 0,
    						 ]))->wield();    
}

void init(){
	::init();
	add_action("do_answer","answer");
}


int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"�θ�������û�ջش��㡣\n");
 		return 1;
 		}
 	if(!me->query("marks/wanma/�ײ�֮��")) {
        	tell_object(me,"�θ���˵��û��˵����������а���ý���\n");
        	return 1;
        }
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó����������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ�������Ȼ��֪���ˣ��Ͳ��������ٻ��ų�ȥ��\n"NOR,this_object());
        another = new(__DIR__"huahua");
	another->move(environment(this_object()));
        destruct(ob);
	return 1;
}


int show_me()	{
	object me,ob;
	
	me=this_player();
	ob=this_object();
	
	if (REWARD_D->riddle_check(me,"�����θ���")) {
		command("say ����ɽ�������һ���ʲô��˵���أ�");
		return 1;
	}

	command("say ����ǰ����֪���Ķ�����һ��ǿ�ˣ�ÿ�����ʱ������ڴ�١�");
	command("say ���ϵ�����һ�첻��һ�죬ǿ����ȴԽ���䱾����������ǰ���Ҵ��ڵ����������Ѷ����ˡ�");
	command("sigh");
	command("say ���޻��п����ǿ�����ȥ�ˣ���λ"+RANK_D->query_respect(me)+"�ܲ��ܾ���һ����(answer)");
	me->set_temp("marks/wanma/answer_song",1);
	return 1;
}


int do_answer(string arg)
{
	object me,ob;
	
	me=this_player();
	ob=this_object();	
	
	if(!me->query_temp("marks/wanma/answer_song")) return 0;
	if(arg=="yes" || arg == "��") {
		message_vision(YEL"$NЦ��˵�����ϰ岻�ط��գ����°����ۼ����ϱ��ǡ�\n\n"NOR,me);
		command("say �ã��ã����ɽ��������ҹ���û�����⣬��˵���������졣");
		command("say ϣ�����ܽ�����һ�ٲ��������һ��ҵĻ��");
		me->delete_temp("marks/wanma/answer_song");
		REWARD_D->riddle_set(me, "�����θ���",1);
		return 1;	
	}
	if(arg=="no"|| arg == "����"){
		message_vision(CYN"$N�Ͻ�ҡ��ҡͷ˵�����������յ�΢���㻹����������ɡ���\n"NOR,me);
		message_vision(YEL"$N̾�˿���˵�����������ˣ����ˣ���\n"NOR,ob);
		me->delete_temp("marks/wanma/answer_song");
		return 1;
	}
	tell_object(me,"��ֻ�ܻش�������\n");
	return 1;
}


int accept_object(object who, object ob)
{
	if (ob->name()=="����") {
		if ( sizeof (who->query("marks/longhuzhai"))<3) {
			command("say лл�������һ��˻�������������ɱ���Ǽ���ɽ��ͷ�ӣ����ǿ϶���������ġ�");
			command("sigh");
			return 0;
		} else {
			who->delete("marks/longhuzhai");
			command("touch "+who->get_id());
			command("say ̫��л�ˣ��Ҿ���������Ӣ�۵Ĵ����µģ�");
			
			REWARD_D->riddle_done(who,"�����θ���",20,1);
			
			if (!who->query("marks/e_wanma/�����θ���")) {
				who->set("marks/e_wanma/�����θ���",1);
				tell_object(who,HIW"���������ԶС������������ˣ�\n"NOR);
			} 
			
			QUESTS_D->special_reward(who,"�����θ���");
			return 1;
		}	
	}
	return 0;
}			

			 

