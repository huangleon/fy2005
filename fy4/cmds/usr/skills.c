// skills.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 08/08/2001 by Daniel Q. Yu.
//			* Get name from skill itself.			
//
// 		- 9/22/2002 by Silencer
//			* Add -xxxx to enable single skill check.


#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_LEVEL;

string *skill_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "��ͨƤë" NOR,
	HIB "��������" NOR,
	HIB "������" NOR,
	HIB "�������" NOR,
	CYN "�������" NOR,
	CYN "����似" NOR,
	CYN "�����뻯" NOR,
	HIC "�Ƿ��켫" NOR,
	HIC "һ����ʦ" NOR,
	HIW "��ɲ�" NOR
});

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "�����ž�" NOR,
	HIB "��֪һ��" NOR,
	HIB "������" NOR,
	HIB "����С��" NOR,
	CYN "�������" NOR,
	CYN "��Ȼ���" NOR,
	CYN "��Ȼ��ͨ" NOR,
	HIC "������˫" NOR,
	HIC "������" NOR,
	HIW "��ɲ�" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob, *list, couple_ob;
	mapping skl, lrn, map;
	string *sname, *mapped,target,cardname,skill_name, permit, msg;
	int i, marry_flag, skill_level;
	mapping learned_skill_points;
	int estimate,cost, amount, total, j, my_skill,req_exp;
	string *att_skill = ({ "literate", "unarmed", "force", 
							"foreknowledge", "chanting", "move" });
	mapping exp_data;
							
	seteuid(getuid());

//	==> implemented to reduce flooding when player only needs to check a single skill level -- by silencer
	if (arg)
	if (sscanf(arg,"-%s -%d",skill_name,estimate)==2 
		|| sscanf(arg,"-%s",skill_name)==1) {
		if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) 
			return notify_fail("��" + skill_name + "���������ּ�����\n");	
		if( !(skill_level=me->query_skill(skill_name,1)))
				skill_level = 0;
//			return notify_fail("�㲢û��ѧ������ܻ��Ǽ��ܵȼ�Ϊ�㡣\n");
		
		learned_skill_points=me->query_learned();
		
//		return notify_fail("��û��ѧ���κμ��ܣ������ܲ쿴���ܵľ�����Ϣ����ȥѧ��ʲô�ɡ�\n");
			
