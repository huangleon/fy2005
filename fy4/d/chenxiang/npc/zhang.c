#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("����", ({ "zhang san", "zhang" }) );
        set("long",
                "һ��ѩ�׵ļ�װ�������صؽ��½󳨿���¶����ʵǿ׳�����ţ�ȴ��\n���Ѹ��ס�\n");
    	set("nickname", HIW"����"NOR);
    	set("chat_chance",1);
		set("chat_msg",	({
			"����¶��̰����Ŀ�⣬�ٺ�һЦ��\n",
			})  );
        set("inquiry",([
        		"��ȸͼ"  :"Ҫ�����Ļ������ǲ�ҪϹ�����ĺá�\n",
              ]) );
        set("combat_exp", 800000);

		set_skill("unarmed",150);
		set_skill("dodge",150);
		set_skill("demon-steps",100);
		set_skill("tigerstrike",200);
		set_skill("parry",150);
	
		map_skill("unarmed","tigerstrike");
		map_skill("dodge","demon-steps");
	
		set("perform_busy_d", "demon/dodge/demon-steps/lianhuanbabu");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

		setup();
        carry_object("/d/chenxiang/npc/obj/whitecloth")->wear();
}

int accept_object(object me, object obj)
{                                                                 
	if( (string) obj->query("name") == "��ȸͼ")
	{
		message_vision(HIY"$N͵͵����$nһ����ȸͼ��\n",me,this_object());
		message_vision(HIY"$N���˿���ͻȻ�˷ܵĹ�����Ц������\n",this_object());
		me->set_temp("marks/longlife_peacockmap",1);
		call_out("fighting",2,me);
		return 1;
	}
	else
 	{
		message_vision("$N˵��������С�����գ����ҷ�����ȸͼ��û�ţ�\n",this_object());
		return 1;
	}
 	  return 1;
}


int fighting(object me)
{
	object miao,zhao;
	if (present(me,environment(this_object())))
	{
		if (miao=present("miao shaotian",environment(this_object())))
		{
			miao->kill_ob(this_object());
			message_vision("$N˵����С�����ӣ�������ȸͼ���Ҿ������㣡��\n",miao);
			this_object()->kill_ob(miao);
		}
		if (zhao=present("zhao yidao",environment(this_object())))
		{
			zhao->kill_ob(this_object());
			message_vision("$N˵����������ͼ�����ˣ��ϵ�����Ҳ��ɱ����\n",zhao);
			this_object()->kill_ob(zhao);
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
