#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("���׷�",({"hua baifeng","hua","baifeng"}));
	set("title",YEL"˫���缦צ���ϸ�"NOR);
   	set("long","
���������ź�ɴ����ɫ�ĳ������ư�ɢ���ڵ��ϣ�ֻ¶��һ˫�ɱ񡢲��ϡ�
��צ����֡���˫�ֺ�ʲ���૵��У���ȴ�����������ϲԴ���ร����
�������䡣�������ϲԣ����������ˣ���������ؼ���������\n");
     	
     	set("gender","Ů��");
     	     	
    	set("age",32); 	 	
    	set("int",52);
    	set("cor",30);
    	set("cps",20);
    	set("str",40);
    	set("per",1);
    	

    	set("combat_exp",1250000);  
    	set("attitude", "friendly");
    	
    	
//    	set("death_msg",CYN"\n$N˵�������߲��������߲��ư�����\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
//		"�������е���������������˱����Ͳ�ϲ����ܵġ���\n",
    	}) );    	    	
    	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","fy-sword",2);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
//    	carry_object(__DIR__"obj/gsword")->wield();    
    
}

void init()
{	
	object me;

	::init();
	if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}

}

void greeting(object me)
{
	object ob;
	ob=this_object();
	if( !me || environment(me) != environment() ) return;
	if (me->query("marks/wanma/Ѱ�ض�") && !me->query("marks/wanma/ɱ����_bai")) {
		call_out("event1",1,me,0);	
	}
	if (me->query("marks/wanma/ɱ����_bai")
		&& me->query_temp("marks/wanma/ɱ������_bai") && me->query_temp("marks/wanma/ɱ������_bai")
		&& me->query_temp("marks/wanma/ɱ�����_bai") && me->query_temp("marks/wanma/ɱ����_bai")
		&& me->query_temp("marks/wanma/ɱС����_bai") 
		&& !me->query("marks/wanma/׼��ɱͬ��_bai")) { 	
		message_vision(CYN"
���׷���˵�ͷ���������������������纮ҹ�еĹ�ޣ������Ⱥ����
��Ⱥ����Ҳ�н��죡��\n"NOR,ob);
		message_vision(CYN"
���׷�˵������һ�������ֵ����Ⱥ��ͬ���ˣ����Ѿ�֪������Ѧ�����
�󾭣���Ҫ�ҳ������������ɱ�����ǵ�һ�����١���\n"NOR,ob);
		me->set("marks/wanma/׼��ɱͬ��_bai",1);
	}
	if (me->query("marks/wanma/׼��ɱͬ��_bai") 
		&& me->query_temp("marks/wanma/�״�_bai") && me->query_temp("marks/wanma/Ѧ��_bai")
		&& me->query_temp("marks/wanma/�һ�����_bai") && me->query_temp("marks/wanma/������_bai")
		&& me->query_temp("marks/wanma/����_bai") 
		&& !me->query("marks/wanma/׼��ɱ����_bai")) {
		message_vision(CYN"
���׷�ת����ȥ�����ں�ɫ������ǰ���૵��û��������������˵ʲô��
Ƭ�̣�����\n"NOR,ob);
		me->set("marks/wanma/׼��ɱ����_bai",1);
	}	
	if (me->query("marks/wanma/׼��ɱ����_bai") && me->query_temp("marks/wanma/ɱ���Ⱥ")
		&& me->query_temp("marks/wanma/ɱ������") && me->query("marks/wanma/���_bai",1)){
		message_vision("hmm, what's the reward here?\n",ob);
		me->set("marks/wanma/���_bai",1);
	}
	return;
}

void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {
        	if(owner=me->query("possessed")) {
			me = owner;
		} 
        	if(me->query("marks/wanma/���׷�_ma"))
                        me->set_temp("marks/wanma/���׷�_ma",1);
        }
        ::die();
}


string *event1_msg=	({
	CYN"
���׷������˵����������ָ���㵽����İɣ��Ҳ������������ʲô��
ֻҪ����Ϊ���ñ�����Ѫ�������������õĴ��ˡ���\n"NOR,

CYN"Ϊ����һ�죬����׼����ʮ���꣬����ʮ���꣬����ѩ�������ң�Ҷ����
�����ң������Ǳ��������ü�ʮ��������ԩ�꣡������\n"NOR,

CYN"���������������һ�����ص����ţ��·������������ϵ���������ħ���
�����䡣��\n"NOR,

CYN"��Ҫ��ס���Ӵ��Ժ�������񣬸��������������ʲô�����ò��ź�
�ڣ���������ô�������ǣ�����Ӧ���ģ���\n"NOR,

CYN"���������Ҿ����������Ⱥ����̫�죬̫���ף���Ҫ����ȥɱ���������£�
���Ķ���Ů������������������������ζ��\n"NOR,

});


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"���׷�ͻ�ֻӵ���һ������$N��ǰ�������ϣ�����˵���������ߣ������
�������ǵ�ͷȫ�����������ٻ������ң�����ǵ���Ҫ���㣬��ҲҪ���㣡\n\n\n"NOR,me);
		me->set("marks/wanma/ɱ����_bai",1);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}