#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fightx();

void create()
{
	object weapon;
	set_name("Ǭ���Ų���", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("gender", "Ů��" );
	set("nickname",HIR"̫��ԭ���޼��� ��Ԫһ����˹ͨ"NOR);
	
	set("attitude", "aggressive");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: smart_fightx() :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	set_skill("taiji",300);
	set_skill("unarmed",200);
	set_skill("five-steps",240);
	set_skill("dodge",200);
	set_skill("parry",200);
	map_skill("unarmed","taiji");
	map_skill("dodge","five-steps");
	
	set_skill("divineforce",200);
	map_skill("force","divineforce");

	setup();
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("�ʺ�Χ��", ({ "scarlet scarf","scarf" }) );
	weapon->set("long","�ʺ�Χ��(Scarlet scarf)��\n");
	weapon->set("value",0);
	weapon->wear();

	set_temp("apply/damage",500);
}

void smart_fightx()
{
	object *tar;
	int i,j;
	object target;

	if (is_busy())
		return;

	tar = query_enemy();
	if (sizeof(tar) > 1)
	{
		message_vision(HIY"\n$Nʹ���䵱��ʧ���Ľ������������������黭�˸���Բ��\n$N�������������һ��������������ȥ��\n"NOR,this_object());
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

// Ϊ����parry busy��Ч(��,̫����),���ﲻʹ��mimic function....
			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
			tar[i]->add("force_factor",query("force_factor")/2);
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,HIY"$N"HIY"ֻ����һ���������������ɼ�����$n"HIY"��ȥ��"NOR);
			tar[i]->add("force_factor",-query("force_factor")/2);
			tar[i]->perform_busy(j+random(2));	// busy 0~1.
			target->add_temp("no_check_pfm_win",-1);
			target->receive_damage("kee",1,this_object());
		}
		perform_busy(2);
	}	

}

/*

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
