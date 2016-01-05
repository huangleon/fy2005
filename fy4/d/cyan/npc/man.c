// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();
void smart_sleep();

void create()
{
	object weapon;
	set_name("��ʮ��", ({ "fang shisan", "fang","shisan" }) );
	set("class","beggar");
	set("gender", "����" );

	set("age", 25);

	set("force_factor",30);

	set("attitude", "friendly");
	set("long","ſ�����Ϻ�����˯�������˰��Σ����ϳ�����������Ǯׯ����\n�ƹ񡢽������˳ơ�������ǽ����ʮ����\n");

	set("nickname",MAG"������ǽ"NOR);
	set("title","����Ǯׯ"NOR);

	set("inquiry",([
       	"*": 	"�������������������������ڣڣڣ�����������",
    	]) );

	set("chat_chance", 1);
	set("chat_msg", ({
//		   (: smart_sleep() :),
	"��ʮ���ĺ����������졣\n",
	}) );

	set("no_arrest",1);

	set_temp("condition_type",YEL" <������˯��>"NOR);

	set("combat_exp", 4400000);

	set_skill("dodge", 400);
	set_skill("doggiesteps", 400);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	

	map_skill("dodge", "doggiesteps");
	setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("ʮ��ȹ", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("����ñ", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();


}

void init()
{
	if (!is_fighting())
		set_temp("condition_type",NOR YEL" <������˯��>"NOR);
}

int kill_ob(object who)
{
	if (query_temp("condition_type"))
	{
		delete_temp("condition_type");
		ccommand("wake");
		ccommand("hmm "+who->query("id"));
		ccommand("say ����˯������Ҫ����");
	}
	::kill_ob(who);
	smart_fight();
	return 1;
}

void smart_fight()
{
	object me,target;
	mapping buff;
	me = this_object();

	ccommand("perform dodge.goujitiaoqiang");

	if (!is_fighting())
	{
		message_vision(CYN"\n��ʮ�����˸���Ƿ��ſ�����ϣ��ܿ��ֳ������硣\n"NOR,me);
		set_temp("condition_type",NOR YEL" <������˯��>"NOR);
	}

}


void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
    command("kick "+who->query("id"));
	if (!is_fighting())
	{
		message_vision(CYN"\n��ʮ�����˸���Ƿ��ſ�����ϣ��ܿ��ֳ������硣\n"NOR,who);
		set_temp("condition_type",NOR YEL" <������˯��>"NOR);
	}
}
