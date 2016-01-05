// Originally coded by Lsb, modified by Tushen/Silencer 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, duration;
	object weapon;
	int chance, busy;

	extra = me->query_skill("xuanyuan-axe", 1);
	if( me->query("class") != "knight" ) {
		return notify_fail("ֻ�п���ֵ��Ӳ���ʹ���������������ľ�����\n");
	}
	if( extra < 160 ) {
		return notify_fail("��������������Ҫ160������ԯ������\n");
	}
	if( userp(me) && me->query_skill_mapped("force") != "longlife-force" ) {
		return notify_fail("��ԯ������Ҫ����������ϣ�\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	duration = me->query("timer/pfm/jiuqipoxiao") + 30 - time();
	if( duration > 0 ) {
		return notify_fail("������������������������" + duration + "���ʹ�á�\n");	
	}
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack",extra);
	target->set_temp("no_check_pfm_win",1);

/*	msg = HIY  "\n$N���е�"+ weapon->name()+HIY"�趯���ٶ��������죬������������
������"+weapon->name()+HIY"ͻȻ������������$n"NOR+HIY"����һʽ������������������\n\n" NOR;*/

	msg = YEL"$N"NOR+YEL"�������������֮������������������֮�У�����˳��һ������Ĺ켣
��ʼ�������������죬��Ȼ������硣"HIY"

$N"HIY"���һ������������"+ weapon->name()+ HIY"���������켣ֱ����ȥ��\n"NOR,
	message_vision(msg,me,target);
	msg = HIW  "���������Ŀ��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	msg = HIW  "��ʯ���������" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIW  "����ɽ�������ĵ���" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIW  "�������Զ��䶷־��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIY  "����������"HIW"�����������˺�ѣ�"+weapon->name()+HIW"���ŷ���֮�Ƶ�ͷ���£�" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack",-extra);

	if( objectp(target) ) {
		if (target->query_temp("damaged_during_attack")) {
			 COMBAT_D->win_lose_check(me, target, 1);
		}
	}

	if( objectp(target) ) {
		target ->delete_temp("no_check_pfm_win"); 
		target->delete_temp("skip_damage_record");
	}

	msg = YEL"\n���ܵ������ƺ�����Ӧһ�㣬��Ȼɢȥ����Ϣ����Ъ���ƿ�����ɢ��\n\n\n"NOR,
	message_vision(msg, me, target);

	chance = F_ABILITY->check_ability(me, "resist_sen") * 10;
	if( random(100) < chance) {
		busy = 2;
	} else {
		busy = 3;
	}
	me->perform_busy(busy);
	me->set("timer/pfm/jiuqipoxiao", time());
	return 1;
}
/*
	message_vision(msg,me,target);
	msg = HIY  "���������Ŀ�����е�weapon" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIY  "��ʯ���������" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIY  "����ɽ�������ĵ���" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIY  "�������Զ��䶷־��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	TARGET�������������֮����ME��������������֮��
	����˳��һ������Ĺ켣��ʼ�������������죬��Ȼ�������
	TARGET��ʧɫ����־��ʧ��
	���һ������!����AXE���������켣ֱ����ȥ
	���ܵ�����������һ����˺�ѣ�TAR��ǰһ����ME���е�AXE�����ŷ���֮��׷���������ǰ
	"����������" NOR;
	���ܵ������ƺ�����Ӧһ�㣬��Ȼɢȥ
	��Ϣ����Ъ���ƿ�����ɢ������
	��������ɽ��ֹ ������ֹ �䲻���� ������֮ 
 */