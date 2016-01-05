#include <ansi.h>
inherit SKILL;

void setup()
{
	set("name","������");
	set("type","force");
	set("effective_level",100);
	set("usage/force",1);
	set("skill_class","knight");
	set("difficulty",200);
}

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int num, hit_damage, amount, n, tt, skill;
	string msg, dot_owner, dir, index;
	mapping buff;

	skill = me->query_skill("herb",1);
	if( damage <= 0) {
		return 0;
	}
	if( skill < 250 || me->query_skill("longlife-force",1) < 180 ) {
		return 0;
	}
	if( skill < 300 ) {
		n = 3 + F_ABILITY->check_ability(me, "3_longlife_add", 3);
	} else {
		n = 5 + F_ABILITY->check_ability(me, "3_longlife_add", 3);
	}
	if( random(100) > n ) {
		return 0;
	}
	n = random(5);
	switch( n ) {
		case 0:
			msg = HIR BLK"$n"HIR BLK"�����³�һ�Ű�����������һ�ָ����˶��������\n"NOR;
			message_vision(msg, ob, me);
			me->set_temp("timer/pfm/longlife_pangu",time());
			break;
		case 1:
			dot_owner = file_name(me);
			sscanf(dot_owner,"%s#%s",dir,index);
			dot_owner = me->query("id")+ index;
			if( !(ob->query_temp("dot/dream-herb/antbite/"+dot_owner)) ) {
				msg = HIR"$n�������һ����Ѫ����Ѫ��ΪѪ����ã��$N��Χ��\n"NOR;
				message_vision(msg, ob, me);
				msg = RED"$N����һ��������������ʴ��\n"NOR;
				num = me->query_skill("herb")/2 + random(me->query_skill("herb")/4);
				num = num*(100+F_ABILITY->check_ability(me,"poison_dmg",2)*2)/100;
				num = COMBAT_D->magic_modifier(me, ob, "kee", num);
				ob->receive_damage("kee",num, me);
				ob->receive_wound("kee",num/2,me);
				tt = 8*(100+F_ABILITY->check_ability(me,"poison_dur",2)*5)/100;
				ob->set_temp("dot/dream-herb/antbite/"+dot_owner, 1);
				call_out("dot", 6, me, ob, tt, 0, num, dot_owner, msg);
			}
			break;
		case 2:
			if( me->query("force")+damage*2 < 2*me->query("max_force") ) {
				me->add("force",damage*2);
			} else {
				me->set("force", 2*me->query("max_force"));
			}
			me->force_status_msg("force");
			msg = WHT"�������³�һ����Ѫ����ɫȴ������������\n"NOR;
			tell_object(me, msg);
			break;
		case 3:
			me->delete("timer/pfm/jiuqipoxiao");
			msg = YEL"�������Ѩ�������������\n"NOR;
			tell_object(me, msg);
			break;
		case 4:
			if( !ANNIE_D->check_buff(me,"knight-resistup") ) {
				buff =
				([
					"caster": me,
					"who": me,
					"type": "knight-resistup",
					"att": "bless",
					"name": "�����廨������ʬ��",
					"buff1": "resistance/kee",
					"buff1_c": 30,
					"time": 20,
					"buff_msg": YEL"$N�ķ�ɫ��������Ұ�����������Ĺ�â��һ��֮�¾����н�ʯ֮����\n"NOR,
				]);
				ANNIE_D->buffup(buff);
			}
			break;
	}
	return 0;
}

void dot (object me, object enemy, int total, int count, int amount, string dot_owner, string msg)
{
	int num;
	if( !me || !enemy || !enemy->is_fighting(me) ) {
		if( enemy ) {
			message_vision(RED"$N����ɫ�����ָ�����������\n"NOR, enemy);
			enemy->delete_temp("dot/dream-herb/antbite/"+dot_owner);
		}
		return;
	}
	message_vision(msg,enemy);
	enemy->receive_damage("kee", amount, me);
	enemy->receive_wound("kee", amount/2, me);
	count = count+1;
	if( count < total) {
		call_out("dot", 6, me, enemy,total, count, amount, dot_owner, msg);
	} else {
		message_vision(RED"$N����ɫ�����ָ�����������\n"NOR, enemy);
		if( enemy ) {
			enemy->delete_temp("dot/dream-herb/antbite/"+dot_owner);
		}
	}
	return;
}

int help(object me)
{
	write(@HELP
L100������������cangsheng��
������һ������Ѫ����ת���������ˣ�ÿ20����ʹ��һ�Ρ�
ת����ֵΪ�������ȼ����屶��ת��Ч��Ϊ200%
�ķ�200��������

��������������180������ʱ���ܵ�����˺�ʱ��һ�����ʹ�ͨ��
������������һЩƽʱ�޷�ʵ�ֵ������似�����ܳ��ֵ���
1���������ڲ��Ʊ̵Ķ������˺���
2�����ܵ����˺�תΪ��������������
3���ڶ������������ֿ���Ѫ�˺���������+30%��ʮ�֣�
4�����ᾭ������һ����������������ʹ��
5����30�������˺�һ����ʹ��һ�С��̹ſ��족
����Ҫ��250��ҩ����180����ԯ����
L250 ҩ�� 3%����
L300 ҩ�� 5%����
ͨ������ability3�������ӹ�ͨ�����ļ��ʡ�
HELP
	);
	return 1;
}