//========================��������====================================
// --------   neon
// Modified by Silencer: Is this a super-gin-killer? Nope, DWG has spirit and bloodcurse

#include <ansi.h>
#include <combat.h>
inherit SSERVER;


int perform(object me, object target)
{
	string msg;
	int celeskill, celepower, i, skill, total, enhance;
	int hit, busy, damage, ability, ap, super;
	
	object weapon;
	string name, name1;
	string *perform_msg = ({
	HIW "�����ڿ�"NOR WHT" �� $N"WHT"����$W"WHT"��׺�������գ�����$n��\n"NOR,
	HIW "������ң"NOR WHT" �� $N"WHT"��Ʈҡ��$W"WHT"����õ���Ӱ�ж��������ػ�����$n��\n"NOR,
	HIW "Я�׳���"NOR WHT" �� $N"WHT"����$W"WHT"����һ����������$n��\n"NOR,
	HIW "���߳���"NOR WHT" �� �����ѿ����ı�������$W"NOR+WHT"����������ķ���������$n��\n"NOR,
	HIW "��������"NOR WHT" �� $W"WHT"������������$n"NOR+WHT"�ζ�����ʱ�仯��һ����꣬����$n��\n"NOR,
	HIW "��ͼ����"NOR WHT" �� $N"WHT"����$W"WHT"��ת���飬�ڿ��лó�һ��������׭��ӡ��$n��\n"NOR,
	HIC "���н�������ǿ��Ϣ"NOR WHT" �� $N"WHT"������������ʱ���˺�һ��$W"NOR+WHT"ƽƽ����һ�Ӷ�����ȴ�޿ɵֵ���\n"NOR,
	YEL "���������Ժ������"NOR WHT" �� $N"WHT"һ������$W"WHT"��һ������ʵ���͵��ھ���������Χ��$n��\n"NOR,
	HIG "�����Ȼ"NOR WHT" �� $N"WHT"���޲�������Ȼ���лó��ڶ����飬��������չʾ�ڲ�ã��ؼ䡣\n"WHT
	"$n���ɵ���������Ȼ���Ķ����ΰ��\n"NOR});

	if( me->query("class") != "yinshi" ) {
		return notify_fail("ֻ�е����ȵ��ӿ���ʹ��"WHT"���������֡�"NOR"��\n");
	}
	weapon = me->query_temp("weapon");
	skill = me->query_skill("thunderwhip",1);
	celeskill = me->query_skill("celecurse", 1);
	if( skill < 110 || celeskill < 110 ) {
		return notify_fail("���������֡���Ҫ110����ͨ�콵�����ױ޷���\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail(WHT"���������֡�"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	}
	ap = me->query_skill("cursism"); 
	if( userp(me) && ap >= 500 ) {
		ap = 500; // got to cap it.
	}
	if( celeskill >= 200 && (me->query_skill("qiankunwuxing",1) >= 200 || !userp(me)) ) {
		// 2040 for 4 busy.
		hit = 9;
		busy = 4;
		name ="��������"; 
		name1 = "�ռ�ɱʽ"; 
		damage = (140+ap*ap*ap/80000)*120/100;
	} else if( celeskill >= 160 ) {
		// 160-200, enable 400-500. dmg 1226 - 1862. for 4 busy
		hit = 6;
		busy = 4;
		name ="��������";
		name1 = "�м�ɱʽ"; 
		damage = 300 + ap*ap*ap/80000;
	} else {
		// 110-160,1.1-3.1M, enable 250-400,dmg 560-860 for 3 busy
		hit = 3;
		busy = 3;
		name ="��������";
		name1 = "����ɱʽ"; 
		damage = 60+ap*2;
	}
	enhance = 200;
	ability = F_ABILITY->check_ability(me,"yljx_add")*2;
	damage = damage * (100 + ability)/100;
	damage = COMBAT_D->magic_modifier(me, target, "gin", damage)/hit;
	message_vision(WHT"\n\n$N�ı޷�һ�䣬��ʽչ�������ܲ���Ũ�ƣ��꽫��δ�䣬������δ��
"HIC"ʹ���������Ƶ�"+ HIC+ name1 + HIC"  ��  ��"HIC+ name +"������\n\n"NOR, me);

	for( i = 0; i < hit; i++ ) {
		msg = perform_msg[i];
		msg = replace_string(msg,"$W", weapon->name()+WHT);
		message_vision("\n" + msg, me, target);
		if( COMBAT_D->do_magic_attack(me, target, "cursism", "gin", enhance ) || target->is_unconcious() ) {
			message_vision(MAG+weapon->name()+MAG"����һ˿˿���ĵ��Ϲ⣬����$n"NOR+MAG"����...\n"NOR, me, target);
			target->receive_damage("gin", damage,me);
			target->receive_wound("gin",damage/4, me);
		} else {
			message_vision(CYN"$N��������������$n"CYN"�ı�Ӱ��\n"NOR,target,me);
		}
	}
	if( hit == 9 ) {
		message_vision(HIG"\n\n$N"+HIG"�������ƣ������������Ϊһ�壬������и�ɻ���\n\n"NOR, me);
	}
	message_vision("\n",target);
	COMBAT_D->report_status(target);
	COMBAT_D->win_lose_check(me, target, 1);
	super = me->query_skill("flying-dragon",1);
	if( super >= 100 ) {
		//super = (super-100)/20+F_ABILITY->check_ability(me,"3_yl9x_add",3)/2;
		super = (super-100)/10+F_ABILITY->check_ability(me,"3_yl9x_add",3);
		if( random(100) < super && me->query_temp("yl9x_times") < 2 ) {
			me->add_temp("yl9x_times",1);
			message_vision(WHT"$Nһ�������³�������Ȼ˿�����Գ��͡�\n"NOR, me);
			busy = 0;
		} else {
			me->set_temp("yl9x_times",0);
		}
	}
	me->perform_busy(busy);
	return 1;
}