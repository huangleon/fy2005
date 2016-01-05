/* rewardd.c	��daemon�ػ�������Ϸ���������Ʒ��Ľ�����
	--- by Silencer@fy4

��1�����ƽ�������

	���飺	Quest��ɱ���콾
	Ǳ�ܣ�  ����������Task
	��Ǯ��  Task��Quest��ɱ���콾���Լ�ɱ�˷Ż����ã����٣�����robot��
	���ۣ�  Task���콾������  ���������ã���ʦ����free_master�����ӵȣ�
	�ؼ�/Mark/���ܵȣ�  ����

��2��score��������
	10	����ĳһ���µĵ���������˵���˵����ȵ��Ǹ��ڶ�
	30	����һ���򵥵ģ������Ϸ��Ƶģ����⣨������ͭ��ʲô�ģ�
	50	һ�������
	100	�ϸ��ӵ�����������������⣨�����ƣ�
	200 	�����⣬������������漰��������ģ�

	ɱ���콾��score��= difficulty (1-50)
	Task��	score = 1

*/

#include <ansi.h>
inherit F_LEVEL;

void create() {
    seteuid(ROOT_UID);
}

/*	ÿ���ȼ��õ��ĵ���Quest����ֵ�������ֵ

	����ȼ����ձ�
	2k - 100k		L0--L10			Delta_L= 10k
	100k-1.1M		L10-L30			Delta_L= 50k
	1.1M- 3.1M		L30-L70			Delta_L = 50k
	3.1- 11.1M		L70-L150		Delta_L = 100k
	11.1-21.1M and above	L150-L200		Delta_L = 200k
*/

int quest_reward(int level){

    int num, reward;

	// ���չ����֣�������
    if (level < 10)
    switch (level) {
    	case 0:	
    	case 1:		
    	case 2:		
    	case 3:		
    	case 4:		
    	case 5:
    	case 6:		num = 20;	break;
    	case 7:		
    	case 8:
    	case 9:		num = 30;	break;
	}													// ���� 20*3+30*3+40*3 = 270 ��
    	
//	�ݶ��Ľ�����ʽ������Quest����Ҫ��ã�5month?�����������̫�죬��;�ټ��Ե���    	
    if (level>=10)	
    switch (level/10){
	    case 1:	
	    case 2:	
	    case 3:		
	    case 4:	num= 60;	break;						// 1000*4 ->  750*4
	    case 5:
	    case 6:
	    case 7:	
	    case 8:
	    case 9:	
	    case 10:num= 150;	break;						// 2000*6 --> 1000*6
	    case 11: 
	    case 12:
	    case 13:num= 200;	break;						// 3000*4 --> 2000*4
	    default:num= 500; 	
    }													

    if (level<10)		reward = 10000/num;		//����γ�����Ŀ����������ֵ
    else if (level<70)	reward = 50000/num;
    else if (level<140)	reward = 100000/num;
    else 			reward = 1;					// COMBAT_EXP should always < L140

    return reward;

}

//	ɱ���콾�Ľ���, difficulty = 1-50;
void 	tianjiao(object player, int difficulty){

    object money_reward;

    player->add("score",1);
    player->add("marks/tianjiao_num",1);		//--- ��¼playserɱ���콾����Ŀ��

    tell_object(player,HIW"\n��ɹ���ɱ����һ�������콾���㱻�����ˣ�һ�����ۺ�"
    + chinese_number(difficulty)+"���ƽ�\n\n"NOR);

    if(player->query("env/savemymoney"))
	player->add("deposit",difficulty*10000);
    else
    {
		money_reward = new("/obj/money/gold");
		money_reward->set_amount(difficulty);
		if (!money_reward ->move(player))	{
	    	tell_object(player, HIR"���������ϵĶ�������̫�࣬������û���ˡ�����\n"NOR);
	    	destruct (money_reward);
	    }
		tell_object(player,WHT"���� Set savemymoney 1 �ɽ������Զ��������У�\n"NOR);
    }

    return;

}


