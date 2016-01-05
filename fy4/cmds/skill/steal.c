// steal.c


#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string what, who;
        object ob, victim, guard;
        int sp, dp;

	if(me->query_skill("stealing",1) < 25 )
		return notify_fail("����������Ҫ�����������ֿտ�֮����\n");

        if( environment(me)->query("no_fight"))
                return notify_fail("�����ֹ���ԡ�\n");
                
	if (guard=present("police",environment(me))) {
		message_vision(guard->query("name")+"��$N˵�������������ʲô��\n",me);
		return 1;
	}
	
	if (me->is_fighting() || me->is_busy())
		return notify_fail("��������æ���Ȼ�������ְɡ�\n");
		
	if( me->query_temp("stealing") )
    	return notify_fail("���Ѿ����һ��������ˣ�\n");

        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
                notify_fail("ָ���ʽ��steal <��Ʒ> from <����>\n");

        victim = present(who, environment(me));
        if( !victim || victim==me) return 
		notify_fail("�������ԵĶ��������\n");
	if( !victim->is_character())
		return notify_fail("����ã������������������������������\n");
	if (victim->is_corpse())
		return notify_fail("����͵�ˣ�ֱ���þ��С�\n");
	if( !wizardp(me) && wizardp(victim) )
                return notify_fail("��Ҳ���͵�������ϵĶ�����\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, victim)) {
		if (stringp(victim->query("NO_KILL")))
			return notify_fail(victim->query("NO_KILL"));
		if (stringp(victim->query("NO_PK")))
			return notify_fail(victim->query("NO_PK"));	
		else 
			return notify_fail("���޷�͵�������ϵĶ�����\n");
	}
		
        if( !ob = present(what, victim) ) {
                object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail(victim->name() + "���Ͽ�����û��ʲ��ֵǮ�Ķ�����͵��\n");
                ob = inv[random(sizeof(inv))];
        }
        
        sp = (me->query_skill("stealing") + me->query_kar())*100/360;
        	if( sp < 1 ) sp = 1;
        	if (sp > 100) sp=100;
        	if( me->is_fighting() ) {
                	sp /= 2;
                	me->start_busy(3);
        	}
        
        dp = (victim->query("sen")+ ob->weight()/10)*100/(me->query("sen")+1);
        	if (dp<100) dp = 100;
                if( victim->is_fighting() ) dp *= 3;
        	if( ob->query("equipped") ) dp *= 5;

        write("�㲻����ɫ����������" + victim->name() + "���ȴ���������\n����\n\n");
		if (wizardp(me)) tell_object(me,"sp="+(string)(sp)+", dp="+(string)(dp)+"\n");
        me->set_temp("stealing", 1);
        call_out( "compelete_steal", 3, me, victim, ob, sp, dp);
        return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
  
    	if (!me)	return;
    	
    	me->delete_temp("stealing");

//		if (me->query("class")!= "beggar") 
//			me->add("score",-1);
	
		if(!victim) {
        	tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ������ˡ�\n");
            return;
        }
        
        if (!ob) {
        	tell_object(me, "̫��ϧ�ˣ�����͵�Ķ����Ѿ���ʧ�ˡ�\n");
            return;
        }
        
        if (environment(ob)!= victim) {
        	tell_object(me,"���ˣ����������Ѿ����ڴ��������ˡ�\n");
        	return;
        }
        	
        
        if(environment(victim) != environment(me) ) {
            tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
            return;
        }
        
		if((int)ob->query("no_get")||(int)ob->query("lore")) {
			tell_object(me,"���ƺ�������ʲô������û���ͳ�����\n");
			return;
		}
        
        if( victim->query_temp("is_unconcious") || (random(sp+dp) > dp) ) {
                if( !ob->move(me) ) {
        	        tell_object(me, sprintf("������һ%s%s�����Ƕ������̫���ˣ����ò�������\n",ob->query("unit"),ob->name()));
                    return;
                }
                tell_object(me, HIW "�����ˣ�\n\n" NOR);
                tell_object(me, sprintf("��ɹ���͵��һ%s%s��\n",ob->query("unit"),ob->name()));
                if( living(victim) )
                if( random(sp) < dp/4 )
                        message("vision", sprintf("�㿴��%s�������ش�%s����͵����һ%s%s��\n",
                        			 me->name(),victim->name(),ob->query("unit"),ob->name()),
                        	environment(me), ({ me, victim }) );
                return;
        } else if( random(sp) > dp/4 ) {
                        tell_object(me, victim->name() + "�������һתͷ���㼱æ�������˻�ȥ��\n���ã�û�б����֡�\n");
                        return;
        } 
        tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
        message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�" + ob->name() + "��\n\n"+ "$N�ȵ�������ʲ�ᣡ��\n\n", victim, me);

        if( userp(victim)) 
        	victim->fight_ob(me);
        else 
        	victim->kill_ob(me);
        
        me->fight_ob(victim);
                        
        me->perform_busy(5 - me->query_skill("stealing",1)/100);
	                         
//        me->add("thief", 1);
}



int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	steal <ĳ��> from <ĳ��>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ�������л���͵���������ϵĶ������ɹ���, ��Ȼ����ܻ��
������Ʒ������, ����ʧ��, ������ʧ���ʱ��, ����ʧ��ʱ��Ȼ��
�ø�������, �ܺ��߶���л���Ҳ��������һ�棬�������˿ɾͲ�
�������ˡ�������


[0;1;37m����������������������������������������������������������������[0m   

HELP
    );
    return 1;
}
 
