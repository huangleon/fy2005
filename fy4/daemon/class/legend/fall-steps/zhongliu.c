// Silencer@fengyun June.2005
// L50�� ��������Super defense stance

#include <ansi.h>
#include <combat.h>
#define S_TIME 480 // ���ʹ��8���ӣ�ÿ��60��
#define L_TIME 3600 // һСʱ��ԭ

inherit SSERVER;
int perform(object me, object target)
{
	string msg, type;
	int duration, extra, add, skill, num, amount;
	mapping buff;
	object weapon;

	extra = me->query_skill("fall-steps",1);
	skill = me->query_skill("six-sense",1);
	if( extra < 150 || skill < 150 || me->query_skill("dormancy",1) < 150 ) {
		return notify_fail("����������Ҫ150������粽�����鰵ʶ��Ϣ��������\n");
	}
	if( me->query("class") != "legend" && userp(me) ) {
		return notify_fail("ֻ����ѩɽׯ�ĵ��Ӳ��ܹ�ʹ�á���������\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return notify_fail("��������ֻ�������Լ����ϡ�\n");
	}
	if( ANNIE_D->check_buff(me,"afm-absshield") ) {
		return notify_fail("���Ѿ���ʹ���������ˡ�\n");
	}
	// ��ʼ��
	if( me->query("timer/tx-zhongliu") < 1 ) {
		me->set("timer/tx-zhongliu",time());
		me->set("timer/pfm/tx-zhongliu",S_TIME);
	}
	if( me->query("timer/tx-zhongliu") + L_TIME < time() ){
		me->set("timer/tx-zhongliu",time());
		me->set("timer/pfm/tx-zhongliu",S_TIME);
	}
	if( me->query("timer/pfm/tx-zhongliu") < 50 ) {
		duration = L_TIME + me->query("timer/tx-zhongliu") - time();
		return notify_fail("�㻹Ҫ�ȴ�"+ (duration/60)+"���Ӳ����ٴ�ʹ��������\n");
	}
	duration = 60;
	me->add("timer/pfm/tx-zhongliu",-60);
	if( weapon = me->query_temp("weapon") ) {
		if( weapon->query("skill_type") == "sword" ) {
			msg = "$N����һ�䣬�Ӽ������Ϊ������������׹��ǧ�������Ƶģ������ڵĶ���һ������\n��һ����������Χ�˳�֮�ڣ����Ʋ�����һ������ͭǽһ�㡣\n";
		} else if( weapon->query("skill_type") == "blade" ) {
			msg = "$N����һ�䣬�Ӽ������Ϊ������������׹��ǧ�������Ƶģ������ڵĶ���һ������\n��һ����������Χ�˳�֮�ڣ����Ʋ�����һ������ͭǽһ�㡣\n";
		}
	}
	if( !msg ) {
		msg = "$N��ʽ˲Ϣ��䣬����󺣳�����һ��ĩƽ��һ��������Χ�˳�֮�ڣ����Ʋ�����һ������ͭǽһ�㡣\n";
	}
	add = me->query("timer/pfm/tx-zhongliu")/60;
	amount = 200 - F_ABILITY->check_ability(me,"3_zhongliu_add",3)*20;
	buff =
		([
			"caster": me,
			"who": me,
			"type": "afm-absshield",
			"type2": "tx-turtle-stance",
			"att": "bless",
			"name": "��粽������",
			"buff1": "resistance/kee",
			"buff1_c": 50,
			"buff2": "apply/attack",
			"buff2_c": -amount,
			"shield_type": "force",
			"shield_amount": 50,
			"shield_msg": "",
			"time": 60,
			"buff_msg": BRED + HIY +msg+NOR,
		]);
	ANNIE_D->buffup(buff);
	write(WHT"���ڽ�������"+ ((me->query("timer/tx-zhongliu") + L_TIME - time())/60) + "�������㻹��ʹ��"+ add + "��������\n"NOR); 
	return 1;
}
