#include <ansi.h>
inherit SMART_NPC;
void smart_fightx();

void create()
{
	object weapon;
	set_name("ҹ�沿��", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("gender", "����" );
	set("nickname",HIR"�� Ѫ �� ��"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(50) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","necromancy",1);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(BLU"Ѫ��֮��"NOR, ({ "cloth"}) );
	weapon->set("long","һ�����а߰�Ѫ�������¡�\n");
	weapon->set("value",0);
	weapon->wear();

}

/*
void dispell(object me)
{
	me->die();
}

int kill_ob(object who)
{
	object corpse,me = this_object(),*enemy;
	int i,j;
	string str;
	seteuid(getuid());
	::kill_ob(who);
	set("atman",query("max_atman"));
	if (is_busy())
		return 1;

	if (random(2) == 1)
	{
	// exhume
		message_vision(HIB"$N�����૵��������ģ�����һ�ӣ���Ȼ�����ź��̴ӵ�����ð��\n" NOR,me);
		message_vision(HIB"Ƭ�̣��������۳����Σ�ȴû��һ��������\n"NOR,me);
		for (i=0; i < random(4)+1; i++)
		{
			corpse = new("/obj/item/mocorpse");   
			corpse->set("name",HIR"��ħ"NOR);
			corpse->set("victim_name",HIR"��ħ"NOR);
			corpse->set("no_burn",1);
			corpse->set("long",
		"����һ������а����۳ɵĹ��������������������һֻ���ǡ�\n");
			corpse ->move(environment(this_player()));
			message_vision("$N�������ϵ�$n�૵����˼������$n�鴤�˼��¾�վ��������\n", me, corpse);
			corpse = corpse->animate(me, 300+random(100));
			corpse->start_call_out( (: call_other, __FILE__, "dispell", corpse :), 60);

				enemy = query_enemy();
				j = sizeof(enemy);
				while(j--) {
					if( enemy[j] && living(enemy[j]) ) {
						corpse->kill_ob(enemy[j]);
						if( userp(enemy[j]) ) enemy[j]->fight_ob(corpse);
						else enemy[j]->kill_ob(corpse);
					}
				}
		}
	}
	else
	{
		// sanqin sheet
		message_vision(HIC"$N���о��񣬼�����ζ�������һ��ȼ�������������������ͷ����������\n"NOR, me);
		for (i=0; i < 3; i++)
		{
			str = "sanqing/sq"+(i+1);
			if (!query_temp(str))
			{
				me->add_temp(str,1);
				str = "/obj/npc/sq_guard"+(i+1);
				corpse =new(str);
				corpse->move(environment(me));
				corpse->invocation(me, 400);
				corpse->set("possessed", me);
			}
		}
		message_vision(CYN"$N�Ǻ�Ц���������Ѳ����ϵ�����λ���Ѱ����ˣ�\n"NOR, me);
	}
	start_busy(2);
	return 1;
}

void smart_fightx()
{
	object corpse,me = this_object(),*enemy;
	int i,j;
	string str;
	seteuid(getuid());
	auto_smart_fight(100);	// rascal design :p
	if (is_busy())
		return;
	if (random(2) == 1)
	{
	// exhume
		message_vision(HIB"$N�����૵��������ģ�����һ�ӣ���Ȼ�����ź��̴ӵ�����ð��\n" NOR,me);
		message_vision(HIB"Ƭ�̣��������۳����Σ�ȴû��һ��������\n"NOR,me);
		for (i=0; i < random(4)+1; i++)
		{
			corpse = new("/obj/item/mocorpse");   
			corpse->set("name",HIR"��ħ"NOR);
			corpse->set("victim_name",HIR"��ħ"NOR);
			corpse->set("no_burn",1);
			corpse->set("long",
		"����һ������а����۳ɵĹ��������������������һֻ���ǡ�\n");
			corpse ->move(environment(this_player()));
			message_vision("$N�������ϵ�$n�૵����˼������$n�鴤�˼��¾�վ��������\n", me, corpse);
			corpse = corpse->animate(me, 300+random(100));
			corpse->start_call_out( (: call_other, __FILE__, "dispell", corpse :), 60);

				enemy = query_enemy();
				j = sizeof(enemy);
				while(j--) {
					if( enemy[j] && living(enemy[j]) ) {
						corpse->kill_ob(enemy[j]);
						if( userp(enemy[j]) ) enemy[j]->fight_ob(corpse);
						else enemy[j]->kill_ob(corpse);
					}
	}			

		}
	}
	else
	{
		// sanqin sheet
		message_vision(HIC"$N���о��񣬼�����ζ�������һ��ȼ�������������������ͷ����������\n"NOR, me);
		for (i=0; i < 3; i++)
		{
			str = "sanqing/sq"+(i+1);
			if (!query_temp(str))
			{
				me->add_temp(str,1);
				str = "/obj/npc/sq_guard"+(i+1);
				corpse =new(str);
				corpse->move(environment(me));
				corpse->invocation(me, 400);
				corpse->set("possessed", me);
			}
		}
		message_vision(CYN"$N�Ǻ�Ц���������Ѳ����ϵ�����λ���Ѱ����ˣ�\n"NOR, me);
	}
	start_busy(2);

}


���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
