// thousand_hand.c

#include <ansi.h>

inherit NPC;
void create()
{
		set_name("½�崨" , ({ "wuchuan", "lu wuchuan", "lu" }) );
		set("long", "��üͷ�������ƺ���ʲô�ⲻ�������⡣\n");
		set("attitude", "friendly");

		set("age", 48);
        set("gender", "����" );
        create_family("��ƽɽׯ", 1, "ׯ��");
		set("combat_exp", 10000);
		set_skill("dodge", 20);
        set_skill("sword", 30);
        set_skill("qingpingsword", 20);
        set_skill("force", 60);
        set_skill("qingpingforce", 55);
        set_skill("chaos-steps", 20);
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");

		setup();
		carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

void init()
{	
	   object me;
	
	   ::init();
	   if(query("given")<3) {
		   add_action("do_answer","answer");
		   me = this_player();
		   if( interactive(me) && !is_fighting() ) {
		      remove_call_out("greeting");
		      switch (random(2)) {
		         case 0:
		            call_out("greeting", 1, me);
		         break;
		         case 1:
		            call_out("ask_him", 5,me );
		         break;
		      }
		   }
	 	}
}

void greeting(object me)
{
   		if( !me || environment(me) != environment() ) return;
   		message_vision("$Nҡͷ��������������ͬ����ʮϡ������÷��إһ֦��������
Բ�����£��Ű�������֪��\n",this_object(),me);
   		return;
}

int ask_him(object me)
{
   object obj;

   obj = this_object();
   if (!me)	return 1;
   	
   if(environment(me) == environment())
   tell_object(me,name()+"�����������ﲻ֪������������֮ʣ����������֮ʣ����
������֮ʣ�������Ｘ�Σ�����answer��\n");
   obj->set_temp("marks/asking",1);
   return 1;
}

int do_answer(string arg)
{
   	object me, obj, kite;
   	obj = this_object();
   	me =this_player();
   	
   	if(!query_temp("marks/asking")) return 0;
   	if(!arg) {
      	message_vision(name()+"��������"+me->name()+"Ҳ�ﲻ���ң�\n", me);
      	obj->set_temp("marks/asking", 0); 
      	return 1;
   	}
   	if( arg == "23" )
   	{
      	message_vision(name()+"��������һ����������ˣ��ã�\n", me);
      	if (REWARD_D->check_m_success(me,"��ˮ̽��")) {
      		tell_object(me,"½�崨�����ã�û�뵽�㾹Ȼ��ô�������Ҹ����С���ݣ��Ժ���Ҳ�����õ���\n");
      		tell_object(me,"½�崨����������������˸�СС�ķ��ݡ�\n");
      		return 1;
      	}
            
      	switch(random(2)) {
         	case 0:
            	tell_object(me, name()+"����������ݽ�����Ҳ���õĵ���\n");
            	message_vision(name()+"�ݸ�"+me->name()+"һ�����ݡ�\n", me);
            	kite = new(__DIR__"obj/kite");
            	kite->move(me);
	    		add("given",1);
         		break;
         	case 1:
            	tell_object(me,name()+"��������������ܣ�����������ƽɽׯ��԰�����ϵ��㣬�����˸��󱦲أ�\n");
      	}
		obj->set_temp("marks/asking", 0); 
      	return 1;
   }
   else {
      	tell_object(me, name()+"�����Ҿ��ò���ԣ�\n");
      	obj->set_temp("marks/asking", 0); 
      	return 1;
   }
}



void reset()
{
	delete("given");

}
