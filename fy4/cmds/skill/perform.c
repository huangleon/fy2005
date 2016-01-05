/*	Modifications
		
	-- 7/22/2004 by Silencer
		** ����perform������Ҫ����50��������L51��������ѡ�	
*/

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	object weapon;
    	string martial, skill;
    	string *skill_list = ({ "axe","blade","dagger","fork","hammer","parry","staff",
    				"sword","throwing","spear","unarmed","whip","musket"});
   		int force, mylevel, force2;
 	    string *freepass = ({ "chunxin","hengxie","jingpo", "juesha", "qianhuan", 
 	    					"yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"});       
    	string *freeforce = ({ "chunxin","hengxie","jingpo", "juesha", "qianhuan" });
//		string *freepass = ({});
//		string *freeforce = ({});
    	int chance;
    	
    	seteuid(getuid());
		
		
    	if( environment(me)->query("no_fight"))
		return notify_fail("�����޷�ʹ��������ʽ��\n");
    	if( me->is_busy() )
        	return notify_fail("������һ��������û����ɣ�����ʩ��������ʽ���� \n");
        
    	if( !arg ) 
    		return notify_fail("��Ҫʹ����һ��������ʽ��\n");

    	if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
	        if( weapon = me->query_temp("weapon") )
	            	martial = weapon->query("skill_type");
	        else if( weapon = me->query_temp("secondary_weapon"))
	            	martial = weapon->query("skill_type");
	        else
	            	martial = "unarmed";
    	} 
    	else{
			if( member_array(martial,skill_list) != -1)
            		return notify_fail("����������ʽ����ָ���书���࣡\n");
        	if( martial == "move")
        		return notify_fail("����������ʽӦ��ʹ��������(dodge)���⹦��\n");    
    	}
    	
    	mylevel = F_LEVEL->get_level(me->query("combat_exp"));
    	force = me->query("force");
    	if (userp(me) && mylevel > 50 && force < 50)
    		return notify_fail("ʹ��������ʽ������Ҫ50���������\n");	
    	
    	if( userp(me) && ANNIE_D->check_buff(me,"forceshield") && force < 300)
    		return notify_fail("�����л������书ʱʹ��������ʽ������Ҫ300���������\n");	
    		
    	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
    	
    	if( stringp(skill = me->query_skill_mapped(martial)) ) {
	        if (me->is_fighting() && random(1000) < chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time()
        		&& member_array(arg,freepass)== -1 )// ��ս���С�%2 chance of fail a perform
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"һ�в�����¶���˺ô��һ������������\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\n������������û�ó����з���¶���˿��ţ�\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
	        	
	        if( SKILL_D(skill)->perform_action(me, arg) ) {	        	       	
				if (userp(me) && member_array(arg,freeforce)== -1 && me->query_temp("pfm/free_perform")<1) {
					if (mylevel>50)
		        	{	  		
		        		force2 = me->query("force");
		        		if( ANNIE_D->check_buff(me,"forceshield")) {
		        			if (force - force2 < 300)
		        				me->set("force", force - 300);
		        		} else
		        		{		        			
		        			if (force - force2 < 50)
		        				me->set("force",force-50);
		        		}		        	
		        	}
	        	}
	        	// Give a mark for zeor force perform
	        	if (me->query_temp("pfm/free_perform")>0) {
					me->add_temp("pfm/free_perform",-1);
					if (me->query_temp("pfm/free_perform")<1)
						me->delete_temp("pfm/free_perform");
				}
	        	me->force_status_msg("force");
	            return 1;
	        
	        } else 
	        	return 0;
    	}
    	return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦��\n");
}



int help (object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	perform [<�书����>]<��ʽ����> [<ʩ�ö���>][0m
[0;1;37m����������������������������������������������������������������[0m   

�����е��书�ɹ�Ϊ�Ĵ��ࣺ���ֱ��Ӧ��ʹ������Ϊ��
��1����ͳ�似�����������������ķ�������perform/exert��
��2�������������˹����µİ�ʶ��ͨ����(conjure)
��3) ���������������������������ѵĹ����������䣩��(cast)
��4����ͷ������������ȵ�ͨ�콵����ɽ��Ѫ���䣩����curse��

��ν��ͳ�似��ָȭ�š������������ȣ���Щ����ͨ����һЩ��
��Ĺ�����ʽ�����������ָ����ʹ�á�

���� enable ָ��ָ������ʹ�õ��书������˵
	enable sword diesword �󣬾���ʹ������ʽ���ʵ����衱
	perform caidiekuangwu

�����ȭ�Ÿ��������ܵ��书����ָ�����õĻ����书������
	perform iron-cloth.daoqiangburu
	perform dodge.yexuechuji
	perform herb.canyunbi

��ȭ�Ź�����߱������������ʡ�Ե������书��һ�����
	perform duangechangmeng
	perform tianxiawugou

��ͨ������£����ж������ʱ�����������ʽ�����ƶ����֣�
����˵������ oldman, waiter, badguy ��������ɱ��
ʹ��
	perform dodge.luoyeqiufeng waiter
�Ϳ��Խ�����Ҷ��硱���ؼ�ʹ�õ�waiter�ϡ�	

��ս����ʹ�����⼼����2%�Ŀ��ܻ�ʧ�ܣ�����Լ�æ�ң���ϰĳЩ
�ض����书���Խ��ʹ˸��ʡ�

ʹ��һ��������ʽ������Ҫ����50��������
���ȼ�51���¿���ȥ��Ҫ��

ע:
	�������е��书��Ҫ���˻���˲���ʹ�������ʽΪ��
perform [<�书����>]<��ʽ����> [<ʩ�ö���>] with ͬ������

����˵�����ֵ����ĵ�������ʹ�õĸ�ʽΪ��

perform yipianlianxin �������� with ͬ������
perform yipianlianxin with ͬ������

ͬ����ѩ�ĵ������Σ���ʹ�õĸ�ʽΪ��

perform daojianruomeng �������� with ͬ������
perform daojianruomeng with ͬ������

[0;1;37m����������������������������������������������������������������[0m   
HELP
        );
    return 1;
}
 
