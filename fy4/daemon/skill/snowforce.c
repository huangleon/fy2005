 // annie 6.27
// dancing_faery@hotmail.com

#include <combat.h>
#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","��ѩ�ľ�");
	set("type","force");
	set("usage/force",1);
	set("skill_class","moon");
	set("effective_level",130);
	set("difficulty",200);
	set("no_refund",({"chillblade"}));
}

mapping ob_hit(object ob, object me, int damage)
{
	string msg;
	mapping buff;
	int i, n;
	int *hits;

	if( ANNIE_D->check_buff(me,"shinra") < 1 && ANNIE_D->check_buff(me,"shine") < 1 ) {
		return 0;
	}
	if( ANNIE_D->check_buff(me,"shinra") > 0 ) {
		if( !ANNIE_D->check_buff(ob,"lowresist2") ) {
			buff =
				([
					"caster":me,
					"who":ob,
					"type":"lowresist2",
					"att":"curse",
					"name":"������衤��Ӱ����",
					"buff1":"resistance/sen",
					"buff1_c":-50,
					"time":6,
					"buff_msg":CYN"��˪���裬$N"CYN"����������ҡ�\n"NOR,
				]);
			ANNIE_D->buffup(buff);
		}
	}
	if( ANNIE_D->check_buff(me,"shine") > 0 ) {
		if( me->query_temp("weapon") && me->query_temp("weapon")->query("ice_blade") && ANNIE_D->check_buff(me,"enchantweapon") > 0 ) {
			if( me->query_skill("chillblade",1) >= 190 && me->query_skill("stormdance",1) >= 130 ) {
				n = 2;
			} else {
				n = 1;
			}
			hits = me->query_temp("marks/shine_hits");
			if( !hits ) {
				hits = ({});
			}
			hits += ({ time() });
			for( i = 0; i < sizeof(hits); i++ ) {
				if( hits[i] + 30 < time() ) {
					hits -= ({ hits[i] });
				}
			}
			hits -= ({ 0 });
			me->set_temp("marks/shine_hits", hits);
			if( n == 1 ) {
				message_vision(CYN"\nһ�Ƶ���ɫ�Ĺ�â������$N"CYN"���е�"+me->query_temp("weapon")->name()+CYN"���\n"NOR,me);
			} else {
				message_vision(CYN"\n��â������$N"CYN"���е�"+me->query_temp("weapon")->name()+CYN"�������԰㳤����\n"NOR,me);
			}
			if( wizardp(me) && (string)me->query("env/combat1") == "verbose" ) {
				tell_object(me,"���� has accumulated " + sizeof(hits)*5*n + "% damage.\n");
			}
			return 0;
	/*		for (i=0; i<14; i++)
			{
				if (ANNIE_D->check_buff(me,"shine"+i))	continue;
				msg="Ը�����Ǿ�����ҹҹ��������";

				buff =
						([
								"caster":me,
								"who":me,
								"type":"shine"+i,
								"att":"bless",
								"name":msg[i*2..i*2+1],
								"buff1":"annie/chillblade_extradamage",
								"buff1_c":damage/15,
								"time":30,
								"warn_msg":" ",
								"buff_msg":CYN"һ�Ƶ���ɫ�Ĺ�â������$N"CYN"���е�"+me->query_temp("weapon")->name()+CYN"���\n"NOR,
						]);
				ANNIE_D->buffup(buff);*/			
		}
	}
	return 0;
}

int skill_difficulty()
{
	object me = this_player();
	int skill;
	if( me && userp(me) ) {
		skill = me ->query_skill("snowforce", 1);
		if( skill < 170 ) {
			return 200;
		} else {
			return 300;
		}
	}
	return 200;
}

int help(object me)
{
	write(@HELP   
��ѩ�ľ�����170���ϣ�ѧϰϵ�����ӵ�300��

L60 ��˪�����᡻��shuanghuaningjie��
�������ڳ�����æ�����֣�15����ʹ��һ��
��һ���ٴ�ʹ��ʱ��12����
������ٴ�ʹ��ʱ�併�͵�10����
�������ٴ�ʹ��ʱ�併�͵�5����

L90 ����Ӱ���ա���jingyingchangkong��
�����Լ�����ѵ��������������ʱ��15���ӡ�
L90��+500�������
L170��+1000�������
����������Ч������

L120�����Ǿ��ڡ�(bingpojingbi)
���ؼ������Ķ����Ǿ��ڣ���һ������ʹ��
���۳�һ�����֮����ս�����赲���ֵĹ���
60��ʹ��һ�Σ�����æ��2�غϣ�������60�����ʧ
��һ���赲���ʣ�����
�ڶ����赲���ʣ�����
�������赲���ʣ�����

L160�������������yinlingkouming��
һ����˵�����������ĵ��˻��˺������Ѫ���ޣ�����
��ʹ���������������޷��˺���Ѫ��ֵ��ħ�����书��
�⣩�����ɹ�����20�룬����æ��һ�غϡ�
���ؼ��ԣ£ϣӣ���Ч��

HELP
    );
    return 1;
}
