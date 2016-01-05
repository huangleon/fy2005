// exert.c

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	string force;
    	int result, amount, pass,chance;
    	string arg1;
    	
    	seteuid(getuid());
    
    	if( environment(me)->query("no_magic")||environment(me)->query("no_fight") )
        	return notify_fail("�㲻�������������ڹ���\n");
    	if( me->is_busy() )
        	return notify_fail("����һ��������û����ɣ�����ʩ���ڹ���\n"); 
    	if( !arg ) return notify_fail("��Ҫ���ڹ���ʲ�᣿\n");
    
    	if( stringp(force = me->query_skill_mapped("force")) )
    	{
        	notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");
        	
        	if (sscanf(arg,"%s %d", arg1, amount)== 2) {
        		if (arg1 == "qi" || arg1 == "shen" || arg1 == "jing")
        			pass = 1;
        	} else if (sscanf(arg,"%s",arg1)==1) {
        		if (arg1 == "qi" || arg1 == "shen" || arg1 == "jing")
        			pass = 1;
        	}
        	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;        	
        	if (me->is_fighting() && random(1000) < chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time()
        		&& !pass )// ��ս���С�%2 chance of fail a perform, and let ppl exert recover
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"����һ��¶���˺ô��һ������������\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\n������һ��û�ó����з���¶���˿��ţ�\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
        	if( SKILL_D(force)->exert_function(me, arg) )        {
            	if (!me->is_fighting() && me->query_busy()<1)
            		me->start_busy(1);
            	me->force_status_msg("force");
            	return 1;
        	}
        	return 0;
    	}
    	return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��ڹ���\n");
}


int help (object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ��exert <��������> [<ʩ�ö���>] [<��������>] [0m
[0;1;37m����������������������������������������������������������������[0m
����������һЩ���칦�ܣ������Ҫָ��<��������>��<ʩ�ö���>�����
���ޡ�����ʹ��ĳһ���ڹ������칦��֮ǰ����������� enable ָ����
ָ����Ҫʹ�õ��ڹ����������ı��Լ����ڹ�����ԭ���������������
��ֱ��ת����ȥ�������0��ʼ����

�ڹ������⹦�ÿɼ������ɵľ�����ܡ�

���������ڹ������еĹ��ܣ�
	�ָ�������	������� ���
	�ָ�����	������� �����
	�ָ�������	������� �����
	�������ˣ�	������� ����� (��һ�����ڹ��޴˹��ܣ�
���������񣯾���ƽ���ָ�ֵ�� ����������Ч�ڹ��ȼ������������ķ�������������

��ս����ʹ�����⼼����2%�Ŀ��ܻ�ʧ�ܣ�����Լ�æ�ң���ϰĳЩ
�ض����书���Խ��ʹ˸��ʡ�

���ָ�
	�ָ�������	���������塡���
	�ָ�������	���������塡�����
	�ָ�������	���������塡�����
	
[0;1;37m����������������������������������������������������������������[0m
HELP
        );
    return 1;
}
