// cast.c

#include <ansi.h>
#include <skill.h>
#define LOWER_LIMIT 2000
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	string spells, spl, trg;
    	object target;
 		int chance;
 		   
    	seteuid(getuid());
    
    	if( me->is_busy() )
        	return notify_fail("( ����һ��������û����ɣ����������ġ�)\n");
    
    	if( environment(me)->query("no_magic") || environment(me)->query("no_fight"))
        	return notify_fail("���ﲻ׼�����ġ�\n");
    	
    	if( !arg ) return notify_fail("ָ���ʽ��cast <����> [on <Ŀ��>]\n");
    	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
        	target = present(trg, environment(me));
        	if(!objectp(target)) 
            		return notify_fail(" �������Ҫ����˭���ϣ�\n");
		if( !target ) target = present(trg, me);
        	if( !target ) 
        		return notify_fail("����û�� " + trg + "��\n");
    	} else {
        	spl = arg;
        	target = 0;
    	}

    	spl = replace_string( spl, " ", "_");
		chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
    	if( stringp(spells = me->query_skill_mapped("spells")) ){
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
//        	return (int)SKILL_D(spells)->cast_spell(me, spl, target);
			if ((int)SKILL_D(spells)->cast_spell(me, spl, target)) {
				
				if (userp(me) && ANNIE_D->check_buff(me,"forceshield")) {
	        		if (me->query("force") > 300)
	        			me->set("force", me->query("force") - 300);
	        		else
	        			me->set("force",0);
	        		me->force_status_msg("force");
	        	} 
	        					
				me->force_status_msg("mana");
				return 1;
			}
			return 0;
    	}
    	return notify_fail("�������� enable spells ָ��ѡ����Ҫʹ�õ�����ϵ��\n");
}

int help (object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	cast <��������> [on <ʩ�����>][0m
[0;1;37m����������������������������������������������������������������[0m   

ʩ������Ҫָ��<��������>��<ʩ�����>�򲢲������еĶ���Ҫ��

�����е��书�ɹ�Ϊ�Ĵ��ࣺ���ֱ��Ӧ��ʹ������Ϊ��
��1����ͳ�似�����������������ķ�������perform/exert��
��2�������������˹����µİ�ʶ��ͨ����(conjure)
��3) ���������������������������ѵĹ����������䣩��(cast)
��4����ͷ������������ȵ�ͨ�콵����ɽ��Ѫ���䣩����curse��

��ν������ָ����Spells�����ϵ��������������������������� 
(necromancy) �ʹ��ѵĹ����������䣨kwan-yin-spells����

��ʹ��ĳһ������֮ǰ�������� enable ָ����ָ��Ҫʹ�õķ���ϵ��
������Ҫʹ������ġ�����֮������drainerbolt��������Ҫ����
enable spells necromancy��Ȼ����ս����ʹ��
cast drainerbolt on xxxx

��ս����ʹ�����⼼����2%�Ŀ��ܻ�ʧ�ܣ�����Լ�æ�ң���ϰĳЩ
�ض����书���Խ��ʹ˸��ʡ�

ע����ͬ������ϵ�������಻ͬ���������ʱת���Լ�������ϵ��
	������ķ�������ʱ���㡣

���ָ��: perform, exert , curse, conjure

[0;1;37m����������������������������������������������������������������[0m    
HELP
        );
    return 1;
}