//		write( "��Ŀǰѧ����\n\n");		
		write(HIG"����������������������������������������������������������������\n"NOR);   
		
		if (mapp(learned_skill_points))
		{
			write(sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n\n", 
					(learned_skill_points[skill_name] >= (skill_level+1) * (skill_level+1)) ? HIM : "", 
					me->query_skill_mapped(skill_name) ? "  ": "��",
					SKILL_D(skill_name)->name() + " (" + skill_name + ")",
					skill_level(SKILL_D(skill_name)->type(), skill_level),
					skill_level, 
					learned_skill_points[skill_name],
			));
		} else
			write(sprintf("%s%s\n\n",
					me->query_skill_mapped(skill_name) ? "  ": "��",
					SKILL_D(skill_name)->name() + " (" + skill_name + ")")
					);
			
		msg = sprintf("\t���书ϵ����%-6d���˺��ȼ���+%-6d�����еȼ���+%-6d\n",
				SKILL_D(skill_name)->effective_level(me),
				SKILL_D(skill_name)->damage_level(me),
				SKILL_D(skill_name)->accuracy_level(me));
		msg += sprintf("\t��ѧϰ�Ѷȡ�%-6d���о��Ѷȡ�+%-6d����ϰ������%-6d\n",
				SKILL_D(skill_name)->skill_difficulty(),
				SKILL_D(skill_name)->skill_difficulty_r(),
				SKILL_D(skill_name)->practice_limit());
		
		if (SKILL_D(skill_name)->eff_parry_level()!=SKILL_D(skill_name)->effective_level())
			msg += sprintf("\t���м���Чϵ����%-6d\n",
				SKILL_D(skill_name)->eff_parry_level());
		if (SKILL_D(skill_name)->bounce_ratio())
			msg += sprintf("\t���������Чϵ����%-6d������෴��ϵ����%-6d\n",
				SKILL_D(skill_name)->ic_effect(),
				SKILL_D(skill_name)->bounce_ratio());
		write(WHT+msg + "\n"NOR);
		
		// Here a friendly estimation of pot cost
		
		if (mapp(learned_skill_points)){
			j = me->query_skill(skill_name,1);
			if (!estimate|| estimate<=j)	estimate = j+1;
			if (estimate>400)	estimate = 400;
		
			if (me->query_int()<=40)
				amount = (400+30*me->query_int())*2*100;
			else
				amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*100) ;
						
	        if (me->query("national")=="����")	
	        	amount = amount + amount/20;	// ��������      	            	    	
	        amount = amount / SKILL_D(skill_name)->skill_difficulty();        	                 	
	       	if( amount < 1) amount = 1;		// ����1��1 
	       	          
	        for (i=j;i<=estimate-1;i++){
	        	total = total + (i+1)*(i+1)+1;
	       	}
	       	total = total - learned_skill_points[skill_name];	
			cost = total*100/amount+1;
			
			my_skill = estimate-1;
			if ( member_array(skill_name, att_skill) == -1)
	    		my_skill = my_skill * SKILL_D(skill_name)->effective_level(me)/100;
	    	else
	    		my_skill = my_skill * 150/100;	
	    	req_exp = my_skill * my_skill * my_skill/10;
			exp_data = exp_to_level(req_exp);
			
			write(sprintf(YEL"��������%d������Ǳ�ܡ�%-6d\t�����辭��ȼ�����%d ��%d.%d����\n" NOR,
						estimate,cost,
							exp_data["level"],
				    		exp_data["sub"]/10,
				    		exp_data["sub"]%10,
				    		));
			
			my_skill = estimate-1;
			if ( member_array(skill_name, att_skill) == -1)
	    		my_skill = my_skill * SKILL_D(skill_name)->effective_level(me)/100;
	    	else
	    		my_skill = my_skill;	
	    	req_exp = my_skill * my_skill * my_skill;
			exp_data = exp_to_level(req_exp);
			
			write(sprintf(YEL"���Ķ��й��鼮������%d�����辭��ȼ�����%d ��%d.%d����\n\n" NOR,
							estimate,
							exp_data["level"],
				    		exp_data["sub"]/10,
				    		exp_data["sub"]%10,
				    		));
		}
			
		if (me->query_temp("timer/check_skill_help")+2 < time())
			SKILL_D(skill_name)->help(me);
		me->set_temp("timer/check_skill_help",time());
		
		write(HIG"����������������������������������������������������������������\n"NOR);   
		return 1;
	}
	
//	==> single skill check ends.	
	
	
	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();		 
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
	}
	
	target = (string) me->query("marry");	
	if(stringp(target)) couple_ob = find_player(target);
	
	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
		&& !me->is_apprentice_of(ob) && ob!=couple_ob
		&& !ob->query("skill_public") )
//		&& !ob->query("skill_restrict"))
		return notify_fail("ֻ�й������ʦͽ/���޹�ϵ�����ܲ쿴���˵ļ��ܡ�\n");

/*	if (stringp(permit = ob->query("skill_restrict"))) {
		if (member_array(permit, me->query("marks/ok_skill")) == -1)
			return notify_fail("ֻ�й������ʦͽ/���޹�ϵ�����ܲ쿴���˵ļ��ܡ�\n");	
	}*/

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}
	write( (ob==me ? "��" : ob->name()) +"Ŀǰ��ѧ��"+chinese_number(sizeof(skl))+"�ּ��ܣ�\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	for(i=0; i<sizeof(skl); i++) {
		if(!find_object(SKILL_D(sname[i])) && file_size(SKILL_D(sname[i])+".c")<0) 
		{
			ob->delete_skill(sname[i]);
			write("delete obselete skill " + sname[i] + "\n");
			continue;
		}
		if (ob->prevent_shown(me,sname[i]))	continue;
		write(sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "", 
				(member_array(sname[i], mapped)==-1? "  ": "��"),
				SKILL_D(sname[i])->name() + " (" + sname[i] + ")",
				skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
				skl[sname[i]], 
				(int)lrn[sname[i]],
		));
	}
	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 20;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

