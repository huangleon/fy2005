#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("����ӵ�Сϱ��",({"pregnant woman","woman"}));
		set("long","һ������һ�������·���Сϱ����ͦ�Ÿ���������ں͵���Ļ���ּۻ��ۡ�\n");
     	
     	set("gender","Ů��");
    	set("attitude", "friendly");
    	    	
    	set("combat_exp",200000);  
    	set("age",22);
    	   	
		set("inquiry", ([
        	
   		]));

    	set("death_msg",CYN"\n$N˵�������ģ��ⲻ��һʬ����ô����\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		10: name()+"�е��������˰���ǿ��������\n",

        ]) );    	

    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"����һ�����������˵�������ɣ������ǿ飿��\n",
    	}) );    	    	
    	
		setup();
		set("cloth_code",4);
    	carry_object("/obj/armor/cloth",([	"name": "˿����",
    						"long": "һ��˿��С�£��������ɡ�\n",
    						 ]))->wear();    
}

void init()
{	
		object ob;
		
		::init();
		if( interactive(ob = this_player()) && !is_fighting() ) {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
		add_action("do_answer", "answer");
}

void greeting(object me)
{
	if( !me || environment(me) != environment() ) return;
	if (REWARD_D->check_m_success( me, "����Сϱ��")){
		command("xixi "+me->get_id());
		return;
	}
	
	if ( REWARD_D->riddle_check( me, "����Сϱ��")==1) {
		message_vision(CYN"$N��$n˵�����������������������Ⲽ��ô��\n"NOR,this_object(),me);
		return;
	}
	
	if (me->query("timer/wanma/answer_preg")+900 > time()) {
		message_vision("Сϱ��Ť��ͷȥ����$N�����ǡ�\n",me);
		return;
	}
	
	message_vision(CYN"$Nһ����ס$n����˵������λ"+RANK_D->query_respect(me)+"���ҳ�������ɡ���\n"NOR,this_object(),me);
	message_vision(CYN"$N˵������˵�����������أ��������ģ��������̵ģ��Ƶģ���\n",this_object());
	tell_object(me,YEL"��answer red/blue/green/yellow/dunno�� \n"NOR);
	me->set_temp("wanma/answer_preg",1);
}

int do_answer(string arg)
{
	object me,ob,huoji;
	
	me=this_player();
	ob=this_object();	
	
	if(!me->query_temp("wanma/answer_preg")) {
		command("say ����û���㣬��Ϲ����ʲô?");
		return 1;
	}
	
	if(	(arg=="red" && ob->query("cloth_code")==0)
		|| (arg=="blue" && ob->query("cloth_code")==1)
		|| (arg=="green" && ob->query("cloth_code")==2)
		|| (arg=="yellow" && ob->query("cloth_code")==3)	) {
		command("say ��ѽ���������ǲµ����Ŀ���ȥ�ˡ�");
		command("say �Ҿ�Ҫ����ˡ�");
		command("say ����,�ҽ�������˴����ӣ�����������ɣ�֪������ѽ��");
		me->delete_temp("wanma/answer_preg");
		REWARD_D->riddle_set(me,"����Сϱ��",1);
		return 1;	
	}
	if ( arg == "dunno" && (ob->query("cloth_code")==4 || !ob->query_temp("armor/cloth"))) {
		command("say ������Ҳ�ò������⣬��Щ�Ҷ���ϲ����");
		command("say ���»�������˵�ɡ�");
		me->delete_temp("wanma/answer_preg");
		return 1;	
	}
	
	if (arg=="yellow" || arg=="blue" || arg=="green" || arg =="red" || arg=="dunno") {
		message_vision(CYN"$N�����룬ҡ��ҡͷ˵�������ò��á���\n"NOR,this_object());
		message_vision(CYN"$Nת��ͷȥ������$n�ˡ�\n",this_object(),me);
		me->delete_temp("wanma/answer_preg");
		me->set("timer/wanma/answer_preg",time());
		huoji=present("huo ji",environment(this_object()));
		if (huoji) 
		{
			message_vision(CYN"\n$N������$n�ļ�ͷ˵������Ů�������������װɣ���\n"NOR,huoji,me);
			message_vision(CYN"\n$N�૵�˵��һ�����������ܻ���ʮ�꣮������ʮ������ǰװ��˷��˵ġ�
��ʮ���У��������������ڵ�Ů�˻��·���

$n�̲�ס�ʵ������������أ�
			
$N̾�˿���˵����һ��Ҫ�����Ҿ�˵�������������ڵ�Ů�����·���\n"NOR, huoji, me);
			
			return 1;
		}
	}
	tell_object(me,"��ֻ�ܻش� answer red/blue/green/yellow/dunno \n");
	return 1;
}

int accept_object(object who, object ob)
{
	if (REWARD_D->riddle_check(who, "����Сϱ��")!= 1) {	
//	if (!who->query("marks/wanma/��Сϱ��")) {
		command("say ���ǹ��ؾ��˼ҳ����ģ���ô�������ñ��˵�Ǯ�أ�");
		return 0;
	}
	if (ob->value()>=30000) {
		command("touch "+who->get_id());
		command("say ̫��л�ˣ�����Ҽ��ǿ��Ӵ󷽶��ˣ��Ҿ�����������ģ�");
		command("kiss "+who->get_id());
		
		if (!REWARD_D->check_m_success( who, "����Сϱ��"))
		{
			REWARD_D->riddle_done( who, "����Сϱ��",20, 1);
			who->set("marks/e_wanma/����Сϱ��",1);
			tell_object(who,HIW"���������ԶС������������ˣ�\n"NOR);
		}
		
		return 1;		
	} 
	command("say ���Ǯ������ѽ��");
	command("addoil "+who->get_id());
	return 0;
}			

			 

