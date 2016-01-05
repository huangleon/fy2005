// quest.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
	
#include <ansi.h>
inherit F_CLEAN_UP;
string time_period(int timep);

int main(object ob, string arg) {
	
	int i, time, nowtime, newbie;
	object me;
	object* mem;
	mapping quest;
	string msg,n_msg;

// NEWBIE QUEST INFORMATION

	newbie = REWARD_D->riddle_check(ob,"��������");
	
	switch (newbie) {
		case 1: if (!ob->query_temp("marks/newbie_quest")) 
					n_msg = "
�����ڵ������ǣ������Ƹ󣨷��ƹ㳡���ϣ�ȥ��������ˣ��������������֪��
����㳡���Ķ������Ƴǵ������ľ����ˡ�\n";
				else			
					n_msg = "
�����ڵ������ǣ����������ȥ���䵱����ʯ���ʸ��ã������ƶ����ŵ����·���ϣ�
�����䵱ɽ�����ҵ��������ӷ������³�������ʮ�������а˲�����ɽ�������������ǣ�
�����ʯ����Ȼ���а��ţ����ˣ�����ʱ��Ƚ�æ����ûע�⵽�㣬��ȥ�ٽ������ͻ�
�������ˣ�\n";
				write(n_msg);
				return 1;
		case 2: if (!ob->query_temp("marks/newbie_quest")
					|| ob->query_skill("literate",1)>=1)
					n_msg = "
�����ڵ������ǣ����ط��Ƴ���������˽�����������\n";
				else
					n_msg= "
�����ڵ������ǣ������Ǽ��ڽֹ�Ժ���ʵ��Ƕ�ȥѧ�����д�֣�
��learn literate from kao guan with 1���������֪����ô�ߣ���������������
�ڵ�ͼ���ҹ�Ժ���ǡ�\n";
				write(n_msg);
				return 1;
		case 3: n_msg = "
�����ڵ������ǣ����������ȥ�ݼ�һ�¹�������±�������ף�������Դ����ϴӳ�����
�ߣ��ο�����𡡣��������еķ��Ƶ������ܣ������ߵ����Ƿ�����վ���紦����
����ԽɳĮ�������Ƕ�������ʾ��֪����������ʲô�ˣ�\n";
				write(n_msg);
				return 1;
		case 4: n_msg = "
�����ڵ������ǣ����ط��Ƴ���������˽����������������Դ�ӭ÷��ջ������
Ҳ���Դӳ�������·���Ǿ�ҪС�Ŀ�������𡡣��������з��Ƶ�����˵���ˡ�\n";
				write(n_msg);
				return 1;
	}		
		
// END Of Newbie QUest
	
	if(!arg || !wizardp(ob)) {
//	(1)	Player self-check
		me = this_player();
		mem = pointerp(me->query_team()) ? me->query_team() : ({ me });
		i = sizeof(mem);
		while(i--){
			if (mem[i]) {
		    	    if (mem[i] != me) {
		    	      	if(mapp(mem[i]->query("quest"))) {
		    	      		quest =  mem[i]->query("quest");
					if (quest["quest_type"] != "special") {
						msg = WHT"���� "+ mem[i]->name() + " ���ڵ�������: ��"+quest["quest_location"]
							+"ȥ"+ HIR + quest["quest_type"] + NOR WHT"��"NOR + quest["quest"] + NOR+ WHT "����";	
					}else
						msg = WHT"���� "+ mem[i]->name() + " ���ڵ�������: "NOR + quest["short"] + "��";															
					tell_object(me, msg);
					
					nowtime = time() - mem[i]->query("quest_time");
//					time = 	quest["duration"] >= 900 ? quest["duration"] : 900;
					time = 	quest["duration"] >= 1 ? quest["duration"] : 900;
					if( nowtime  < time ) {
						tell_object(me,"������" + time_period(time-nowtime) + "������������\n");
					} else 
	                			write(YEL"����"+ mem[i]->name() +"�Ѿ�û���㹻��ʱ����������ˡ�\n"NOR);
	                	}
		    	    }
			}
		}
	
	    	if(!me->query("quest")) {
		        if((me->query("next_time")) > time()) {
			    	return notify_fail(WHT"��Ҫ��" 
		                	+ time_period(me->query("next_time") - time()) 
		                	+ "֮��ſ�Ҫ����\n"NOR);
		        }
		        else {
		       		return notify_fail(NOR"������û���κ�����\n");            
		        }
	    	}
		
		if(mapp(me->query("quest"))) {
			quest =  me->query("quest");
	        if (quest["quest_type"] != "special") {
				msg = WHT"�����ڵ�������: ��"+quest["quest_location"]+"ȥ"+ HIR+ quest["quest_type"] + NOR WHT"��"NOR + quest["quest"] + NOR WHT"����";	
			}else
				msg = WHT"�����ڵ�������: " + quest["short"] + WHT"��";															              
			tell_object(me,msg);
			nowtime = (int)time() - me->query("quest_time");
//					time = 	quest["duration"] >= 900 ? quest["duration"] : 900;
					time = 	quest["duration"] >= 1 ? quest["duration"] : 900;
			if( nowtime  < time) {
				tell_object(me,"�������" + time_period(time-nowtime) + "������������\n"NOR);
			} else {
		                write("�������Ѿ�û���㹻��ʱ����������ˡ�\n"NOR);
		                me->set("quest", 0 );
		                me->delete("cont_quest");	// ȥ������QUest����
		                me->delete("annie_quest");
		                me->delete_temp("annie_quest");
		                me->delete_temp("luyu");
		                return notify_fail("��������Զ�ȡ���ˡ�\n");
			}
		} else if(!me->query("quest")) {
		        if((me->query("next_time")) > time()) {
			    return notify_fail(WHT"��Ҫ��" 
		                	+ time_period(me->query("next_time") - time()) 
		                	+ "֮��ſ�Ҫ����\n"NOR);
		        }
		        else {
		            	return notify_fail(NOR"������û���κ�����\n");            
		        }
	    	} else
	    		return notify_fail(HIR"���������֪ͨ��ʦ�쿴��\n"NOR);
		
	
	} 
// (2)	Wizard check Players' quests
	else {
	 	if(!(ob = present(arg, environment(ob))) && !(ob =  find_player(arg))) {
		return notify_fail("��Ҫ�쿴˭������\n");
		}
		if(!ob->query("quest")) {
                	return notify_fail(ob->name()+"����û���κ�����\n");
		}
		if(mapp(ob->query("quest"))) {
			quest =  ob->query("quest");
               		if (quest["quest_type"] != "special") {
				msg = WHT""+ob->name() + "���ڵ�������: ��"+quest["quest_location"]+"ȥ"+ quest["quest_type"] + "��"NOR + quest["quest"] + NOR WHT"����";	
			}else
				msg = WHT""+ob->name() + "���ڵ�������: " + quest["short"] + "��"NOR;	
                	write(msg);
		} 
	
		nowtime = (int)time() - ob->query("quest_time");
//					time = 	quest["duration"] >= 900 ? quest["duration"] : 900;
					time = 	quest["duration"] >= 1 ? quest["duration"] : 900;
		if( nowtime  < time) {
			write("������" + time_period(time-nowtime) + "������������\n"NOR);
		} else {
	                write(NOR"�����Ѿ�û���㹻��ʱ����������ˡ�\n"NOR);
		}
	}	
	return 1;
}

/*
int time_period(int timep, object me) {
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;             t /= 60;
	m = t % 60;             t /= 60;
	h = t % 24;             t /= 24;
	d = t;
	
	if(d) time = chinese_number(d) + "��";
	else time = "";
	
	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";
	tell_object(me,"������" + time + "����������\n");
	return 1;
}*/

string time_period(int timep) {
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;             t /= 60;
	m = t % 60;             t /= 60;
	h = t % 24;             t /= 24;
	d = t;
	
	if(d) time = chinese_number(d) + "��";
		else time = "";
	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";
	
	return time;
}



int help(object me) {
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 		�������[0m
[0;1;37m����������������������������������������������������������������[0m

���ָ�������ʾ�������Ķ��ѵ�ǰ������

[0;1;37m����������������������������������������������������������������[0m

HELP);
	return 1;
}
