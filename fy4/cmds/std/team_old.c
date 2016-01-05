// team.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
		object *t,*t1, *players;
		int i, me_exp, ob_exp, num, num1, n, max_exp;
	


//		First remove those 1-man bogus team, mostly due to unclean code.
		if (sizeof(me->query_team())<2) 	me->dismiss_team();

//		�����б�
	
		if( !arg ) {
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"�����ڲ�û�вμ��κζ��顣\n"NOR);
			write(WHT"��ġ�"+ me->query_temp("team_name") + "���еĳ�Ա�У�\n  "NOR + implode(t->name(1), "\n  ") + "��\n"NOR);
			return 1;
		}

//		��ɢ������������
		if( arg=="dismiss" ) {
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"�����ڲ�û�вμ��κζ��顣\n"NOR);
			if( me->is_team_leader() ) {
				message("team", WHT""+me->name(1) + "�������ɢ�ˡ�\n"NOR, t, me);
				write(WHT"�㽫�����ɢ�ˡ�\n"NOR);
			} else {
				message("team", WHT""+me->name(1) + "����������顣\n"NOR, t, me);
				write(WHT"����������Ķ��顣\n"NOR);
			}
			me->dismiss_team();
			return 1;
		}

//		����������
		if (sscanf (arg, "name %s", arg) == 1) {
			if (!me->is_team_leader())
				return notify_fail(WHT"ֻ������˲��ܹ������������ơ�\n");
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"�����ڲ�û�вμ��κζ��顣\n"NOR);
			if (sizeof(arg)>14)
				return notify_fail(WHT"������Ϊ�����֡�\n"NOR);
			
			if (userp(me) && me->query_temp("timer/team_name") + 4 > time())
				return notify_fail(WHT"�����ű��̫Ƶ���ˣ���һ���Ӱɡ�\n"NOR);
			players = filter_array(livings(), (: userp($1):));
			num = sizeof(players);
			while (num--)
				if (players[num]->query_temp("team_name") == arg)
					return notify_fail("�������Ѿ�������ʹ���ˡ�\n");
			me->set_temp("timer/team_name",time());
			for(i=0; i<sizeof(t); i++) {
				t[i]->set_temp("team_name",arg);
				tell_object(t[i],YEL"��Ķ�����Ÿ�Ϊ��"+arg+YEL"����\n"NOR);
			}			
			return 1;
		
		}			
		


//		����������ĳһ��	
		if(sscanf(arg, "dismiss %s", arg) == 1) {
			object ob;
			ob = find_player(arg);
			if(!ob || !me->visible(ob)){
				return notify_fail(WHT"û�������....��\n"NOR);
			}
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"�����ڲ�û�вμ��κζ��顣\n"NOR);
			if( !me->is_team_leader() ) {
				return notify_fail(WHT"�㲻������ˡ�\n"NOR);
			} else if ( me->is_team_leader() && me==ob) {
				return notify_fail(WHT"��ɢ����ֱ��ʹ��team dismiss����������ָ��������ӣ�team promote��\n"NOR); 
			} else { 
				for(i=0; i<sizeof(t); i++) {
					if(t[i]->name() == ob->name()){
						if (me==ob) {
							message("team", WHT""+me->name(1) + "�������ɢ�ˡ�\n"NOR, t, me);
							write(WHT"�㽫�����ɢ�ˡ�\n"NOR);
						} else {
							message("team", WHT""+me->name(1) + "������" + ob->name()+ "�߳����顣\n"NOR, t, me);
							write(WHT"�������" + ob->name() + "�߳����顣\n"NOR);
							tell_object(ob,WHT"�㱻��Ķ��鿪����\n"NOR);
						}
						ob->dismiss_team();
						return 1;
					}
				} 
				return notify_fail(WHT""+ob->name() + "������Ķ����С�\n"NOR);
			}
			return 1;
		}

