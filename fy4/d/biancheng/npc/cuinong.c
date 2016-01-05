#include <ansi.h>
inherit SMART_NPC;

int fu();
int do_answer(string arg);

void create()
{
    	set_name("��Ũ",({"cuinong"}));
	   	set("long","
������Ҳ������̫������ȴ��˫��˵�����۾������ɵ��졣����Ȼֻ�Ǿ���
�����������ȴ��Ȼ���������˵ķ��˺����ʡ�һ��������Ů�ˣ����۶���
��������˵�����㹻��\n");
     	set("gender","Ů��");
    	set("age",22);
    	 	
    	set("per",4);
    	    	
    	set("inquiry", ([
        	"����ѩ" :		(: fu() :),
        	"fu hongxue" :	(: fu() :),	
        	"�ȴ�"	: 	"�ȡ����������ô��\n",
        	"��"	: 	"�ȡ����������ô��\n",
        	"��":		"action��Ũҧ���촽˵�����������Ǹ���ѩ��\n",
        	"��Զ�ĵط�":	"��Ҳ���Ǻ������ֻ֪�������½���ʲô�ط���\n",
    	         	
   		]));
    	
    	set("combat_exp",400000);  
    	set("attitude", "friendly");
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			"��Ũ���������Ŵ��⣬�ƺ��ڵȴ���ʲô�˵�������\n",
			"��Ũ����ͷ���������㡭���㼸ʱҪ�ҵȹ��㣿��\n", 
    	}) );    	    	
    		
		setup();
    	carry_object("/obj/armor/cloth",([	
    						"name":  HIR"���߰�"NOR,
    						"long": "һ�����˿����ް��������ĺܡ�\n",
    						 ]))->wear();    
    
}


void init(){
	::init();
	add_action("do_answer","answer");
}

int fu (){
	object me, ob;
	string msg, gender;
	int stage;
	
	me = this_player();
	ob = this_object();
	stage = REWARD_D->riddle_check(me,"�����ƺ�");
	
	if (!stage)
	{
		message_vision(CYN"��Ũ�۾�����������⣺�����ˣ�ȥ�˺�Զ�ĵط�������\n"NOR, me);
		gender = (me->query("gender")== "����")?"ү":"��";
		message_vision(CYN"��Ũҧ���촽˵����"+ gender +"���������ӵģ�����ô������ء�\n"NOR, me);
		command("say ����û���������Ķ��ܰ�������أ�");
		return 1;
	}
	
	if (stage == 1 || stage == 2) {
		message_vision(CYN"
һ������Ө��������ᣬ�Ӵ�Ũ�������۾���������������ӿ�ʼ������
������վ��վ��ס��

��ʱ����Ϊ�������ң��������ң�����Ϊ����������Ҫ�ҡ��������Ҳ�֪����
��������ϲ���ҵģ���ǰ�������������ӣ�ֻ������Ϊ�������Ĺ�Ƣ����
�ο�������Щ������������ʲô���ӣ���Ҳ֪����

��Ũ���������������Ҳ���ף�ֻҪ��������ϲ���ң���Ҳ����ϲ��������
������ȫ����Ҫ���㣬����ȥ��������"YEL"�������Ҷ����ˣ���Ҳ�������ȥ��\n"NOR,ob);
		me->set_temp("marks/fuhong_ask",1);		// put this here, in case player relogin after this.
		REWARD_D->riddle_set(me,"�����ƺ�",2);
		return 1;
	}
	if (stage == 3) {
		message_vision("��Ũ������˵��������˵ʲô��ô��\n",me);
		return 1;
	}
	return 0;
}


int do_answer(string arg){
	int stage;
	object me;
	
	me = this_player();
	stage = REWARD_D->riddle_check(me,"�����ƺ�");
	
	if(stage == 3)
	if ( arg == "����ȥ���������ǣ�"|| arg== "����ȥ����������") {
			message_vision(CYN"
��Ũ˵�������������ô˵���һ�����ģ�����Ҫ��ã������������
��Ũ��������һ���������������������Ҹ����ֵ����飬������������黹���\n"NOR,me);
					
			REWARD_D->riddle_done(me, "�����ƺ�",20, 1);	
			
			if (!me->query("marks/e_wanma/�����ƺ�")){
				me->set("marks/e_wanma/�����ƺ�",1);
				tell_object(me,HIW"���������ԶС������������ˣ�\n"NOR);
			}
			
			QUESTS_D->special_reward(me,"�����ƺ�");
			
			return 1;
	}
	return 0;
}
