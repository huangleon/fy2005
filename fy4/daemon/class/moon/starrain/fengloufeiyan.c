// annie 07.2003
// dancing_faery@hotmail.com
// desc�� ��Ұ��䡰�ʽ.��

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_ANNIE;

int perform(object me, object target)
{
	string msg,temp1;
	object weapon,*pros,shadow,newweapon;
	int attack_points, dodge_points,skill,count,i,j,k,level,num1,duration;
	int mm;
	
	if (me->query("class")!="moon" && userp(me))
		return notify_fail("Ψ����¹����Ӳ���ʹ�á���©���̡�\n");
	
	skill = me->query_skill("starrain",1);
	if (skill < 150)
		return notify_fail("����©���̡���Ҫ����150���ĺ���������\n");

	if (me->query_skill_mapped("force") != "snowforce")
       	return notify_fail("����©���̡�������ѩ�ľ�������\n");	// limit enforce

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����©���̡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

/*	��©����?�Ͼ�	starrrain_fengloufeiyan_1	L100	1M
	��©����?�Ͼ�	starrrain_fengloufeiyan_2	L150	4M
	��©����?�Ͼ�	starrrain_fengloufeiyan_3	L200	6.4M

*/
	level = me->query("annie/starrain_liulongbingjia");
	if (!userp(me))
		level = 5;
	
	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if (count < 6)
		return notify_fail("����©���̡�������Ҫ6ö������\n");

	duration = me->query("timer/pfm/fengloufeiyan")+ 20 - time();
	if (duration>0)
		return notify_fail("��©������"+duration+"�������ٴ�ʹ�á�\n");
	
	me->set("timer/pfm/fengloufeiyan",time());

	if (!target->is_busy())	// target����busy״̬ʱ���extra attack bonus.
		me->add_temp("apply/throwing",me->query_skill("throwing"));
		
	attack_points = COMBAT_D->skill_power(me, SKILL_USAGE_ATTACK);
	dodge_points = COMBAT_D->skill_power(target, SKILL_USAGE_DODGE);	// �����жԷ��൱�ڲ���busy��	
		
	if (!target->is_busy())
		me->add_temp("apply/throwing",-me->query_skill("throwing"));

	k=0;
	for (i=0; i<6; i++)
		if (random(attack_points+dodge_points) > dodge_points)	// pass
			k++;

	if(wizardp(me) && (string)me->query("env/combat1")=="verbose" ) {
		write(WHT"atk = "+ attack_points + ", dp = " + dodge_points + "\n"NOR);
		mm = dodge_points*100/(attack_points+dodge_points);
		write(WHT" missing chance = " + mm + "%\n"NOR);
		write(WHT" all miss chance = " + mm*mm*mm*mm/10000*mm*mm/10000+ "/100 %\n");
	}
	
//	message_vision("K:"+k+"\n",me,target);

	j=0;
	if ( F_ABILITY->check_ability(me,"flfy_add")< random(10))
	{
		for (i=0; i<k; i++)
			if (random(attack_points+dodge_points) > dodge_points)	// pass
				j++;
	}					
	else
		j=k;

	if (wizardp(me))
		message_vision("AP:"+attack_points+"  DP:"+dodge_points+"\n",me,target);
	
	msg = HIY"ֻ��$N"HIY"һ����ȣ���������ߣ�˫��էȻ������������â���������㺮�⼲��$n��\n"NOR;
	message_vision(msg,me,target);

	switch (j)
	{
	case 0:
		msg = HIY"$n"HIY"��Цһ�����ߵ���ө��֮�⣬Ҳ��������ԣ�
$n"HIY"һ��һ�ģ�Ҳ������ʲô�ַ����������$N"HIY"������ء�"NOR;
		break;
	case 1:
		msg = HIY"$n"HIY"�߶����������ּ佫��ö�������䣬���ڰ��Ե��⣬����ȴΪ���һ���������ˣ�"NOR;
		break;
	case 2:
		msg = HIY"$n"HIY"�������𣬿����ܹ�������Ϯ�����㺮�ǣ����ڿ���һת���ܹ����
�磬�������ŵ�������棬ȴû�ϵ�������ö�����������֮������$n��"NOR;
		break;
	case 3:
	case 4:
	case 5:
		msg = HIY"$n"HIY"���һ����бб����ǰ����һ��Բ�������㺮��Ӧ�����䡣
����ö����ȴ��������һ�㣬Խ��$n"HIY"�����ת�۷ɻأ�����$n"HIY"���ģ�"NOR;
		j = 3;
		break;
	case 6:
		msg = HIY"$n"HIY"��ʧɫ��б�ߺ�ɣ��ݺ���Ų������������������׷����"NOR;
		break;
	}
	
	if (level >= 2 && j == 0 )
		msg = HIY"$n"HIY"����üë�������ĳ�һ�����磬�������������䡣\n"NOR;
	
	message_vision(msg+"\n",me,target);

	me->set_temp("annie/perform_starrain",1);
	target->set("timer/liulongbingjia",time());
	
	if (j > 0)
	{
		me->add_temp("apply/damage",-skill/3);		// -150

		pros = target->query_temp("protectors");
		target->delete_temp("protectors");
		target->add_temp("cant_parry",1);
		target->add_temp("cant_dodge",1);
		target->add_temp("cant_counter",1);
		
		for (i=0; i<j ;i++ )
			COMBAT_D->do_attack(me,target, TYPE_PERFORM, " ");
		
		if (target)
		{
			target->add_temp("cant_parry",-1);
			target->add_temp("cant_dodge",-1);
			target->add_temp("cant_counter",-1);
			target->set_temp("protectors",pros);
		}
		me->add_temp("apply/damage",skill/3);
	}
	else
	{
		// j == 0
		if (level < 2 || !target->is_busy())
		{
			// ��׼������ʽ��
			
			seteuid(getuid());
			shadow=new("/obj/npc/shadefigure");
			shadow->changeshape(me);		
			annie_mimic(me,shadow);
			sscanf(file_name(weapon),"%s#%d",temp1,num1);
			newweapon=new(temp1);
			newweapon->move(shadow);
			newweapon->wield();

			shadow->move(environment(me));
			shadow->set_temp("fight_to_death",1);

			me->add_temp("cant_parry",1);
			me->add_temp("cant_dodge",1);
			me->add_temp("cant_counter",1);
			
			pros = me->query_temp("protectors");
			me->delete_temp("protectors");
			
			for (i=0; i<6 ;i++)
				COMBAT_D->do_attack(shadow,me, TYPE_REGULAR, " ", "���ˣ�");	 //  not TYPE_PERFORM.

			me->receive_damage("kee",1,target);

		   	if (shadow)
		   		destruct(shadow);
			if (me){
				me->add_temp("cant_parry",-1);
				me->add_temp("cant_dodge",-1);
				me->add_temp("cant_counter",-1);
				me->set_temp("protectors",pros);
			}			
		}
	}

	
	if (userp(me))	weapon->add_amount(j-6);	// 6 

	me->delete_temp("annie/perform_starrain");
	me->perform_busy(2);
	return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/

