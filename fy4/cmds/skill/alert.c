// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit F_CLEAN_UP;
#define MAX_GUARD 1


int main(object me, string arg)
{
	object soldier,*enemy;
	string where;
	int strategy,leadership, exp, title , cost, sen, yue,hate;
	int duration, i,timer;
	
	if ((string)me->query("class") != "official")
		return notify_fail("�㲻�ǳ�͢���٣������Լ��չ��Լ��ɣ�\n");
	
	 if (userp(me))
     if (REWARD_D->check_m_success(me,"�ݺ�����") || me->query("family/master_id")=="master yue")
        	return notify_fail("�۳ҽ������Ķ����д��ڸ��ֱ�������\n");
	
	if (ANNIE_D->check_buff(me,"lockfield") >= 1)
	{
		tell_object(me,YEL"���ſ���Х��ȴͻȻ���ַ�����һ��������\n"NOR);
		return 0;
	}

	timer  = 6;
		
	strategy = (int)me->query_skill("strategy",1);
	leadership = (int)me->query_skill("leadership",1);
	if(strategy < 25 || leadership < 25)
		return notify_fail("Х��������Ҫ25��������25������֮��!\n");	
	
	if( !me->is_fighting() )
    	return notify_fail("����û����Ҫɱ�㣡\n");
		
	duration = me->query("timer/pfm/alert")-time() + timer;
    if (duration >0)
		return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration)+"�������Ҳ����ٴ�Х����\n");
	        	
	if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("�������ڵĹ�λ�����Ѿ��ܵ��㹻�ı�����\n");
		
	//	high cost for alert.	
	cost = me->query("max_sen")/5;
	cost = (cost> 800)? 800 : cost;
	if ( me->query("sen") < cost)
		return notify_fail("��Ҫ" + cost + "������\n");
	me->receive_damage("sen",cost);
   
    me -> set("timer/pfm/alert",time());
    
    if (random(leadership+strategy)< 13 && leadership + strategy <=260) {
       	message_vision(HIB "\n$N����һ����Х��Ԯ������ʲ��Ҳû�з�����\n" NOR, me);   
		return 1;
	}  	
    	
	if (leadership + strategy >260 && random(100)<5)  
		message_vision(HIB "\n$N����һ����Х��Ԯ������ʲ��Ҳû�з�����\n" NOR, me); 
	else {
		seteuid(getuid());
		soldier= new("/obj/npc/danei_guard");
		message_vision(HIB "\n$N����һ����Х��Ԯ��\n" NOR, me);   
        soldier->set("possessed", me);
        soldier->set_leader(me);
      	    
        title = leadership+ strategy;
        	
        if (title < 200)
			soldier->set_name("���ڸ���",({ "bodyguard" }));
		else if (title < 300)
			soldier->set_name(HIY"��ǰ����"NOR,({ "bodyguard" }));
		else 
			soldier->set_name(HIR"������"NOR,({ "bodyguard" }));

        me->add_temp("max_guard",1);			
		soldier->move(environment(me));	
		soldier->invocation(me, (leadership+strategy));

		if (soldier) {
	       	message_vision(HIB "\n$NӦ��������\n" NOR, soldier);
	       	message_vision("$N�ȵ����󵨣����Һͳ�͢���ٹ���ȥ��\n" NOR,soldier);
	       	enemy = me->query_enemy();
		    if (enemy)
	    	for (i=0;i<sizeof(enemy);i++)
	    	{
	       		hate = enemy[i]->query_hate(me);
	       		enemy[i]->add_hate(soldier, hate);     	
	    	}
	       	me->remove_all_killer();
	       	
	    }
	}
		
	return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ��alert[0m
[0;1;37m����������������������������������������������������������������[0m
�ٸ�����ָ����ָ���ù�Ա���������������Լ���
�ܷ��к������֣���������ˮƽ�ĸߵ�ȡ���ڹ�Ա����֮���ͱ����ĵȼ��ߵ͡�

�ٸ�����Х��������25��������25������֮����
�ٻ������ĸ��ֱַ�Ϊ��
���� + ����֮���� 200��	���ڸ���
���� + ����֮���� 300��	��ǰ����
���� + ����֮���� 450��	������	

ע�⣺������������͢�˲ŵ��㣬Х��/��Ԯ�ܹ��ٵ��ĸ�������һ�����ơ�
	�ٸ�����ÿ6�����Х��һ�Σ����ֻ��ͬʱ���������֡�
	�����ɺ�����Х����

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
