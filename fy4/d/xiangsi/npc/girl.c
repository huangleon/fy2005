// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();

void create()
{
	set_name("СѾ��", ({ "xiao yahuan", "yahuan","girl" }) );
	set("class","moon");
	set("gender", "Ů��" );
	set("age", 15);
	set("str",20);
	set("force_factor",30);
	set("per", 27);
	set("attitude", "friendly");
	set("long","һ�����ھ��ߴ����СѾ�ߡ�\n");

	set("nickname",CYN"���ڴ����"NOR);
	set("title","��¹�"NOR);

	set("inquiry",([
       	"*": 	"��Ҫ���ң���\nСѾ�����������ʵĳ������硣",
    	]) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"СѾ��˯�������������������ˮ�����ǻᶳ���ˣ���\n",
		"СѾ�����������˵����֪����ʦ����ǰѺ�Ȫ�����ǲ��Ǿ��������������dip�������ġ�\n",
		"СѾ������˽���˵ֻҪ�����˱����߾������ܴ�տ������Ƕ�ѧ��������¹��Ļ���������\n",
	}) );

	set("no_arrest",1);

	set_temp("condition_type",CYN" <˯����>"NOR);

	set("combat_exp", 500000);

	set_skill("tenderzhi", 90);
	set_skill("unarmed", 120);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("unarmed", "tenderzhi");
	setup();

	carry_object(__DIR__"obj/wcloth")->wear();

}

void init()
{
	if (!is_fighting())
		set_temp("condition_type",NOR CYN" <˯����>"NOR);
}

int kill_ob(object who)
{
	if (query_temp("condition_type"))
	{
		delete_temp("condition_type");
		ccommand("wake");
		ccommand("ack "+who->get_id());
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
	target = select_opponent();
	if( ANNIE_D->check_buff(target,"freeze")) 
		return;

	message_vision(WHT "\nСѾ����æ���ҵĴӲ��Ϻ�Ȫ������һͰˮ������$N��ȥ��\n",target);

		buff =
		([
			"caster":me,
			"who":target,
			"type":"freeze",
			"att":"curse",
			"name":"���Ϻ�Ȫ��ǧ������",
			"buff1":"disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"disable_type":HIW " <������>"NOR,
			"time":4+random(4),
			"buff_msg":HIW"����ĺ�����Χ��$N��ȫ����$N������һ�����\n"NOR,
			"disa_msg":HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n"NOR,
			"disa_type":1,
		]);
	ANNIE_D->buffup(buff);
	if (random(2))
		ccommand("giggle "+target->get_id());
	else
		ccommand("fox");
}

void die()
{	
	object me,target;
	mapping buff;
	me = this_object();
	target = query_temp("last_damage_from");
	if (!target)
	{
		::die();
		return;
	}
	if( ANNIE_D->check_buff(target,"freeze")) 
		return;

	message_vision(WHT "\nСѾ���þ�������������Ͱ��ʣ�µĺ�Ȫˮ����$N��\n",target);

		buff =
		([
			"caster":me,
			"who":target,
			"type":"freeze",
			"att":"curse",
			"name":"���Ϻ�Ȫ��ǧ������",
			"buff1":"disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"disable_type":HIW " <������>"NOR,
			"time":6+random(16),
			"buff_msg":HIW"����ĺ�����Χ��$N��ȫ����$N������һ�����\n"NOR,
			"disa_msg":HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n"NOR,
			"disa_type":1,
		]);
	ANNIE_D->buffup(buff);
	message_vision(CYN"СѾ��ֻ�������������"+target->name()+"��̾һ����������������֮�£���ʮ֮�˾ţ������ȣ���������\n"NOR,target);
	::die();
}



void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
    command("duck "+who->query("id"));
	if (!is_fighting())
	{
		message_vision(CYN"СѾ�߲��˲����䣬�����ž��ڿ�ʼ���\n"NOR,who);
		set_temp("condition_type",NOR CYN" <˯����>"NOR);
	}
}
