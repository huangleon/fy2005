#include <ansi.h>
inherit NPC;
inherit INQUIRY_MSG;
int check_other(object me);

void create()
{
    	set_name("С��",({"xiao die","xiaodie"}));
   	set("long","
С�������÷·����Ժ�ˮ����������������۾���Ȼ�ڱ����п���������ô
���������������ȴ������ˮ���������ʺ�Ķ�������ˮ��Ʈ������ڵ�ͷ
���ڷ��з��裬�������۾��У�������˵������������ͬ�顣\n");
     	
     	set("gender","Ů��");
     	     	
    	set("age",20); 	 	
    	set("int",52);
    	set("per",100);
    	set("cps",20);
    	set("str",10);
    	
    	set("combat_exp",10000);  
    	set("attitude", "friendly");
    	
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
     
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"С�������ʵ�����ֻ���㣬����û�У���\n",
		"С���������һ���������û�л������ô��������\n",
		
    	}) );    	    	
    	
		setup();
    	carry_object(__DIR__"obj/redcloak")->wear();
    
}


void init()
{	
	object me;
	::init();
	if( interactive(me = this_player()) && !is_fighting() ) {
		if ( REWARD_D->riddle_check(me,"��԰����")!=14
			&& !REWARD_D->check_m_success(me,"��԰����"))
			return;
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}

}

void greeting(object me)
{
	object ob;
	ob=this_object();
	if( !me || environment(me) != environment() ) return;
	
	if ( REWARD_D->check_m_success(me,"��԰����")==1) {
		message_vision("С����$N�����һЦ������$N���\n",me);
		return;
	}
	
	if ( REWARD_D->riddle_check(me,"��԰����")==14) {
		message_vision("С��ҧ���촽������������$N����$N�������֣�ת����������ȥ��\n",me);
		tell_object(me,"͸������������Լ������Զ����һ��С��¥��\n");
		destruct(this_object());
		return;
	}
	
	if ( REWARD_D->check_m_success(me,"��԰����")==2) {
		message_vision("С�����ĵ�˵�����㣬�ѵ����ɱ���ҵ������ѵ���Ͳ�Ҫ���ǵ�δ����ô����\n",me);
		return;
	}	
	
}
