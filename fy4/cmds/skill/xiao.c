#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object wolf, *enemy;
	int summonwolf, exp, cost, hate, i, guard, duration, timer;
	        
    if ((string)me->query("class") != "wolfmount")
		return notify_fail("ֻ����ɽ���Ӳſ�����������\n");
        
    summonwolf = (int)me->query_skill("summonwolf",1);
	if(summonwolf < 20 )
    		return notify_fail("����������Ҫ20���Ļ���֮����\n");   
        
    timer = 40;
	duration = me->query("timer/alert")-time() + timer - F_ABILITY->check_ability(me,"xiao_add");
    if ( duration >0)
		return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration)+"�������Ҳ����ٴλ��ǣ�\n");
		
    if (me->is_busy() )
        	return notify_fail("��������æ���޷���������\n");
    
    if(!me->is_fighting() )
        	return notify_fail("����û����Ҫɱ�㣡\n");
        	
	if (ANNIE_D->check_buff(me,"lockfield") >= 1)
	{
		tell_object(me,YEL"���ſ���Х��ȴͻȻ���ַ�����һ��������\n"NOR);
		return 0;
	}
			
	if(me->query_temp("max_guard"))
        return notify_fail("���������Ѿ���������ˡ�\n");
             
	if (summonwolf<100)	cost = 80;
		else	cost = 80 + (summonwolf-80)/3;		
	if(me->query("sen")< cost ||me->query("gin") < cost)
		return notify_fail("��ľ���״��̫���ˣ������޷���Ч����������\n");
	me->receive_damage("sen",cost);
	me->receive_damage("gin",cost);
	
	if (summonwolf > 200)	summonwolf = 200;	// capped
		
	seteuid(getuid());
	wolf= new("/obj/npc/wolf");
	me->add_temp("max_guard",1);
	wolf->move(environment(me));
    wolf->invocation(me, (summonwolf));
    wolf->set("possessed", me);

	if (summonwolf<50)
		wolf->set_name("��ë����",({ "wolf" }));
	else if (summonwolf<75)
		wolf->set_name(WHT"��ë����"NOR,({ "wolf" }));
	else if (summonwolf<100)
    	wolf->set_name(YEL"��ë����"NOR,({ "wolf" }));
	else if (summonwolf<150)
        wolf->set_name(RED"��ë����"NOR,({ "wolf" }));
	else if (summonwolf<200)
		wolf->set_name(HIW"��ë����"NOR,({ "wolf" }));
    else if (summonwolf<250)
     	wolf->set_name(HIR"��ë����"NOR,({ "wolf" }));
	else 
		wolf->set_name(HIY"��ë����"NOR,({ "wolf" }));

    me->set("timer/alert",time());
                
    if (wolf)
    {       
	    enemy = me->query_enemy();
	    if (enemy)
	    for (i=0;i<sizeof(enemy);i++)
	    {
	       	hate = enemy[i]->query_hate(me);
	       	enemy[i]->add_hate(wolf, summonwolf + hate);     	
	    }   	
       	message_vision(HIB "\n$N�����Ǻ����ء�໡������ء�໡�����ʱ��ɽ��ҰȺ��������\n" NOR, me);	
    	message_vision( "\n\n$N��ݺݵ�����������\n" , wolf);
    }
	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	ָ���ʽ��xiao[0m
[0;1;37m����������������������������������������������������������������[0m   

ָ���ʽ��xiao
 
��ɽ����ÿ��ʮ���غϿɻ�����ת�Ƶ���ע������������Ҫ20����������
�������ǳ��ֺ󽫾��б������Ըߵ�����ֵ�������˲���ս��10���غϺ�
��ʧ�������ǵ�ǿ��ȡ���ڻ���֮���ļ����ǵ��������������ƣ�����
Ѫ�ϲ���ǲ���������æ��ʱ���У�ͬʱ������һ��������;�����

[0;1;37m����������������������������������������������������������������[0m    
HELP
    );
    return 1;
}