string pet_skill(object ob)
{
	string desc;
        object  *list, couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        int i, marry_flag;
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                desc =  ob->name() + "Ŀǰ��û��ѧ���κμ��ܡ�\n";
                return desc;
        }
        	desc =  ob->name() +"Ŀǰ��ѧ���ļ��ܣ�\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
              desc +=  sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        SKILL_D(sname[i])->name() + " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        return desc +"\n";
}


int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m   
[0;1;36mָ���ʽ :[0;32m 

��1�� skills 

��ѯ�Լ���ѧ���ļ��ܡ�

��2�� skills [<ĳ��>] 

ָ��һ��������ʦͽ/���޹�ϵ�Ķ��󣬿��Բ�֪�Է��ļ���״����

��3�� skills -����Ӣ������

�ڼ��š�-�����һ���ܵ�Ӣ�����ƣ���ֻ�г��ü��ܵĵȼ�״����

��4�� skills -����Ӣ������ -����

����һ�������ڡ����֡��ȼ�����Ҫ��Ǳ�������㡣

Ϊ�˱���ˢ������������Ӧ���ؼ���Ϣÿ�����������ʾһ��

[0;1;37m����������������������������������������������������������������[0m   

���ڸ����˵��

��������x������Ǳ�ܡ�
�����辭��ȼ���
���Ķ��й��鼮������x�����辭��ȼ���

Ϊ�˷����ң����Ǹ����������״��������һ��������һ������
Ǳ�������Ĵ��¹��ơ��Դ���һЩ˵����

�ᣮ���ƣ���������ѧϰ���ķѵ�Ǳ����û������ڶ����������
�ǱȽ�׼ȷ�Ĺ��ƣ������㻨�ѵ�Ǳ�ܲ�ͬ������������ʱ����һ
�����죬�˹����ǰ���ÿ��ʹ�ã�����Ǳ�ܵ�Ĺ�ʽ����ġ�
������μ�����𡡣������˵����

�⣮�˹����ǰ����㵱ǰ���ǡ����塢�Լ���ǰ���ܵȼ�����Ӧ��
ѧϰ�Ѷ�������ģ������Ĳ��ǡ����߸ü��ܵ�ѧϰ�Ѷ��Ժ��
���ˣ��������Ҳ���䶯��

�㣮����ʶ�֣�literate��ǣ�浽���ǵ���ߣ�������ʵ�������
����ʾ��Ҫ�ٺܶࡣ
[1;31m
�䣮���кķѵ�Ǳ�ܵ�ֻ�ڵ�ǰ�ȼ���Ч����ʹϵͳ��ʾ��Ҫ20000
�������ڣ������������������ֻ�У�������һ����ȥ20000��Ҳֻ
�������ڣ�������������ֱ�������ڣ�����������֮������
[0;32m

���书ϵ����������Ҫ�������������书��ĳһ����ο���ѧ����
��ߵȼ����书ϵ�����书�ȼ��Ǿ����书�������ʵ�������Ҫ���ء�

���˺��ȼ��������书���˺��ʣ��˺���һ��ȡ�����������������
��enforce������������Ծ���ȼ��ȣ����˺��ȼ�����ǰ��������
�ӳɡ�100�൱����Դ�������ͼ������˺�������10����

�����еȼ�����������һ����书�����ʵļӳɣ�����������ȫ
��ͬ�ļ��ܣ����еȼ��������ı����еȼ����������ʸߣ�����

��ѧϰ�Ѷȡ��ο����������Ĺ�ʽ˵��

���о��Ѷȡ�һ����˵���о�����������裩����Ǳ����Ϊ��
ͨѧϰ����ģ��������о��Ѷ����ڴ˻����ϵļ�Ȩ��

����ϰ�������ü����ܹ���ϰ�����������壩������ߵȼ���

���м���Чϵ����һ����˵�����书ϵ�������Ǽ��ܵ��м�ϵ����Ψ
��һЩ�ض����书����ר�ŵ��м�ϵ����

���������Чϵ���������������书�����ڻ��׵����Σ�ϵ��Խ�ߣ�
�������þ�Խ���ԡ�

������෴��ϵ���������������������书�ķ����˺�����


[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
