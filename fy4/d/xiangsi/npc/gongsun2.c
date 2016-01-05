// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();
int look_stone();

void create()
{
	set_name("����̫����", ({ "gongsun furen","gongsun","furen" }) );
	set("class","huashan");
	set("gender", "Ů��" );
	set("age", 45);

	set("attitude", "friendly");

	set("long","���Դӵ�һ�γ���ɱ��ɽ����һ������ڲ���֮����������
��ʮ���ꡣ�������������о��飬�����ʸ�ļ�λǰ�����Ʋ�
���жϣ����������ֹ���ʮһ�Σ�ƽ��ÿ��һ�Σ�ÿ��ɱ�Ķ�
�ǵ��������еĶ�����֡�\n"NOR);
	set("chat_chance", 1);
	set("chat_msg", ({
		CYN"����̫����������˵����Ҫɱ���ˣ��������Ѿ����ˣ���Ҳ�������ٻ�������Σ�Ȼ�������������\n"NOR,
	}) );

	set("inquiry",([
       	"����": 	"�������ǵ��¼۸���ߵ�ɱ�֣���ϧ�����ò��ã��޷�һ��������Ը��\n",
		"����": "�����ҵ��ɷ��������ļ����ﱲ�ݺܸߣ������ҲŻᱻ��Ϊ����̫���ˡ�\n",
		"�": (: look_stone :),
    	]) );

	set("combat_exp", 1500000);

	set("reward_npc",1);
	set("difficulty",3);

	set_skill("move", 400);
	set_skill("dodge", 200);
	set_skill("parry", 100);
	set_skill("force",200);
	set_skill("staff",200);
	set_skill("illusionstick",300);
	set_skill("liangyi-force",200);
	set_skill("hanmei-force",200);
	map_skill("force","liangyi-force");
	map_skill("staff","illusionstick");
	map_skill("parry","illusionstick");
	
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
        	 (: smart_fight() :),
	}) );

	setup();

	carry_object(__DIR__"obj/robe2")->wear();
	carry_object(__DIR__"obj/stick");

}


int kill_ob(object who)
{
	ccommand("wield all");
	::kill_ob(who);
	smart_fight();
	return 1;
}

void smart_fight()
{
	set("force",4000);
	ccommand("perform menghuantianluo");
}

void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
    command("sigh2 "+who->query("id"));
	if (!is_fighting())
		ccommand("unwield all");
}


void die()
{
	object me;
	me = query_temp("last_damage_from");
	if (me )
	{
		if (REWARD_D->riddle_check(me,"������Թ") == 6 && me->query_temp("annie/riddle/moonmaster") == 9)
		{
			message_vision(CYN"\n����̫���˶�ס�Ų���̾��������������ǰ�ˣ��������£��Ѿ������ǵ������ˣ�����\n����̫����˵��������ھ�������¥�С���Ҫ���������ȥ�����Ӱɡ�\n����̫����ҡ��ҡ����������ͷ�������⿪��\n\n"NOR,me);
			REWARD_D->riddle_set(me,"������Թ",7);
			destruct(this_object());
			return;
		}
	}
	::die();
}

int look_stone()
{
	object me;
	me=this_player();

	if (REWARD_D->riddle_check(me,"������Թ") == 6 )
	{
		ccommand("hmm");
		ccommand("say ���������ó���ı�����˵��");
		me->set_temp("annie/riddle/moonmaster",9);
		kill_ob(me);
		return 1;
	}
	message_vision("$N˵�������С��ɵ����ˣ��������϶����������\n"NOR,this_object(),this_player());
    return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
