#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "miao shaotian", "miao" }) );
        set("long",
                "����ʨ�����ڣ���ͷ�෢������ȴ������ö�𻷡�\n");
    	set("nickname", HIR"�෢�� ��ư����"NOR);
    	set("chat_chance",1);
	set("chat_msg",	({
			"�����춶���Ž𻷣�ҹ�ɰ��Ц������������������ӣ��������ү\n�������ǣۿ�ȸͼ�ݣ��ٰ�����һ����....����....����!!��\n",
			})  );
        set("inquiry",([
 		"��ȸͼ"  :"����ȸͼ�𣬰�������־�ڱصá���\n",
              ]) );
        set("combat_exp", 800000);
	
	set_skill("unarmed",150);
	set_skill("blade",150);
	set_skill("lianxin-blade",150);
	set_skill("tigerstrike",200);
	set_skill("dodge",100);
	set_skill("puti-steps",150);
	set_skill("parry",150);
	
	map_skill("parry","lianxin-blade");
	map_skill("dodge","puti-steps");
	map_skill("move","puti-steps");
	map_skill("unarmed","tigerstrike");
	map_skill("blade","lianxin-blade");
	
	setup();
        carry_object(__DIR__"obj/miaocloth")->wear();
	carry_object(__DIR__"obj/miaoblade")->wield();
}

int accept_object(object me, object obj)
{                                                                 
	if( (string) obj->query("name") == "��ȸͼ")
	{
		command("smile");
		message_vision(HIY"$N͵͵����$nһ����ȸͼ��\n"NOR,me,this_object());
		message_vision(HIY"$Nһ��,��ϸ���˿������ɹ�����Ц������\n"NOR,this_object());
		me->set_temp("marks/longlife_peacockmap",1);
		call_out("fighting",2,me);
		return 1;
	}
	else
 	{
		message_vision("$N˵�������¸�����磿�������գ�������̸��\n",this_object());
		return 1;
	}
 	  return 1;
}


int fighting(object me)
{
	object zhang,zhao;
	if (present(me,environment(this_object())))
	{
		if (zhang=present("zhang san",environment(this_object())))
		{
			zhang->kill_ob(this_object());
			message_vision("$N˵����˭����̿�ȸͼ���Ҿ�Ҫ����������\n",zhang);
			this_object()->kill_ob(zhang);
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