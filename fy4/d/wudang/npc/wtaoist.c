#include <ansi.h>
inherit NPC;

void create()
{
        set_name("֪�͵���", ({ "waiter taoist", "taoist", "waiter" }) );
        set("gender", "����");
        set("long",
		"�䵱��֪�͵��ˣ�������ɫ���ۡ�ͷ����ɫ���ڡ�\n"
	);
        set("combat_exp", 10000+random(20000));
        set("score", 200);
        set("class", "wudang");

        create_family("�䵱��", 58, "����");

        set_skill("move", 30+random(20));
        set_skill("force", 30+random(20));
        set_skill("unarmed", 30+random(20));
        set_skill("dodge", 30+random(20));
        set_skill("taijiforce", 30+random(20));
        set_skill("taiji", 30+random(20));
        set_skill("five-steps", 30+random(20));

        map_skill("force", "taijiforce");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        set_skill("changelaw", 60);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.nianzijue" :),
        }) );
        
        
        setup();

        carry_object(__DIR__"obj/cloth1")->wear();
        carry_object(__DIR__"obj/hat")->wear();

}

void init()
{
	object 		me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
		if( me->query_temp("marks/������")) call_out("rockkill", 1, me);
		if( me->query_temp("marks/͵��"))   call_out("stealbook", 1, me);
		if( me->query_temp("marks/���ǽ�")) call_out("stealsword", 1, me);
        }
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="�䵱��" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �䵱�ɲ��ͱ��ɵ��˹��С�");
        return 0;
}


int rockkill(object me)
{
	me->set_temp("marks/������", 0);
	message_vision(HIR"֪�͵��˶�$N�ȵ���" + RANK_D->query_rude(me)+"���������䵱ɽɱ���䵱���ӣ���������\n"NOR,me);
	this_object()->kill_ob(me);
	return 1;
}
 
int stealbook(object me)
{
	me->set_temp("marks/͵��", 0);
	if(random(me->query("kar")) < 15) {
		say( HIR "֪�͵��˶�" + me->name() + "�ȵ���" + RANK_D->query_rude(me)
			+ "���������䵱ɽ͵��������������\n"NOR);
		this_object()->kill_ob(me);
	}
	return 1;
}

/*
int stealsword(object me)
{
	string	*skname;
	mapping skills;
	int	i;

	me->set_temp("marks/���ǽ�", 0);
	if(random(me->query("kar")) < 29){
		if( (string)me->query("family/family_name")=="�䵱��" ) {
			say( HIR "֪�͵��˶�" + me->name() + "�ȵ���" + RANK_D->query_rude(me)
			+ "������Ϊ�䵱���ӣ�����͵���䵱ɽ��ɽ֮�����㲻�����䵱���ӣ�\n"NOR);
			me->delete("family");
			me->set("title", "�䵱��ͽ");
			me->set("score", 0);
			skills = me->query_skills();
			if( mapp(skills) ) {
				skname = keys(skills);
				for(i=0; i<sizeof(skname); i++)
				skills[skname[i]] /= 2;
			}
			me->add("betrayer", 1);
			me->set("marks/�䵱��ͽ", 1);
                	tell_object(me, "\n�㱻�����ʦ���ˣ�\n\n");
		}
		else {
			say( HIR "֪�͵��˶�" + me->name() + "�ȵ���" + RANK_D->query_rude(me)
				+ "������͵���䵱ɽ��ɽ֮������������\n"NOR);
			this_object()->kill_ob(me);                
		}
	}
	return 1;
}
*/