//	ÿ��TasK��TaskNPC�Ľ���, default amount= 50 silver
int 	task_reward(object player, int amount){

    object money_reward;
    int task_level, task_num;
    object book;
    	
    player->add("score",1);
		player->add("deposit",amount * 100);
		player->add("TASK",1);   	
		
    tell_object(player,HIW"�������һ��TASK����õ�һ�����ۡ��������"
			+ chinese_number(amount)+ "��������\n"NOR);

		// TASK ��ÿ���ȼ���Ǳ�ܵ�Ľ���
		task_level = F_LEVEL->get_level(player->query("combat_exp"));
		task_num = F_LEVEL->level_to_pot(task_level)/10/50;		// 1/10 leveling up reward    
    if (player->query("rewarded_task")< task_num) {
    	player->add("rewarded_task",1);
    	player->add("task_pot", 50);
    	player->add("potential",50);
    	tell_object(player,HIW"���Ǳ�ܵ�������50��\n"NOR);	
    } 
    else
    {
		  player->add("saved_quest",60/3);	// 6000= 1 ability, 60/3--> 300 tasks 1 ability    	
    	player->add("ability_task",1);
    	tell_object(player,HIW"�����������ۣ�Ability�������0.3��\n"NOR);
    }		
    
    if (!random(12)){
    	book=new("/obj/item/treasurebook");
		if (!book->move(player))
			book->move(environment(player));
    	tell_object(player,HIR"����أ���õ���һҳ������������\n"NOR);
    }
    	
    return 1;
}


int check_m_success(object who, string riddle)
{
    return who->query("m_success/"+ riddle);
}

//	Riddle and score reward
varargs int riddle_reward(object who, string rname, int score,int g){

	if (!userp(who))	return 0;	 
    if (check_m_success(who,rname))		return 0;


    if (!g) g = 1;
    who->set("m_success/"+ rname, g);
    if (score)	
    {
	who->add("score",score);
	log_file("riddle/REWARD_LOG",
	  sprintf("%s(%s) ����� %s���������ۣ�%d \n",
	    who->name(1), geteuid(who), rname, score));
    }

    tell_object(who,HIY"\n\n��ϲ��⿪�ˡ�"HIC+rname+HIY"��"NOR);
    if (!score)
	tell_object(who,HIY"��\n\n"NOR);
    else
	tell_object(who,HIY"���õ�"+score+"�����ۣ�\n\n"NOR);

    log_file("riddle/RIDDLE_LOG", 
      sprintf("%s(%s) ����� %s��ʱ�䣺%s \n",
	who->name(1), geteuid(who), rname, ctime(time())));
    return 1;
}

varargs int riddle_set(object who, string rname, int phase)
{
    if (!phase)
	phase = -1;
    who->set("riddle/"+rname,phase);
    if (phase == 1)
    	tell_object(who,WHT"��ϲ���㿪ʼ��һ�������⣺"+ rname + "\n"NOR);
    if (who->query("combat_exp")== 2000)	// likely newbie quest
    	tell_object(who,WHT"���������ʱʹ������riddle���鿴��Ľ��ս��̡���\n\n"NOR);
    return 1;
}

varargs int riddle_clear(object who, string rname)
{
    // No, we dont want to clear m_success mark.
    who->set("riddle/"+rname,0);
    return 1;
}

varargs int riddle_check(object who, string rname)
{
    return who->query("riddle/"+rname);
}

varargs int riddle_done(object who, string rname, int score,int g)
{
    //	g=who->query("riddle/"+rname);
    if (!userp(who))	return 0;
    who->delete("riddle/"+rname);
    riddle_reward(who,rname,score,g);
    return 1;
}


