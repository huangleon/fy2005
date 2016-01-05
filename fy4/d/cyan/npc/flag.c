#include <ansi.h>
#include <combat.h>
inherit WALL;
void summon_ghost();

void create()
{
	set_name(MAG"ب�Ż��"NOR, ({ "demonic standard","standard" }) );
	set("race","Ԫ��");
	set("long","һ������ɫ�ľ޴���ᦲ���һ����̳���룬�����Χ�������������顣\n�����������ͼ�ݻ�(kill)ب�Ż�ᦡ�\n");
	set("combat_exp",20000);
	set("no_fly",1);
	set("no_curse",1);
	set("busy_immune",4);
	set("no_arrest",1);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: summon_ghost() :),
	}) );

	set("real_boss",1);
	set_skill("iron-cloth",200);
	set_skill("steelwall",200);
	map_skill("iron-cloth","steelwall");
	setup();
}

int kill_ob(object who)
{
	if (!is_fighting())
	{
		summon_ghost();
		summon_ghost();
//		summon_ghost();
	}
	::kill_ob(who);
	return 1;
}

void summon_ghost()
{
	object ghost;
	string g;
	object *enemy;
	int i;

	g=__DIR__"ghost"+(random(4)+1);
	ghost = new(g);
	ghost->move(environment());

	message_vision(MAG"һ�����������и������Ļ�����ب�Ż�ᦱ߷��£�ֱ�����㣡\n"NOR,ghost);

	enemy = query_enemy();

	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			ghost->kill_ob(enemy[i]);
			enemy[i]->kill_ob(ghost);
		}
	}
	ghost->set("possessed",this_object());

	call_out("dist",10,ghost);
	return;
}

void dist(object ghost)
{
	if (!ghost)
		return;
	message_vision(BLU"$N�ڿ��д��˸����������彥����ɢ��Ӱ������\n"NOR,ghost);
	destruct(ghost);
	return;
}

void die()
{
	object me = this_object();
	object who = query_temp("last_damage_from");
	object tis = new(__DIR__"obj/artifact");
	object *c,owner;
	int i;
	
	if (objectp(owner=who->query("possessed")))
		who = owner;
	
	c=all_inventory(environment());
	for (i=0;i<sizeof(c) ; i++)
	{
		if (c[i]->is_ghost() && !userp(c[i]))
		{
			message_vision(BLU"$N�ڿ��д��˸����������彥����ɢ��Ӱ������\n"NOR,c[i]);
			destruct(c[i]);
		}
	}
	message_vision(MAG"\n����һ�����죬ب�Ż�ᦺ�Ȼ���أ�ɽ����һ�󵭵����������𣮣���\n\n"NOR,me);
	if (who)		// You can get it again and again.. need mark to proceed riddle
		{
			tis->move(who);
			who->set("annie/ب�Ż��",1);
		}
	::die();
	return;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
