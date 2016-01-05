// conjure.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string spells, spl, trg;
	object target;
	int chance;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩչ��ͨ��)\n");

	if( environment(me)->query("no_magic")||environment(me)->query("no_fight") )
		return notify_fail("�����޷�ʹ����ͨ��\n");
	
//	if (me->query_temp("till_death/lockup")==1)
//    		return notify_fail(" ����Ѫ���������������ͣ�һʱ��Ȼ����ʩչ��ͨ����\n");  

	if( !arg ) return notify_fail("ָ���ʽ��conjure <��ͨ> [on <Ŀ��>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("����û�� " + trg + "��\n");
	} else {
		spl = arg;
		target = 0;
	}

	spl = replace_string( spl, " ", "_");
	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
	if( stringp(spells = me->query_skill_mapped("magic")) ){
		if (me->is_fighting() && random(1000) < chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time())// ��ս���С�%2 chance of fail a perform
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"��ͷһ�ţ�¶���˺ô��һ������������\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\n����ͷһ�ţ�û�ó���������¶���˿��ţ�\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
		if ((int)SKILL_D(spells)->conjure_magic(me, spl, target)) {
			if (userp(me) && ANNIE_D->check_buff(me,"forceshield")) {
        		if (me->query("force") > 300)
        			me->set("force", me->query("force") - 300);
        		else
        			me->set("force",0);
        		me->force_status_msg("force");
        	}
			me->force_status_msg("atman");
			return 1;
		}
		return 0;
	}	
	return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ���ͨϵ��\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	conjure <��������> [on <ʩ������>][0m
[0;1;37m����������������������������������������������������������������[0m   

ʩ������Ҫָ��<��������>��<ʩ������>�򲢲������еĶ���Ҫ��

�����е��书�ɹ�Ϊ�Ĵ��ࣺ���ֱ��Ӧ��ʹ������Ϊ��
��1����ͳ�似�����������������ķ�������perform/exert��
��2�������������˹����µİ�ʶ��ͨ����(conjure)
��3) ���������������������������ѵĹ����������䣩��(cast)
��4����ͷ������������ȵ�ͨ�콵����ɽ��Ѫ���䣩����curse��

��ν������ָ����Magic�����ϵ����ⷨ�������˹����µİ�ʶ��ͨ��

��ʹ��ĳһ������֮ǰ�������� enable ָ����ָ��Ҫʹ�õķ���ϵ��
������Ҫʹ�����˹����µİ�ʶ��ͨ��essencemagic���еġ���ʶ��
(mind_sense) ������Ҫ����
enable magic essencemagic
conjure mind_sense on xxxx

��ս����ʹ�����⼼����2%�Ŀ��ܻ�ʧ�ܣ�����Լ�æ�ң���ϰĳЩ
�ض����书���Խ��ʹ˸��ʡ�

ע����ͬ�ķ���ϵ�������಻ͬ���������ʱת���Լ��ķ���ϵ��
	���������������ʱ���㡣

���ָ��: perform, exert , curse, cast

[0;1;37m����������������������������������������������������������������[0m    
 
HELP
        );
        return 1;
}