//		ת������

		if (sscanf(arg,"promote %s", arg) == 1) {
			object ob, bb;
			ob = find_player(arg);
			if(!ob || !me->visible(ob)){
				return notify_fail(WHT"û�������....��\n"NOR);
			}
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"�����ڲ�û�вμ��κζ��顣\n"NOR);
			if( !me->is_team_leader() ) {
				return notify_fail(WHT"�㲻������ˣ��޷�ת����ӡ�\n"NOR);
			}  else if ( me == ob) {
				return notify_fail(WHT"���Ѿ���������ˡ�\n"NOR);
			} else if (me->team_member(ob)){ 
				me->switch_team_member(me,ob);
				me->tell_team(me,WHT""+ me->name(1) + "�����Ȩ������" + ob->name(1)+"��\n"NOR);	
				return 1;
			}	
			return notify_fail(WHT""+ob->name() + "������Ķ����С�\n"NOR);
		}

//		������ӡ�

		if( sscanf(arg, "with %s", arg)==1 ) {
			object ob;
			if( !(ob = present(arg, environment(me)))
				||	!living(ob)
				||	!ob->is_character()
				||	ob==me )
					return notify_fail(WHT"�����˭��Ϊⷰ飿\n"NOR);
		
			if (sizeof(ob->query_team())<2) 	ob->dismiss_team();
			
		//	(1) ����Ƿ�Ϸ� 	
			if( ob->query("quest"))
				return notify_fail(WHT"�Է�����û��ɵ����񣬲�����ӣ�\n"NOR);
			
			ob_exp = ob->query("combat_exp");
			me_exp = me->query("combat_exp");
			n = 3;
			
			if (pointerp(t=me->query_team())) {
			// If Me is in a team
				if (!me->is_team_leader())
					return notify_fail(WHT"ֻ�ж����������������˼��롣\n"NOR);
				else if (sizeof(me->query_team())>5)
					return notify_fail(WHT"��������������ˡ�\n"NOR);
				else {
					num= sizeof(t);
					max_exp = 0;
					while(num--) {
						if (t[num]->query("combat_exp")> max_exp)
							max_exp = t[num]->query("combat_exp");
					}
					num= sizeof(t);
					while (num--) {
						if (t[num]->query("quest") && max_exp < ob_exp)
							return notify_fail(WHT"�����е�������ڼ����߾��飬��Ҫ���������\n"NOR);
						if (n*t[num]->query("combat_exp")<ob_exp 
							|| t[num]->query("combat_exp")+ 2000000< ob_exp)
							return notify_fail(WHT"��Ӿ��鷶Χ���̫��\n"NOR);
						if (t[num]->query("combat_exp")>n*ob_exp 
							|| t[num]->query("combat_exp")> ob_exp+ 2000000)
							return notify_fail(WHT"��Ӿ��鷶Χ���̫��\n"NOR);	
						
					}
				}
			} else {	// Or I am not in a team	
				if( me->query("quest"))
					return notify_fail(WHT"�㻹��û��ɵ����񣬲�����ӣ�\n"NOR);
				if (n * me_exp<ob_exp || me_exp + 2000000< ob_exp)
					return notify_fail(WHT"��Ӿ��鷶Χ���̫��\n"NOR);
				if (me_exp>n * ob_exp || me_exp > ob_exp + 2000000)
					return notify_fail(WHT"��Ӿ��鷶Χ���̫��\n"NOR);	
			}
	
		//	A����B������֤ʵA������飬�Լ�B�����ǺϷ��ģ����ǲ����B�Ķ��顣
				
		//	��B�ٴ�����team with ʱ��A/B�Լ�B�Ķ�����ٴ�ͨ��������飬
		//	����A�Ķ��飬�Լ�B�Ƿ�������������п������б䶯���������渴�顣	
		
			if( !pointerp(me->query_team()) || me->is_team_leader() ) {
				if( me==(object)ob->query_temp("pending/team") ) {
					//	���A�����Ƿ�Ϸ����Ƕ��������Ѿ�����������ˡ�
					if (pointerp(t1=ob->query_team())) {
						// If Ob is in a team
						if (me->query_team())
							return notify_fail(WHT"���Ѿ���ĳ���������ˡ�\n"NOR);				
						if (!ob->is_team_leader())
							return notify_fail(WHT"ֻ�ж����������������˼��롣\n"NOR);
						else {
							num= sizeof(t1);
							max_exp = 0;
							while(num--) {
								if (t1[num]->query("combat_exp")> max_exp)
									max_exp = t1[num]->query("combat_exp");
							}
							num= sizeof(t1);
							while (num--) {
								if (t1[num]->query("quest") && max_exp < me->query("combat_exp"))
									return notify_fail(WHT"�Է������е����������ľ���ֵ����ʱ���ܼ��롣\n"NOR);
							if (n*t1[num]->query("combat_exp")<me_exp 
								|| t1[num]->query("combat_exp")+ 2000000< me_exp)
								return notify_fail(WHT"��Ӿ��鷶Χ���̫��\n"NOR);
							if (t1[num]->query("combat_exp")>n*me_exp 
								|| t1[num]->query("combat_exp")> me_exp+ 2000000)
								return notify_fail(WHT"��Ӿ��鷶Χ���̫��\n"NOR);	
							}
						}
					} 								
					if( !pointerp(me->query_team()) ) {
						ob->add_team_member(me);
						message_vision(WHT"$N��������$n�ġ�"+me->query_temp("team_name")+"����\n"NOR, me, ob);
					} else {
						me->add_team_member(ob);
						message_vision(WHT"$N������$n������顣\n"NOR, me, ob);
						tell_object(ob,YEL"��Ķ��������"+ me->query_temp("team_name")+"��\n");
					}
					ob->delete_temp("pending/team");
					return 1;
				} else {
					if(pointerp(ob->query_team())) {	//���B�Ƿ����ж��顣
						if (sizeof(me->query_team())<2)
							return notify_fail(ob->name()+"�Ѿ����ڱ�Ķ����ˣ������������˰ɡ�\n");
						if (member_array(ob, me->query_team())== -1)
							return notify_fail(ob->name()+"�Ѿ����ڱ�Ķ����ˣ������������˰ɡ�\n");
						else
							return notify_fail(ob->name()+"�Ѿ�����Ķ������ˡ�\n");
					}
					message_vision(WHT"$N����$n����$P�Ķ��顣\n"NOR, me, ob);
					tell_object(ob, YEL "�����Ը����룬���� team with " + me->query("id") + "��\n" NOR);
					me->set_temp("pending/team", ob);
					return 1;
				}
			} else
				return notify_fail(WHT"ֻ�ж����������������˼��롣\n"NOR);
		}
        
	
		if( sscanf(arg, "talk %s", arg)==1 )   {
			t= me->query_team();
	        if( !pointerp(t) )
	           	return notify_fail("�����ڲ�û�кͱ�����ɶ��顣\n");
			for(i=0; i<sizeof(t) ; i++)
				if (!objectp(t[i])) return notify_fail("����Ҫ������϶��顣\n");
			t -= ({ 0 });
			if (sizeof(t)==1)
				return notify_fail("��Ķ�����ֻ�����Լ��ˡ�\n");	
	        return CHANNEL_D->do_channel(me, "teamtalk", arg);
		}

	/*
	if( sscanf(arg, "form %s", arg)==1 ) {
		if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
			return notify_fail("�������һ����������������֯���Ρ�\n");
		if( !me->query_skill(arg, 1) )
			return notify_fail("����������ûѧ����\n");
		return SKILL_D(arg)->form_array(me);
	}*/
}





int help(object me)
{
	write(@HELP

[0;1;37m����������������������������������������������������������������[0m
����ָ��ʹ�÷���:

team with <ĳ��> - ��ĳ����ɶ���. ����Ҫ˫����ͬ�����Ż���Ч��
team name <ĳ��> - ������ӿɸ��Ĵ˶������š�
team dismiss     - �뿪����. ���´�ָ��������, ������������ɢ��
team dismiss <ĳ��> - �������ӿ�����ʱ���������е�ĳ�ˡ�
team promote <ĳ��> - �������ӿ��԰����ת�ø������е�ĳ��
team talk <ѶϢ> - ����������������̸��, ������ tt <ѶϢ> �����

ֱ���� team ָ��ʱ�����ʾ��Ŀǰ�Ƿ��м�����鼰��Ա������

ע: team �� follow �Ƕ����ģ��㲻һ��Ҫ follow ��������䡣

ע�����ʱ����ֵ�������̫���¼����߲�������������
	�����������߾���ֵ�����¼����ߣ��������Ҳ����������
	
[0;1;37m����������������������������������������������������������������[0m  

HELP
	);
	return 1;
}
