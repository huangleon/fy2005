// annie 07.2003
// dancing_faery@hotmail.com
// ��ѩ���
// Backfire.... silencer��Ȼ��no_abs & no_shield��ôrascal��pfm���ṩ��player��....hmm
// ���ڴ�pfm����Ҫ��enable���жϣ���ֹЧ�������dodge��

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	mapping buff;
	int extra, level, ratio;

	if( me->query("class") != "moon" ) {
		return notify_fail("ֻ����¹��ĵ��Ӳ���ʩչ����ѩ��ᰡ���\n");
	}
	extra = me->query_skill("stormdance", 1);
	if( extra <150 ) {
		return notify_fail("����ѩ��ᰡ���Ҫ����150����������衣\n");
	}
	if( ANNIE_D->check_buff(me, "damageshield") || me->query_temp("damage_shield") ) {
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	}
/*
	��ѩ���?���	stormdance_hanxueliulan_1	L100	1M
	��ѩ���?���	stormdance_hanxueliulan_2	L120	2.4M
	��ѩ���?���	stormdance_hanxueliulan_3	L140	4M
	��ѩ���?���	stormdance_hanxueliulan_4	L200	6.4M
*/
	level = me->query("annie/stormdance_hanxueliulan");
	if( me->query("class") != "moon" ) {
		level = 0;
	}
	if( !userp(me) ) {
		level = 5;
	}
	switch( level ) {
		case 0:
			ratio = 15;
			break;
		case 1:
			ratio = 25;
			break;
		case 2:
			ratio = 25;
			break;
		case 3:
			ratio = 35;
			break;
		case 4:
			ratio = 45;
			break;
		case 5:
			ratio = 55;
			break;
	}

	buff = ([
			"caster": me,
			"who": me,
			"type": "damageshield",
			"att": "bless",
			"name": "������衤��ѩ���",
			"buffup_name": "backfire",
			"buffup_type": level >= 2 ? "all" : "kee",
			"buffup_ratio": ratio,
			"buffup_msg": WHT"һ��׶�Ĵ̹ǵĺ����߽���$n"NOR+WHT"���У�$n"NOR+WHT"���ɴ���һ��������\n"NOR,
			"time": extra/3,
			"buff_msg": WHT"$N"NOR+WHT"��է�䣬������˪��Ͷ���������緭���̹�������\n"NOR,
		]);

	ANNIE_D->buffup(buff);
	return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