//	Item reward
int give_item(object me, string riddle, string item_file){
    object item;

    item = new(item_file);

    if (!objectp(item)){
	tell_object(me, HIR"OOPS, �뱨����ʦ������У£գǡ�\n"NOR);
	log_file("riddle/REWARD_LOG",
	  sprintf("%s(%s) ����� %s������û�з��ֽ��������%s \n",
	    me->name(1), geteuid(me), riddle, item_file));
	return 1;
    }

    if (item->move(me)){
	tell_object(me,WHT"��õ���"+ item->name() + "��\n"NOR);
	log_file("riddle/REWARD_LOG",
	  sprintf("%s(%s) ����� %s�����������%s %s \n",
	    me->name(1), geteuid(me), riddle, item->name(), item_file));
    } else {
	destruct(item);
	log_file("riddle/REWARD_LOG",
	  sprintf("%s(%s) ����� %s�������޷����������%s %s \n",
	    me->name(1), geteuid(me), riddle, item->name(), item_file));
	tell_object(me, YEL" OOPS, ������һ����Ʒ����������\n"NOR);
    }
    return 1;										
}

/*	IMBUE event daemon, triggered by NPC
	������Щ�εδ���msg,�����������imbue����player���Ϸ�����
	imbue {[
		"name": "ħ�۽�",
		"target": me,
		"att_1": "str", "con" etc
		"att_1c": 
		"att_2": 
		"att_2c":
		"att_3": ------------> �����ʹreward�����������
		"att_3c":
		"mark":	��ʱ������в�ͬ���
	]));	

*/

int	imbue_check(object who, string name)
{
    return who->query("imbue/"+ name);
}

int 	imbue_att(mapping imbue)
{
    object who;
    int n;
    string *att = ({ "str", "cps", "agi", "con", "int", "kar" });
    string *att_c = ({"����","����","�ٶ�","����", "����", "����" });

    who = imbue["target"];

    // A little check here
    if ( imbue_check(who,imbue["name"]))	return 0;

    if (stringp(imbue["att_1"]))	
    {
	n = member_array(imbue["att_1"], att);
	if (n == -1)	
	{
	    tell_object(who," Riddle is bugged, please notify Wizard.\n");
	    return 1;
	} 		
	tell_object( who, HIR"���"+ att_c[n] + "������"+ chinese_number(imbue["att_1c"])+"�㡣\n"NOR);

	who->add(imbue["att_1"],imbue["att_1c"]);
	who->add("imbue/"+ imbue["att_1"], imbue["att_1c"]);	
	log_file("riddle/IMBUE_LOG",
	  sprintf("%s(%s) �⿪ %s imbue ��� %d���õ����� %s(+%d)��%s \n",
	    who->name(1), geteuid(who), imbue["name"], imbue["mark"], 
	    imbue["att_1"], imbue["att_1c"], ctime(time()) ));
    }

    if (stringp(imbue["att_2"]))	
    {
	n = member_array(imbue["att_2"], att);
	if (n == -1)	
	{
	    tell_object(who," Riddle is bugged, please notify Wizard.\n");
	    return 1;
	}
	tell_object( who, HIR"\n���"+ att_c[n] + "������"+ chinese_number(imbue["att_2c"])+"�㡣\n\n"NOR);
	who->add(imbue["att_2"],imbue["att_2c"]);
	who->add("imbue/"+ imbue["att_2"], imbue["att_2c"]);	
	log_file("riddle/IMBUE_LOG",
	  sprintf("%s(%s) �⿪ %s imbue ��� %d���õ����� %s(+%d)��%s \n",
	    who->name(1), geteuid(who), imbue["name"], imbue["mark"], 
	    imbue["att_2"], imbue["att_2c"], ctime(time()) ));
    }

    // OK, �������Ǹ��������...��Ҫ��׼�����ʹ��:)
    if (stringp(imbue["att_3"]))	
    {
	n = random(6);
	tell_object( who, HIR"���"+ att_c[n] + "������"+ chinese_number(imbue["att_3c"])+"�㡣\n\n"NOR);
	who->add(att[n],imbue["att_3c"]);
	who->add("imbue/"+ att[n], imbue["att_3c"]);	
	log_file("riddle/IMBUE_LOG",
	  sprintf("%s(%s) �⿪ %s imbue ��� %d���õ�������� %s(+%d)��%s \n",
	    who->name(1), geteuid(who), imbue["name"], imbue["mark"], 
	    att[n], imbue["att_3c"], ctime(time()) ));
    }

    who->set("imbue/"+ imbue["name"], imbue["mark"]);
    who->save();

    return 1;

}
