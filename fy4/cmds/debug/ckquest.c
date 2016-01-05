// ckquest.c
// Silencer, quest-reward checkup
// ���������������Quest�Ľ��������
	
#include <ansi.h>
inherit F_CLEAN_UP;
void give_reward(object who, object accomplisher, mapping quest);

int main(object me, string arg) {
	
//	if (!wizardp(me) || me->query("tester"))
//		return notify_fail("��ʦר��ָ�Υ����ɱͷ��\n");
	seteuid(ROOT_UID);
	write("\n\n");
	me->ccommand("quest");
	if (!me->query("quest"))
		return notify_fail("��û�Уѣ�������\n");
	write(sprintf(WHT"\n���Quest��%O.\n"NOR,me->query("quest")));
	write(HIR"��ľ���ֵ��"+ me->query("combat_exp") +"\n\n"NOR);
	give_reward(me, me, me->query("quest"));
	me->ccommand("hp");
	return 1; 
}

void give_reward(object who, object accomplisher, mapping quest) 
{
	int i, d_bonus, team_size, q_bonus, max_exp,e_reward,single_exp;
	int used_time,t_bonus, l_bonus;
	int combat_exp,pot,score, ratio, sum_exp, i_pot,
		reward_silver, reward_exp, reward_score,reward_pot;
	int team_bonus, silver;
	int accomp_exp, accomp_pot, accomp_silver;
	int my_exp_level,q_num;
	int random_n, real_exp;
	int base;
	
	mapping level_data;
	
	string reward_msg;
	object ob;
	object* mem;
	
	/* 4.0 system base:
		0-10k, 		20 - 23
		10-800k, 	32 - 116
		880k-2.2M: 	116 - 233
		2.2M+		131+ random(91) --- 260
		
	*/
			
	mem = pointerp(who->query_team()) ? who->query_team() : ({ who });
	team_size = sizeof(mem);
	sum_exp = 0;
	max_exp = 0;

	// Check if max_exp player left team and calculate max_exp, sum_exp
	for(i=0; i<team_size; i++) {
		if (mem[i]) {
		    q_bonus = (int)mem[i]->query("combat_exp");
		    max_exp = (max_exp>q_bonus) ? max_exp : q_bonus;
		    sum_exp += q_bonus;		    
		}
	}
	
	q_bonus = quest["exp_bonus"];

	//Max_exp player left team, heavy penalty on cheating :D
	if (700*q_bonus > max_exp){
		q_bonus = max_exp/1024 ;
	}
	
	tell_object(who,"�����������ֵΪ "+max_exp+" .\n");		
	
	//Calculate base bonus
	 			
	// BASE
	
	// base exp �� pot �����������Ӧ�ó�������������5M����
	
	if(q_bonus < 10) 		base= 20 + q_bonus/3;
	else if (q_bonus < 800)    	base= 30 + (q_bonus *2)/9- (q_bonus*q_bonus)/7000;
	else if (q_bonus < 2000) 	base= 50 + q_bonus/12;
	else 				base= 40 + q_bonus/24 + random(q_bonus/24);
	
	if(base > 160) {
		base = 260 - 3*16000/(base*2);	
	}
	
	real_exp = base;				//������������� pot ����ʵexp. 
	
	// ���� 5M ���ϵ� exp �����������𽥼��١�
	if (q_bonus > 5000)	{
		base = (q_bonus< 10000)?(10000 - q_bonus)/ 20:10;
	}
	
			
	combat_exp = base;				// ����δ����team bonus�ĸ��˽���exp��
	
	// Ǳ�ܵ� Difficulty BONUS
	// ����
	// 	(1)	�Ƚ���ɱ+5, 
	//	(2)	�Ƚ�Զ+5, (������Ʒ) After 5M, this is no longer the case.
	//	(3)	�϶�������Σ��+10-15, 
	//	(4)	Random() +5, 
	//				--> 30 Maxium. 	If >30... �㶨�ü��������⡣
	if(quest["difficulty"]) {
		d_bonus = 100 * (quest["difficulty"]-5)/10;
		if (max_exp *9/10 > q_bonus) {
			d_bonus = d_bonus/2;
			tell_object(who,"�������Ը���quest��quest�ѶȽ���/2 = d_bonus = " + d_bonus + "\n");
		}else if (max_exp > q_bonus) {
			d_bonus = d_bonus *2/3;
			tell_object(who,"�������quest��quest�ѶȽ���2/3 = d_bonus = " + d_bonus + "\n");
		}else 
			tell_object(who,"����С�ڵ���quest��quest�ѶȽ��� = d_bonus = " + d_bonus + "\n");
	}	else
			tell_object(who,"û��quest�ѶȽ��� = d_bonus = 0 \n");
	
		
	// Ǳ�ܵ� TIME BONUS
	if (quest["quest_type"] == "ɱ") {
		used_time = (int) time() - who->query("task_time");
		if(used_time < 60) {  		//Get 50% bonus for finishing within 1 minutes
			t_bonus = 100 / 2;
		} else if (used_time < 360) {  	//Get a little bonus for finishing within 6 minutes
			t_bonus = 100 * (360 - used_time) /600;
		}
	}
		
	
	//Add some bonus for team to share 
	// 1M ���µõ���������ppl, �Ժ�Ϊ�����������죮
	if (q_bonus<1024) {
		team_bonus = 100;
		team_bonus = team_bonus < (team_size -1)* 20 ? team_bonus : (team_size -1)* 20 ;
	} else {
		team_bonus =  40 ;
		team_bonus = team_bonus < (team_size -1)* 100/12 ? team_bonus : (team_size -1)* 100/12 ;
	}
	
//	tell_object(who,"team_bonus is"+(string)(team_bonus)+".\n");
//	tell_object(who,"total exp reward"+(string)(combat_exp)+".\n");
	

//	���� TEAM BONUS �͡����������ġ����飬Ǳ�ܽ�����
	random_n = random(100);	
	combat_exp = combat_exp + combat_exp * (random_n + team_bonus) /100;
	real_exp   = real_exp   + real_exp   * (random_n + team_bonus + d_bonus + 10) /100;

	if(q_bonus < 200) 			pot = real_exp / 7 + 1;
	else if (q_bonus < 4000)		pot = real_exp / 6 + 1;
	else if (q_bonus < 5500)		pot = real_exp *10 /55 + 1;
	else 					pot = real_exp / 5 + 1;


//	tell_object(who,"q_bonus is"+(string)(q_bonus)+".\n");
/*	tell_object(who,"  ��������exp "+q_bonus*1000+" �εģ������.\n");
	tell_object(who,"  ��õ������ģ£����� "+base+" �㾭�飮\n");
	tell_object(who,"  ���ʱ�佱����(�ԣ���ģ��)" + t_bonus + "�� , �ѶȽ����� " + d_bonus + "�� .\n");
	tell_object(who,"  ��� Random seed ����" + random_n + "�� .\n");
	tell_object(who,WHT"  ��õ�������exp �� "+combat_exp+" �㾭�飮\n"NOR);

	level_data=F_LEVEL->exp_to_level(who->query("combat_exp"));
	
	tell_object(who,HIG" ������ٶȣ�"+level_data["level"]+"������Ҫ" 
		+(level_data["next_level"]/combat_exp)+" ���ѣ�������������һ����\n\n"NOR);*/
	

	// add money
	if (q_bonus< 50) silver = 10 + random(10);
	else if (q_bonus< 100) silver = 10 + random(20);
	else if (q_bonus< 500) silver = 10 + random(30);
	else if (q_bonus< 1000) silver = 20 + random(40); 
	else silver = 30+random(60);
	
	accomp_exp = combat_exp;
	accomp_pot = pot;
	accomp_silver = silver;
	
	if (sum_exp == 0) sum_exp = 1;
	for(i=0; i<sizeof(mem); i++) {
		if (mem[i])
		if (mem[i]!=accomplisher) {
			
			ratio = (10* mem[i]->query("combat_exp"))/sum_exp*10;
//			tell_object(mem[i],"ratio is "+ratio+"\n");
			reward_exp= (combat_exp*ratio)/100>0 ? (combat_exp*ratio)/100 : 1;
			if((silver/team_size ) > 0 && objectp(ob = new("/obj/money/silver"))) {
				reward_silver= (silver*ratio)/100>0 ? (silver*ratio)/100 : 1;
				ob->set_amount(reward_silver);
				if(mem[i]->query("env/savemymoney"))
					mem[i]->add("deposit",reward_silver*100);
				else
					ob->move(mem[i]);
			}
		
			accomp_exp = accomp_exp - reward_exp;
			accomp_pot = accomp_pot - pot * ratio/100;
			accomp_silver = accomp_silver - reward_silver;
			
			i_pot= pot* ratio/100;
			 						
			mem[i]->add("combat_exp", reward_exp);
			mem[i]->add("potential", i_pot);
			mem[i]->add("score", (score*ratio) / 100);	
			
//			if (reward_exp > 1000)
//				log_quest(mem[i], who, quest, reward_exp, i_pot, used_time, base);
						 
			score =  mem[i]== accomplisher? 1 : 0;
			reward_msg = mem[i]==who ? HIW : HIW+"�����Ա "+who->name()+" ��";
			reward_msg +="����"+accomplisher->name()+"��ɣ��㱻�����ˣ�\n\t\t" +
				chinese_number(i_pot) + "��Ǳ��\n\t\t" +
				chinese_number(score) + "������\n\t\t" + 
				chinese_number(reward_silver) + "������\n" + NOR;
			
			tell_object(mem[i],reward_msg);
			mem[i]->add("FINISH_QUEST",1);
		}
	}
	
	score = 1;
	accomplisher ->add("score", 1);
	accomplisher->add("combat_exp", accomp_exp);
//	accomplisher->add("potential", accomp_pot);
	
//	log_quest(accomplisher, who, quest, accomp_exp, accomp_pot,used_time, base);
	
	if(objectp(ob = new("/obj/money/silver"))) {
		ob->set_amount(accomp_silver);
		if(accomplisher->query("env/savemymoney"))
			accomplisher->add("deposit",accomp_silver*100);
		else
			ob->move(accomplisher);
	}
	reward_msg = accomplisher==who ? HIW : HIW+"�����Ա "+who->name()+" ��";
	reward_msg +="��������ɣ��㱻�����ˣ�\n\t\t" +
	chinese_number(accomp_exp) + "�㽭������\n\t\t" +
	chinese_number(accomp_pot) + "��Ǳ��\n\t\t" +
	chinese_number(1) + "������\n\t\t" + 
	chinese_number(accomp_silver) + "������\n" + NOR;
	
	tell_object(accomplisher,reward_msg);
	accomplisher->add("FINISH_QUEST",1);
	who->set("quest", 0 );
	return;
}


int help(object me) {
	write(@HELP
ָ���ʽ : quest
 
���ָ�������ʾ���㵱ǰ������
HELP);
	return 1;
}
