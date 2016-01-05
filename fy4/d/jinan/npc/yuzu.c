// garrison.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����", ({ "yuzu", "yu zu" }) );
	set("long",
		"������С����Ҳ��Ҫ�����ǵ����ǣ�����������֯��һȺ�ˡ�\n");
	set("attitude", "heroism");
	set("vendetta_mark", "authority");
	set("str", 27);
	set("cor", 26);
	set("cps", 25);
	set("combat_exp", random(10000));
	set_skill("unarmed", 70+random(50));
	set_skill("staff", 70+random(50));
	set_skill("parry", 70+random(50));
	set_skill("dodge", 70+random(50));
	set_skill("move", 100+random(50));
	set_temp("apply/attack", 70);
	set_temp("apply/dodge", 70);
	set_temp("apply/parry", 70);
	set_temp("apply/damage", random(100));
	set_temp("apply/armor", 70);
	set_temp("apply/move", 100);
	set("chat_chance", 1);
	set("chat_msg", ({
        "�������������������������������Ӵ�ƺȡ���\n",
		"���������֣����̽�������ô��ô�ࣿ\n",
	}) );
	set("inquiry", ([
		"tanjian" : "̽��ѽ����˵����˵��������Ǯʲô����˵��\n",
		"̽��" : "̽��ѽ����˵����˵��������Ǯʲô����˵��\n",
	]));    
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{
	int i, value;
    
	if(ob->query("money_id")) 
	{
		i = ob->query("base_value");
		value = ob->query_amount() * i;
	}
	else 
	{
		return 0;
	}
	if(!NATURE_D->is_day_time())
	{
	        if(value > 10000) 
	        {
	        	message_vision("$N����˵��������ȥ�������\n", this_object());
	        	environment(this_object())->add("exits/east","/d/jinan/dalao1");
	        	who->set_temp("̽��", 1);

			if (!REWARD_D->check_m_success(who,"ԡѪ����") && REWARD_D->riddle_check(who,"ԡѪ����") <=1)
				REWARD_D->riddle_set(who,"ԡѪ����",1);


	        	call_out("close_door", 30);
	        } 
	        else 
	        {
	            message_vision("$N˵�����������ҹ��̽�࣬������ʲô���⣿��\n", this_object());
	        }
	} 
	else
	{
    		if(value > 500)
    		{
        		say("����Ǻǵ�Ц����̽��ѽ����˵����˵������\n");
        		environment(this_object())->add("exits/east","/d/jinan/dalao1");
        		who->set_temp("̽��", 1);
			call_out("close_door", 40);

			if (!REWARD_D->check_m_success(who,"ԡѪ����") && REWARD_D->riddle_check(who,"ԡѪ����") <=1)
				REWARD_D->riddle_set(who,"ԡѪ����",1);

   		} 
   		else 
   		{
        		say("����˵�������Ǯ��������ү�ȾƵ��أ�\n");
    		}
	}
	return 1;
} 

void close_door()
{
	if(environment(this_object())->query("exits/east"))
	{
		message_vision("$N����������ˣ���֨~ѽ~��һ�����Ѵ��Ź���������\n", this_object());
		environment(this_object())->delete("exits/east");
	}	

}
