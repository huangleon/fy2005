inherit NPC;
#include <ansi.h>
#include <command.h>

void create()
{
    	set_name("����",({"zhenzhu"}));
    	set("title",YEL"����¥"NOR);
    	set("long","
���鼡��΢�ᣬ������ģ����Ǵ��˼ҳ����ҵ��������䵽�糾�У���
������Щʫ����ר�Ÿ�������������ӽӴ������еķ�ɧ֮ʿ��\n");
    	set("gender","Ů��");
    	set("age",22);
    	set("no_arrest",1);
    	
    	set("combat_exp",600000);  
    	set("attitude", "friendly");
    
   	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	]) ); 
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		"������������Ȱ��Īϧ�����£�Ȱ��ϧȡ����ʱ��������\n",	
    	}) );
    	setup();    
	carry_object(__DIR__"obj/ladycloth1")->wear();
}

 void init()	{
	::init();
	add_action("do_love","answer");
	add_action("do_enjoy","enjoy");
}

  
int do_love(string arg)
{
	object me;
	object ob;
	ob=this_object();
	me=this_player();
	if(arg == "�л�����ֱ���ۣ�Ī���޻�����֦��"
		|| arg == "�л�����ֱ���ۣ�Ī���޻�����֦"
		|| arg == "�л�����ֱ���ۣ�Ī���޻�����֦��"
		|| arg == "�л�����ֱ���ۣ�Ī���޻�����֦��"
		|| arg == "�л�����ֱ���ۣ�Ī���޻�����֦"
		|| arg == "�л�����ֱ���ۣ�Ī���޻�����֦��"	) {
                if (me->query("gender")=="����")
                	message_vision(MAG "\n$N��$n̾������������֪���Ȥ֮ʿ��СŮ�Ӻ޲�����������\n"NOR, ob,me);
                else 
                	message_vision(MAG "\n$N��$n������λ��������������ˣ�СŮ����������Ҫ���˽�㡣\n"NOR, ob,me);
                me->set_temp("mark/enjoy",1);
                return 1;
        }
    
    command("shake");    
	command("say ");
	return 1;
}        

int do_enjoy()
{
	object me;
	object wo;
	object *inv;
	int maxgin,maxkee, maxsen;
	int i;
	me = this_player();
	if(!me->query_temp("mark/enjoy")){
	        command("say ��Ӵ��������λ" + RANK_D->query_respect(me)+"��ū�ҿɲ�����������ϴ����ˣ�");
		return 1;
	}
	if (query_temp("enjoy_time")+60>time()){
		message_vision(CYN"���齿��������˵��������ū�ң���ū��Ъ��Ƭ�̰ɡ���\n"NOR,this_object());
		return 1;
	}
	message_vision("$N��ƮƮ����$n�߹���������ĸ�Ū$n�ĺڷ���������\n",this_object(),me);
	me->unconcious();
	set_temp("enjoy_time",time());
    
    me->full_me();	
	wo = new(__DIR__"obj/grass");
	wo->move(me);
	return 1;
}
	