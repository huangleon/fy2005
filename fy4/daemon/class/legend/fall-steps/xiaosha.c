// Silencer@fengyun	June.2005
// L50�� ����ɱ������3���ӣ��������� ��ϵ����ߵ��������������½�����

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg, type;
	int duration, extra, add, skill,num;
	mapping buff;

	extra = me->query_skill("fall-steps",1);
	skill = me->query_skill("six-sense",1);
	if( extra < 110 ) { 
		return notify_fail("����ɱ����Ҫ110������粽��\n");
	}
	if( me->query("class") != "legend" && userp(me) ) {
		return notify_fail("ֻ����ѩɽׯ�ĵ��Ӳ��ܹ�ʹ�á���ɱ����\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return 	notify_fail("����ɱ��ֻ�������Լ����ϡ�\n");
	}	
	if( ANNIE_D->check_buff(me, "tx-atk-stance") > 0 ) {
		return notify_fail("���Ѿ���ʹ�á���ɱ���ˡ�\n");
	}
	duration = me->query_temp("timer/tx-stance")+30 - time();
	if( duration > 0 ) {
		return notify_fail("��ѩ����ÿ30�������ת��һ�Σ�"+duration+"��\n");
	}
	if( ANNIE_D->check_buff(me, "tx-df-stance") > 0 ) {
		ANNIE_D->debuff(me, "tx-df-stance");
		ANNIE_D->debuff(me, "kee1");
	}
	me->set_temp("timer/tx-stance", time());
	num = 20;
	if( extra >= 150 ) {
		if( skill >= 250 ) {
			num = 30;
		}
	}
	buff =
		([
			"caster":	me,
			"who": 		me,
			"type":		"tx-atk-stance",
			"att":		"bless",
			"name":		"��粽����ɱ",
			"buff1": 	"pfm/legend_berserk",
			"buff1_c":	num,
			"buff2": 	"apply/composure",
			"buff2_c": 	-10,
			"time":  	600,
			"buff_msg":	WHT"�����ֹǣ�ɱ����ˮ��к�ذ�������$N���ܡ�\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}
