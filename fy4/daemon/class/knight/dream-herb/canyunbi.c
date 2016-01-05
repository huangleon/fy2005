// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *ob;
	int i, skill, my_exp, his_exp, bonus,num, enhance, tt, crit, suc;
	string msg, dot_owner, dir, index;

	if( me->query("class") != "knight" ) {
		return notify_fail("ֻ�п���ֵ��Ӳ��ܹ�ʹ��"+HIG"�����Ʊ̡�"NOR+"��\n");
	}
	if( me->query_skill("dream-herb",1) < 100 ) {
		return notify_fail("�����Ʊ̡���Ҫ100���������廨����\n");
	}
	if( !me->is_fighting() ) {
		return notify_fail("�����Ʊ̡�ֻ����ս����ʹ�á�\n");
	}
	skill = me->query_skill("herb");
	bonus = me->query_skill("dream-herb",1);
	if( userp(me) ) {
		if( me->query("force") < 100 ) {
			return notify_fail("���Ʊ���Ҫ100��������\n");
		}
		me->add("force", -100);
	}

	msg =  HIG "$N������ת����ɫͻȻ��ñ�����������\n\n" NOR;
	message_vision(msg, me);
	msg = HIG "$N"HIG"��һҧ��⣬ʹ�������廨�������������ġ�������ϲ��Ʊ̡����� 
��Ѫ�������Ũ��һ�㣬����׷����䡣\n\n" NOR;
	message_vision(msg, me);
	me->add_temp("apply/herb",bonus*2);
	ob = all_inventory(environment(me));
	dot_owner = file_name(me);
	sscanf(dot_owner,"%s#%s", dir, index);
	dot_owner = me->query("id") + index;
	suc = 2;
	for( i = 0; i < sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i] == me ) {
			continue;
		}
		if( !ob[i]->is_fighting(me) ) {
			continue;
		}
		if( ob[i]->query_temp("dot/dream-herb/cyb/"+dot_owner) ) {
			continue;
		}
		if( COMBAT_D->do_magic_attack(me, ob[i], "herb", "kee", 0) ) {
			msg = HIR "�廨����������Ϣ������$n�����ڣ�����\n" NOR;
			message_vision(msg, me, ob[i]);
			suc = 3;
			msg = YEL"$Nֻ����ǰ"+HIG"��"+HIG"��"+HIM"��"+HIY"�"NOR+YEL"���ƺ�������ֻС���ڷ��衣\n"NOR;
			crit = 0;
			if( me->query_skill("herb",1) >= 210 ) {
				crit = crit + (me->query_skill("herb",1)-200)/10;
			}
			if( crit > 10 ) {
				crit = 10;
			}
			crit += F_ABILITY->check_ability(me, "3_canyunbi_add", 3);
			// 275 + random(137)
			// -- 275*8 + random(1000) = 2200 + random(1000)	in 24 turns
			// with ability it's,+20% damage, *150% duration
			// (275*1.2 + random(137)*1.2) * 12 = 3960 + random(1972) in 36 turns
			num = skill/2 + random(skill/4);
			num = num*(100+F_ABILITY->check_ability(me,"poison_dmg",2)*2)/100;
			if( crit + 5 > random(100) ) {
				num = num*2;
				msg = YEL"��$Nֻ����ǰ"+HIG"��"+HIG"��"+HIM"��"+HIY"�"NOR+YEL"���ƺ�������ֻС���ڷ��衣��\n"NOR;
			}
			message_vision(msg,ob[i]);
			num = COMBAT_D->magic_modifier(me, ob[i],"kee",num);
			ob[i]->receive_damage("kee", num, me);
			ob[i]->receive_wound("kee", num/2, me);
			tt = 8*(100+F_ABILITY->check_ability(me,"poison_dur",2)*5)/100;
			ob[i]->set_temp("dot/dream-herb/cyb/"+dot_owner,1);
			call_out("dot", 6, me, ob[i], tt, 0, num, dot_owner, msg);
		} else {
			tell_object(me, HIW"����廨����"+ob[i]->name()+"�����ˣ���\n"NOR);
		}
	}
	me->add_temp("apply/herb",-bonus*2);
	me->perform_busy(suc);
	return 1;
}


void dot (object me, object enemy, int total, int count, int amount, string dot_owner, string msg)
{
	int num;
	if( !me || !enemy || !enemy->is_fighting(me) ) {
		if( enemy ) {
			message_vision(YEL"$N����ɫ�����ָ�����������\n"NOR, enemy);
			enemy->delete_temp("dot/dream-herb/cyb/"+dot_owner);
		}
		return;
	}
	message_vision(msg, enemy);
	enemy->receive_damage("kee", amount, me);
	enemy->receive_wound("kee", amount/2, me);
	count = count+1;
	if( count < total ) {
		call_out("dot", 6, me, enemy, total, count, amount, dot_owner, msg);
	} else {
		message_vision(YEL"$N����ɫ�����ָ�����������\n"NOR,enemy);
		if( enemy ) {
			enemy->delete_temp("dot/dream-herb/cyb/"+dot_owner);
		}
	}
	return;
}