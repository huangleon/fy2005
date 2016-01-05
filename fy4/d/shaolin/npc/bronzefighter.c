// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
	set_name("ͭ��", ({ "bronze fighter"}) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 3);
	set("max_kee", 99900);
	set("max_gin", 99900);
	set("max_sen", 99900);
	set("attitude", "peaceful");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "hoof"}) );
	set("combat_exp", 3500000);
	set_temp("apply/attack", 400);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge",40);
	setup();
}

void do_perform(object target,int count)
{
	object me = this_object();
	object weapon;
	int extra=200,hisexp,myexp,lvl,yourexp,mod=10,i;
	string msg;
		string *style = ({
HIR "��ͭ������"CYN"��������"HIR"ͻ����⣬����$n����磡" NOR,
HIY "��ͭ������"CYN"��צ����"HIY"ͻ���ƹ⣬ֱȡ$n���Ҹ���" NOR,
HIW "ǰͭ������"CYN"��������"HIW"ͻ���׹⣬����$n�����ȣ�" NOR,
HIG "��ͭ������"CYN"��צ����"HIG"ͻ���̹⣬ƽ��$n�����ţ�" NOR,
HIB "��ǰ��ͭ������"CYN"��������"HIB"���Һ��ͭ�����е�"CYN"��צ����"HIB"��֯��ϣ�����������������$nС����" NOR,
});

	string *style2 = ({
"���Σ���$N�ն�����"CYN"��������"HIY"�������Х������$n��С����",
"���Σ���$N����"CYN"��צ����"HIY"������Ӱ���أ���$n����Χס��",
"���Σ���$N��ǰһ�ݣ�����"CYN"��������"HIY"���裬��$n���˹�ȥ��",
"���Σ���$N������������"CYN"��צ����"HIY"ͷβ������ִ�$n������Ҫ����",
"���Σ���$N����"CYN"��������"HIY"һ�٣���������������$n��С����",
"Գ�Σ���$N����������Ծ������"CYN"��צ����"HIY"���ƶ�����������$n��ȥ��",
"���Σ���$N��Ӱ����$n�����ζ�������"CYN"��������"HIY"������ɨ��$n��С����",
"ӥ�Σ���$N������������"CYN"��צ����"HIY"���϶��£�Ѹ���ޱȣ�����$n��С����"});
	if (!target || !count)
		return;
	switch (count)
	{
	case 1:
			weapon = target->query_temp("weapon");
			myexp = (int)me->query("combat_exp");
			hisexp= (int)target->query("combat_exp");
			if(random(hisexp) < myexp && weapon)	
			{
			message_vision(
		HIW "\n\n$Nʹ��һʽ���β���ǹ��ǹ�������߰��ס$n���еı��У�"+ 
		weapon->name()+  "���ֶ��ɣ�\n\n" NOR, me,target);
			if( weapon->unequip()) weapon->move(environment(target));
			}
			else
			{
				me->add_temp("apply/attack", extra);
				me->add_temp("apply/damage", extra*2);
			msg = HIR+ "\n\n$Nʹ��һʽ���β���ǹ�����е�"CYN"��������"HIR"�����߰�ֱҧ$n��$l��\n\n"+ NOR;
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				me->add_temp("apply/attack", -extra);
				me->add_temp("apply/damage", -extra*2);
			}
		break;
	case 2:

    	myexp = (int) me->query("combat_exp");
    	hisexp= (int)target->query("combat_exp");
    	weapon = me->query_temp("weapon");
    
    	message_vision(HIW"\n�ຣãã���δ��ǰ���$N���е�"CYN"��צ����"HIW"��Ȼ�ó���ʮ������ã���֣�\n"NOR,me);

    	myexp=myexp/2+random(myexp)*5/2;
    
    	if(hisexp < myexp)
    	{
			target->force_busy(8);
			message_vision(YEL"$N���ȷ����󣬶�������������\n\n"NOR,target);
    	}
    	else
			message_vision(HIR"$N��Ȼ�����˷����������ϣ�$n���Ȼ���ʱ��ʧ���٣�\n\n"NOR,target,me);		

		break;
	case 3:
			myexp = (int) me->query("combat_exp");
			yourexp = (int) target->query("combat_exp")* mod/10;

			lvl = 8;
				
			msg = HIR "\n$N"HIR"ʹ����ǧҶ�Ʒ��еġ�ǧ��ǧ�䡻���ó�������Ӱ����$n��" NOR;
			if( random(myexp * lvl+yourexp) <myexp*lvl )
			{
				message_vision(msg + "\n", me, target);
				msg = "���$n��$N���˸���æ���ң�\n";
				message_vision(msg, me, target);
				target->force_busy(8);
				target->set_temp("busy_timer/dabei-strike",time());
			}
			else
			{
				me->add_temp("apply/attack",extra/2);
				COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				me->add_temp("apply/attack",-extra/2);
			}		break;
	case 4:
		for (i=0; i<5;i++ )
		{
			me->add_temp("apply/attack",extra*i/2);
			me->add_temp("apply/damage",extra*i/2);
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,style[i]);
			me->add_temp("apply/attack",-extra*i/2);
			me->add_temp("apply/damage",-extra*i/2);
		}
		break;
	case 5:

		msg = HIY  "$Nʹ����ת���Ǵ����еģ۷��������ݣ���������ˣ���ط�����һ����" NOR;      	
        	me->add_temp("apply/attack",extra/2);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack",-extra/2);
		msg = HIY  "$N����һ�У���һ����������һ������" NOR;
        	me->add_temp("apply/attack",extra/2);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack",-extra/2);
        	msg = HIY  "$N��Ȼ������ͷ������һ������һ����" NOR;
        	me->add_temp("apply/attack",extra/2);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack",-extra/2);
		break;
	case 6:
			weapon = target->query_temp("weapon");
			myexp = (int)me->query("combat_exp");
			hisexp= (int)target->query("combat_exp");
			
			if(random(hisexp) < myexp  && weapon && random(2))	
			{
			message_vision(
		HIW "\n\n$Nʹ��һʽ��һ����Ե�ݣ����������߰��ס$n���еı��У�"+ 
		weapon->name()+  HIW"���ֶ��ɣ�\n\n" NOR, me,target);
			if( weapon->unequip()) weapon->move(environment(target));
			}
			else
			{
					me->add_temp("apply/attack", extra*2);
					me->add_temp("apply/damage", extra*2);
				msg = HIR+ "\n\n$Nʹ��һʽ��һ����Ե�ݣ����е�"CYN"��������"HIR"�������ֱ��$n��$l��\n\n"+ NOR;
				COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
					me->add_temp("apply/attack", -extra*2);
					me->add_temp("apply/damage", -extra*2);
			}
		break;
	case 7:
	 	msg = HIR "\n\n"+
	"��$N���е�"CYN"��������"HIR"�����������³����\n��$N���е�"CYN"��צ����"HIR"չ����������ɨ��\n"+
        "��$N���е�"CYN"��������"HIR"���������������̣�\n"+
        "��$N���е�"CYN"��צ����"HIR"����ֱ�̣�\n"+
"ͬʱʹ�����������޷����ߺȵ����ģ���צ�����죭��������\n���еļһ�ͬʱ��������" NOR;
		message_vision(msg,me,target);
		for (i=0; i<4;i++ )
		{
			me->add_temp("apply/attack",extra*i);
			me->add_temp("apply/damage",extra*i);
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM," ");
			me->add_temp("apply/attack",-extra*i);
			me->add_temp("apply/damage",-extra*i);
		}
		break;
	case 8:
			me->add_temp("apply/attack",extra);
				msg = HIY  "$N"HIY"ʹ���򳹲��縫���еġ����師����һ���������������е�"CYN"��צ����"HIY"��ɽ����$n"HIY"������һ����" NOR;
			COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
			
			msg = HIY  "�ڶ�����" NOR;
				me->add_temp("apply/damage",extra);
				COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				
					msg = HIY  "��������" NOR;
				me->add_temp("apply/damage",extra);
				COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				me->add_temp("apply/damage",-extra);    

					me->add_temp("apply/damage",-extra);
			   me->add_temp("apply/attack",-extra);
	

		break;
	case 9:
		        msg = HIR+"$Nʩչ��������һ��ָ��"+ HIY +
        	"����ָӰ�����ų��ȵ�ָ�磬����$n��ȫ��\n\n" + NOR;
					me->add_temp("apply/attack", extra*2);
					me->add_temp("apply/damage", extra*2);
				COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
					me->add_temp("apply/attack", -extra*2);
					me->add_temp("apply/damage", -extra*2);
		break;
	case 10:
		for (i=0; i<8;i++ )
		{
			me->add_temp("apply/attack",extra*i);
			me->add_temp("apply/damage",extra*i);
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,HIY+style2[i]+NOR);
			me->add_temp("apply/attack",-extra*i);
			me->add_temp("apply/damage",-extra*i);
		}
		break;
	}
	
}