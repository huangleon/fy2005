#include <ansi.h>
#include <skill.h>
#define LOWER_LIMIT 2000
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string curse, spl, trg;
	object target;
	int chance;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail(" ����һ��������û����ɣ������½�ͷ��\n");

	if( environment(me)->query("no_magic") )
		return notify_fail("���ﲻ׼�½�ͷ��\n");
		
	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼�½�ͷ��\n");
		
	if( environment(me)->query("no_curse") )
		return notify_fail("���ﲻ׼�½�ͷ��\n");
		
//	if (me->query_temp("till_death/lockup")==1)
//    		return notify_fail(" ����Ѫ���������������ͣ�һʱ��Ȼ�²��˽�ͷ����\n");  

	if( !arg ) return notify_fail("ָ���ʽ��curse <��ͷ> [on <Ŀ��>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
                if(!objectp(target)) 
	 		return notify_fail(" ��Ľ�ͷҪ����˭���ϣ�\n");
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("����û�� " + trg + "��\n");
	} else {
		spl = arg;
		target = 0;
	}
	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
	spl = replace_string( spl, " ", "_");
	if( stringp(curse= me->query_skill_mapped("cursism")) ){
		if (me->is_fighting() && random(1000)<chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time())// ��ս���С�%2 chance of fail a perform
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"��ͷһ�ţ�¶���˺ô��һ������������\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\n����ͷһ�ţ�û�ó���������¶���˿��ţ�\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
		if ((int)SKILL_D(curse)->curse_curses(me, spl, target)) {
			if (userp(me) && ANNIE_D->check_buff(me,"forceshield")) {
        		if (me->query("force") > 300)
        			me->set("force", me->query("force") - 300);
        		else
        			me->set("force",0);
        	}
			me->force_status_msg("force");
			return 1;
		}
		return 0;
	}	
	return notify_fail("������ enable curseָ��ѡ����Ҫʹ�õĽ�ͷ����ϵ��\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	curse <��ͷ> [on <ʩ������>][0m
[0;1;37m����������������������������������������������������������������[0m   

ʩ��ͷ����Ҫָ��<��ͷ����>��<ʩ������>�򲢲������еĶ���Ҫ��

�����е��书�ɹ�Ϊ�Ĵ��ࣺ���ֱ��Ӧ��ʹ������Ϊ��
��1����ͳ�似�����������������ķ�������perform/exert��
��2�������������˹����µİ�ʶ��ͨ����(conjure)
��3) ���������������������������ѵĹ����������䣩��(cast)
��4����ͷ������������ȵ�ͨ�콵����ɽ��Ѫ���䣩����curse��

��ν��ͷ��ָ����cursism�����ϵ����⽵ͷ����������ȵ�ͨ�콵��

��ʹ��ĳһ����ͷ֮ǰ�������� enable ָ����ָ��Ҫʹ�õĽ�ͷϵ��
������Ҫʹ�õ����ȵ�ͨ�콵��celecurse���еġ�Ѫ������bloodcurse��
����Ҫ����
enable cursism celecurse
cast bloodcurse on xxxx

���ָ��: perform, exert , conjure, cast

[0;1;37m����������������������������������������������������������������[0m     
HELP
        );
        return 1;
}
