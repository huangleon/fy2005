// ��籵ķ��ݺ�ʽ

#include <ansi.h>
inherit ROOM;
inherit F_ANNIE;

#define DAY 86400

int save();
int restore();
int restore_item();


int is_owner(string arg)
{
	object ob;
	if (arg == query("temp_owner"))
		return 1;
	if (arg == query("owner"))
		return 1;
	
	// ���Ӷ����ļ�飬��ֹһ�����	
	// ����˵��ֻ�����ó�2nd owner�ĵ�ǰ���²��ܹ���
	if (arg == query("couple")) {
		ob = find_player(arg);
		if (!ob)	return 0;	
		if (ob->query("marry")!= query("owner")) {
			set("couple","����");
			return 0;
		}
		return 1;
	}
	return 0;
}


void init()
{
	int flag;
	flag = (int) query("room_flag");
	if(flag & 1) set("valid_startroom",1);
	if(flag & 2) set("NONPC",1);
	if(flag & 4) set("no_fight",1);
    if(flag & 8) set("no_magic",1);
	if(flag & 16) set("outdoors","residence");
	if(flag & 32) set("open_area",1);

	if (!query("already_loaded"))
	{
		restore();
		restore_item();	// annie' item-save
		set("already_loaded",1);
		set("perma_exist",1);		// to help with the stack field
	}
	
	add_action("do_help","roomhelp");
	add_action("do_invite","invite");
//	add_action("do_setowner","setowner");	// ��ʱ�رմ�ָ�
	add_action("do_share","share");
	add_action("do_here","here");
//	add_action("do_pay","pay");
	add_action("do_payoff","payoff");
	add_action("do_remodel", "remodel");
	add_action("do_destroy", "destroy_room");
	add_action("input_description","renovate");
	add_action("do_exercise","fight_switch");
}

// ����������arch����ǿ�����ٷ���

int do_destroy(){
	
	object me = this_player();

	if (!wizardp(me) || wiz_level(me) < 4){
		return 0;
	}	
	
	BR_D->destroy_room();
	return 1;
}


int do_help()
{
	write(@HELP   
�ڴ˷������ִ�е����
-Roomhelp
������

-Share 
����¹�����ķ��䡣ֻ�з�������˿���ִ�д�ָ�ע�⣬��ָ
���������ĵڶ������ˣ�һ���������޷����������Ϸ�и��ġ�
��������飬ǰ�ޣ�����Ȼ�ǵڶ����ˣ����޷������ɳ��롣

-Invite 
���������˽�����ķ��䡣 
ֻ�з�������˻�ڶ����˿���ִ�д�ָ� 
����ԭ���������ϵ��˿���ȡ�����롣

-Here 
�鿴��ǰ�������ӵ�������κ��˶�����ִ�д�ָ�

-Payoff
��ͼһ�ν������е���ֻ�з��ݵ����˻�ڶ����˿���ִ�д�ָ�
Ϊ�˱����������������Ҫ��ִ����ȥ����һ�ݺ�Լ��

-Remodel
�����еķ��ݽ���������������Ψ�����Ѿ��������з��ݵĴ�������
ִ�У�Ϊ�˱����������������Ҫ��ִ����ȥ����һ�ݺ�Լ����������
�����д���ܣ�����һ�θ��塣

-Renovate
װ�����з��ݣ�������ɸı����ӵ�������ÿ��װ��ֻ�ķ������ƽ�
����ÿ����װ�޼��ʱ�䲻������ʮ���ӡ�

HELP
    );
    return 1;
}

int query_tax()
{
//	return query("basic_tax")+query("tax");	�Ҿ����Ҳ���Ǯ
	return query("total_gold")*14/15;
}

int query_stax()
{
//	return query("basic_score_tax")+query("score_tax");���Ҿ����Ҳ���Ǯ, and, using free_space is bugged here with upgrades
	int g1,old_space;
	g1 = query("total_gold");
	
	switch (g1) {
		case 150:	old_space = 1; break;
		case 300:	old_space = 2; break;
		case 600:	old_space = 3; break;
		case 1200:	old_space = 4; break;
		case 2400:	old_space = 5; break;
	}

	return old_space*100;
}

//  �򻯹��̣��������pay_time()�ĺ������ last_pay_time�ˣ�
int pay_time()
{
	if (query("last_pay_time"))
		return query("last_pay_time");
	else
		return atoi(query("timestamp2"));
}

//	������������ǰ�last_pay_time���ڵ�������������Ǹ���ȥ������
int reset_pay_time()
{
	int n;
	n = (time()-pay_time())/DAY/7;
	set("last_pay_time", pay_time()+ n*DAY*7);
	return query("last_pay_time");
}

int balance_g(){		// unit = silver
	
	int left;
	left = query("total_gold")*100 - query("already_pay");
	
	if (left<=0 )
		return 0;
	else
		return left;	
}


int balance_s(){
	
	int left_s;
	left_s = query("total_score") -query("already_spay");
	
	if (left_s <=0)
		return 0;
	else
		return left_s;
	
}

/*
int do_pay()
{
	int t,s,n;
	int g;
	int gold;
	object me = this_player();
	if(!is_owner(me->query("id")))
		return 0;
	if (query("charged"))
		return notify_fail("���Ѿ�Ԥ������һ�ε��·��ˡ�\n");

	t = query_tax();
	s = query_stax();
	
	if (query("basic_tax") == -1)
		return notify_fail("��������Ѿ��������ˡ�\n");
	
	gold  = this_player()->query("deposit")/100;
	if(gold < t)
       	return notify_fail("�����Ϲ���û�д湻"+chinese_number(t)+"�����ӡ�\n");
	
	if(me->query("score") < s/100)
       	return notify_fail("������۲���"+chinese_number(s/100)+"�㣡\n");
       	
	me->add("deposit",-t*100);
	me->add("score",-s/100);
	add("already_pay",t);
	add("already_spay",s/100);
	set("charged",1);
	
	if( !balance_s() && !balance_g()) {
		set("basic_tax",-1);
		log_file("annie_log_buildroom", 
			sprintf("Payoff: [%s] %s(%s)���Խ�����%s�Ѿ�����������Ϊ%s��\n",
			ctime(time()), 
			me->query("name"),
			me->query("id"),
			query("short"),
			base_name(this_object())));
		tell_object(me,"��ϲ����������Ѿ���������ӵ����ȫ����Ȩ�ˣ���\n");
		save();
		return 1;
	}
		
	save();
    return notify_fail("��ɹ���������һ�ε�������" + t + "�����ӣ���\n");
}
*/

int do_exercise(string arg)
{
	int t,s;
	int g;
	int gold, duration;
	object me = this_player();
	object contract;
	
	if(!is_owner(me->query("id")))
		return notify_fail ("��ô����¶���Ҫ���˲���������\n");
	
	duration = query_temp("fight_switch")+ 3600 - time();
	if (duration >0)
		return notify_fail("�ı䷿�ݴ�����ÿСʱ���һ�Σ�"+ (duration/60)+"��\n");	
	
	if (arg == "1") {
		set("no_fight",0);
		set("no_magic",0);
		message_vision(HIR"�÷����趨Ϊ�ɴ򶷿ռ䡣\n"NOR,me);
		message_vision(HIR"�÷����趨Ϊ��ʹ�÷����ռ䡣\n"NOR,me);
		set_temp("fight_switch",time());
		return 1;
	}
	
	if (arg == "0") {
		set("no_fight",1);
		set("no_magic",1);
		message_vision(HIG"�÷����趨Ϊ���ɴ򶷿ռ䡣\n"NOR,me);
		message_vision(HIG"�÷����趨Ϊ����ʹ�÷����ռ䡣\n"NOR,me);
		set_temp("fight_switch",time());
		return 1;
	}
		
	return notify_fail("����ֻ���ǣ�������򶷣��򣰣�������򶷣�\n");
}	
		
int do_payoff()
{
	int t,s;
	int g;
	int gold;
	object me = this_player();
	object contract;
	
	if(!is_owner(me->query("id")))
		return notify_fail ("������˸�Ǯ����\n");
		
	t = query_tax();
	s = query_stax();
	
	if (query("basic_tax") == -1)
		return notify_fail("��������Ѿ��������ˡ�\n");
	
	if (!objectp(contract = present("payoff contract",me)))
		return notify_fail("Ϊ��ֹ�����������ȥ����һ�ݺ�Լ��payoff contract��\n");
			
	t = balance_g();
	s = balance_s();

	if (!t && !s)
		return notify_fail("��������Ѿ��������ˡ�\n");
		
	gold  = this_player()->query("deposit")/100;
	if(gold < t)
       	return notify_fail("�����Ϲ���û�д湻"+chinese_number(t)+"�����ӡ�\n");
	
	if(me->query("score") < s)
       	return notify_fail("������۲���"+chinese_number(s)+"�㣡\n");
       	
	me->add("deposit",-t*100);
	me->add("score",-s);
	
	tell_object(me,"�㸶����" + t +"��������"+ s + "�����ۡ�\n");
	
	add("already_pay",t);
	add("already_spay",s);
	set("charged",1);
	
	if( !balance_s() && !balance_g()) {
		set("basic_tax",-1);
		log_file("annie_log_buildroom", 
			sprintf("Payoff: [%s] %s(%s)���Խ�����%s�Ѿ�����������Ϊ%s��\n",
			ctime(time()), 
			me->query("name"),
			me->query("id"),
			query("short"),
			base_name(this_object())));
		destruct(contract);
		tell_object(me,"��ϲ����������Ѿ���������ӵ����ȫ����Ȩ�ˣ���\n");
	}
		
	save();
	return 1;
	
}


int do_remodel(string arg){
	
	int old_space, new_space, num;
	int g, s, g1,g2,s1,s2,gold,level;
	object env,contract;
	object me = this_player();
	string this_room, my_file;
	
	g1 = query("total_gold");
	s1 = query("total_score");
	
	switch (g1) {
		case 150:	old_space = 1; break;
		case 300:	old_space = 2; break;
		case 600:	old_space = 3; break;
		case 1200:	old_space = 4; break;
		case 2400:	old_space = 5; break;
	}
	
	if(!is_owner(me->query("id")))
		return notify_fail ("���¶�ֻ�����˲�����������\n");
	
	if (query("basic_tax") != -1)
		return notify_fail("�Ȱ�������ӵĴ������˵�ɡ�\n");
	
	if (!objectp(contract = present("remodel contract",me)))
		return notify_fail("Ϊ��ֹ�����������ȥ����һ�ݺ�Լ��remodel contract��\n");
		
	if (old_space>=5)
		return notify_fail("��������Ѿ��������ռ��ˡ�\n");
		
	if (!arg || sscanf(arg,"%d",new_space)!=1)
		return notify_fail("��ʽ��remodel ���֣�����Ϊ�����������Ŀռ䡣\n");
		
	if ( new_space <= old_space || new_space >5)
		return notify_fail("Remodel������ֱ���������пռ䣨"+old_space+"���󣬱ȣ�С��\n");	 
		
	switch (new_space){
		case 1:		g2 = 150; s2 = 120; break;
		case 2: 	g2 = 300; s2 = 240; break;
		case 3:		g2 = 600; s2 = 380; break;
		case 4: 	g2 = 1200;s2 = 560; break;
		case 5:		g2 = 2400;s2 = 820; break;
		default:	tell_object(me,"���ݸ���ʧ�ܣ�������֪ͨ��ʦ��ʧ�ܴ���Room_0017\n");return 1;
	}

	g = g2 -g1;
	s = s2 -s1;
	
//	write ("remodel needs " + g + " gold, "+ s + " score \n");
	
	gold  = this_player()->query("deposit")/10000;
	if(gold < g)
       	return notify_fail("�����Ϲ���û�д湻"+chinese_number(g)+"�����ӡ�\n");

	if(me->query("score") < s)
       	return notify_fail("������۲���"+chinese_number(s)+"�㣡\n");
	
	env = this_object();
	log_file("annie_log_buildroom", 
			sprintf("Payoff: [%s] %s(%s)���Խ�����%s�Ѿ���%d�Ľ���%d������Ϊ%s��\n",
			ctime(time()), 
			me->query("name"),
			me->query("id"),
			env->query("short"),
			old_space,
			new_space,
			base_name(env)));
	
	env->set("total_gold",g2);
	env->set("total_score",s2);
	env->set("free_space",new_space-(old_space-env->query("free_space")));
	env->save();
	
	me->add("deposit",-g*10000);
	me->add("score",-s);
		tell_object(me,"�㸶����" + g +"���ƽ�"+ s + "�����ۡ�\n");
	me->save();
	destruct(contract);
	write("���ݸĽ��ɹ������Ľ������ϴ洢�ɹ�����\n");
	return 1;

}	

/*
	���ݵĲ���:
	
	A�ࣺ��ROOM initʱ���ļ��Զ���#define������	
		total_gold		:�� �ܶ� ( gold)
		total_score		: ��������	
		room_flag		��������flag
		owner			:   ����
		class			������������
		timestamp		:   �ڼ��䷿
	B�ࣺ��Ϊdbase����ʽ��������ҵ�����Ŀ¼��	
		already_pay		: �ۼƸ��silver��
		already_spay	: �ۼ�����
		basic_tax		������ֻ��Ϊ�Ƿ������п����һ���ͣ���

*/


int do_here(string arg)
{
	string strx;
	write("\n�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
	strx = 
    strx="����������������������"+WHT+query("short")+NOR"("+(query("outdoors")?CYN"����":CYN"����")+NOR")";
	strx=ngstr(strx+NOR,56);
	write("�U"+strx+"�U\n");
    strx="�������"+YEL+ "/cmds/usr/uptime"->chinese_time(7,""+query("timestamp2"))+NOR;
	strx=ngstr(strx+NOR,56);
	write("�U"+strx+"�U\n");
	write("�U �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �U \n");
	strx = " �����ˣ�"CYN+query("owner")+NOR" �����ˣ�"CYN+(query("couple")?query("couple"):"��")+NOR" �������ߣ�"CYN"���Թر�"NOR;
	strx=ngstr(strx+NOR,56);
	write("�U"+strx+"�U\n");
	write("�U�q�����������������������������������������������������r�U \n");
	if (query("basic_tax") == -1)
	{
	write("�U���������������������������������������������������������U \n");
	write("�U���������������������������������������������������������U \n");
	write("�U���������������������������������������������������������U \n");
	write("�U���������������������������������������������������������U \n");
	strx="���ÿռ䣺"CYN+query("free_space");
	strx=ngstr(strx+NOR,52);
	write("�U��"+strx+"���U\n");
	}
	else
	{
	strx="�������գ�"CYN+CHINESE_D->chinese_number(query_tax())+"��"NOR"/�� �������գ�"CYN+CHINESE_D->chinese_number(query_stax()/100)+"��"NOR"/��";
	strx=ngstr(strx+NOR,52);
	write("�U��"+strx+"���U\n");
	write("�U���������������������������������������������������������U \n");

	strx="�ϴν��ɣ�"CYN+"/cmds/usr/uptime"->chinese_time(7,""+pay_time());
	strx=ngstr(strx+NOR,52);
	write("�U��"+strx+"���U\n");
	
	strx="�´ν��ɣ�"CYN+"/cmds/usr/uptime"->chinese_time(7,""+(pay_time()+DAY*7));
	if (time()> pay_time()+ DAY*7)
		strx += HIR"����Ƿ��"+chinese_number(query("expired")/7+1)+"�ڣ�"NOR;
	
	strx=ngstr(strx+NOR,52);
	write("�U��"+strx+"���U\n");
	
	write("�U���������������������������������������������������������U \n");
	strx="�ۼ��ѽ���"CYN+query("already_pay")+"��"NOR"����"CYN" "+query("already_spay")+"��"NOR"���ۡ������ÿռ䣺"CYN+query("free_space");
	strx=ngstr(strx+NOR,52);
	write("�U��"+strx+"���U\n");
	}
	write("�U�t�����������������������������������������������������s�U\n");
	
	strx = "�U �������ܶ"CYN + query("total_gold")+ NOR"���ƽ�"+"/"CYN+query("total_score")+NOR"������";
	strx = ngstr(strx +NOR,44);
	write( strx+"���ƣ�������  �U\n");
	
//	write("�U ����ǰ˰�ʣ�"CYN"��2.0%"NOR"������ ������ ������ �����ƣ����������U\n");
	
	write("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");

	return 1;

}

int valid_enter(object me)
{
	int flag;
	int g, n;
			int t,s;
	int gold;
// means no enter at the beginning.
	int enter = 0;
        flag = (int) query("room_flag");
// always let owner go in:
	if(is_owner(me->query("id")))
		enter = 1;
//  if(flag & 16)
//		enter = 1;
	if(flag & 32)	
		enter = 1;	
	if(query_temp("invite/"+me->query("id")))
		enter = 1;	

//  Upkeep cost already payed?

	if (query("expired") && query("basic_tax") != -1)
	{
		// ������д׷�ɺ�ʽ
		enter = 0;
		if(is_owner(me->query("id")))
		{
			n = query("expired")/7 + 1;		// Ƿ�����ܽ�����
			t = query_tax()*n;
			s = query_stax()*n;
			tell_object(me,WHT"����"+ chinese_number(n)+"����δ��ά�ַ��á�\n"NOR);
			
			if (query("expired")> 7) {
				tell_object(me,WHT"ϵͳһ�����ֻ�������ܵ�ά�ַ��ã���ӭ�ص���Ϸ��\n"NOR);
				t = query_tax()*2;
				s = query_stax()*2;
			}
						
			gold  = this_player()->query("deposit")/100;					
			if(gold < t)
			{
				tell_object(me,"�������Ϲ���û�д湻"+chinese_number(t)+"�����ӡ���\n");
				return 0;
			}
			
			if(me->query("score") < s/100)
			{
				tell_object(me,"��������۲���"+chinese_number(s/100)+"�㣡��\n");
				return 0;
			}
			me->add("deposit",-t*100);
			me->add("score",-s/100);
			tell_object(me,YEL"�㲹������Ƿ��ά�ַ��ã�"+t+"�����ӡ�"+(s/100)+"�����ۣ���\n"NOR);
			add("already_pay",t);
			add("already_spay",s/100);
			set("expired",0);
			set("charged",1);		// ���� expiredʱ���Ǽ��㵽��һ�ܵģ�Ҳ����˵��������İ�����һ����
			reset_pay_time();

			if( !balance_s() && !balance_g()) {
				set("basic_tax",-1);
				log_file("annie_log_buildroom", 
					sprintf("Payoff: [%s] %s(%s)���Խ�����%s�Ѿ�����������Ϊ%s��\n",
					ctime(time()), 
					me->query("name"),
					me->query("id"),
					query("short"),
					base_name(this_object())));
				tell_object(me,HIR"��ϲ����������Ѿ���������ӵ����ȫ����Ȩ�ˣ���\n"NOR);
			}

			save();
			enter = 1;
		}
	}

	if (!enter && query("expired") && query("basic_tax")!=-1)
		tell_object(me,"�÷���Ƿ��δ�룬��ʱ�޷����룡\n");
		
	return enter;
}

int do_invite(string arg)
{
	object me;
	mapping invite_list;
	int i;
	string *lists;
	me= this_player();
	if(!is_owner(me->query("id")))
		return 0;
	
	invite_list = query_temp("invite");
	
	if (arg) {
		if (mapp(invite_list))
			lists = keys(invite_list);
		if (lists && sizeof(lists))
		if (member_array(arg,lists)!= -1){
			delete_temp("invite/"+arg);
			write("���"+arg+"�ӿ���������ɾȥ�ˡ�\n");
			return 1;
		}
		set_temp("invite/"+arg,1);
		write("������"+arg+"����ķ��䡣\n");
		return 1;
	}
	
	invite_list = query_temp("invite");
	
	write(WHT"\t��������������\n"NOR);
	write(HIR BLK"��������������������������������\n"NOR);
	if( !mapp(invite_list) || !sizeof(invite_list) )
	{
		write("û�������κ��ˡ�\n");
		write(HIR BLK"��������������������������������\n"NOR);
		return 1;
	}
	lists = keys(invite_list);
	for(i=0; i<sizeof(lists); i++)
		write(lists[i]+"\n");
	write(HIR BLK"��������������������������������\n"NOR);
	return 1;
}

int do_setowner(string arg)
{
	string oldowner;
	if (!wizardp(this_player()) && !is_owner(this_player()->query("id")))
		return 0;
	oldowner = (string)query("temp_owner");
	set("temp_owner",arg);
	write("�㽫�����������ʱ��Ϊ"+arg+"��\n");
	call_out("set_back",60, oldowner);
	return 1;
}

int do_share(string arg)
{
	object me;
	
	me= this_player();
	if((string)me->query("id") != query("owner"))
		return 0;
	if (!me->query("marry") )
		return notify_fail("��ֻ���������һ������䡣\n");
	if (!arg)
		return notify_fail("����ָ��Ϊ��share <id>��\n");
	if (arg != me->query("marry"))
		return notify_fail("��ֻ���������һ������䡣\n");
	if (arg == query("owner"))
		return notify_fail("���Լ�����Ϊ�ڶ������ˣ������⣮����\n");
	if (query("couple"))
		return notify_fail("��ֻ������һ�η���ĵڶ����ˣ�\n");
	if (!find_player(arg))
		return notify_fail("�ڶ����˱�����������ʱ���á�\n");
	set("couple",arg);
	write("������˷���ĵڶ����ˣ�"+arg+"��\n");
	tell_object(find_player(arg),me->query("name")+"��������Ϊ"+query("short")+"����ĵڶ����ˡ�\n");
	return 1;
}

int set_back(string oldowner)
{
	set("temp_owner", oldowner);
	return 1;
}


string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+".room"+query("timestamp")+".o");
}

int save()
{
        string file;
        int result;
		seteuid(query("owner"));
        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                return result;
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file))
                return 1;
        return 0;
}

int restore_item()
{
	object box,item;
	mapping item_list;
	string *lists,mitem;
	int i,idx;
/*
	box = new("/obj/item/box");
	box->move(this_object());

	item_list = query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return 1;
	// û���κζ�����

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = query("item_list/"+lists[i]);
		item = new(mitem["item_basename"]);
		annie_itemmimic(item,mitem["data"],mitem["temp_data"]);
		item->set_name(mitem["item_name"],mitem["item_id"]);
		item->set_amount(mitem["amount"]);
		item->move(box);
	}
*/
	item_list = query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return 1;
	// û���κζ�����

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = query("item_list/"+lists[i]);
		item = new(mitem);
		item->move(this_object());
		item->set("no_reset",1);
		item->restore_item();
	}
	return 1;
}

void reset()
{
	object *inv;
	int i;
	::reset();

	inv = all_inventory(this_object());
	for (i=0;i<sizeof(inv) ;i++ )
	{
		if (!inv[i]->query("item_type"))	continue;
		inv[i]->reset_item_list(inv[i]);	// save
	}
	return ;
}


int check_legal_long(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 120) || (strlen(name) > 600 ) ) {
                write("�Բ�������������������ʮ�����ٸ������֡�"+strlen(name)+"\n");
                return 0;
        }
        while(i--) {
		if(name[i]==' ' || name[i] == '\n') continue;
                if( name[i]<' ' ) {
                        write("�Բ����������������ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ����������������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

int enter_desc(object me, object room, string text){

	if(!check_legal_long(text)) return 1;
	
	if (me->query("deposit")< 50000) {
		tell_object(me, "������д�����������Ҫ�����ƽ�\n");
		return 1;
	}
	me->add("deposit",-50000);
	
	room->set("long", text);
	room->add("renovation",1);
	room->set("renovation_time",time());
	room->save();
	me->save();
	write("���������޸ĳɹ�������\n");
	return 1;
}


int input_description(){
	object me, env;
	me = this_player();
	
	if(!is_owner(me->query("id")))
		return notify_fail ("���¶�ֻ�����˲�����������\n");
		
	env = environment(me);
	if (env->query("renovation_time")+ 600> time())
		return notify_fail("װ�����ӵļ��ʱ�䲻������ʮ���ӡ�\n");
		
	if (me->query("deposit")< 50000)
		return notify_fail("������д�����������Ҫ�����ƽ�\n");
		
	me->edit( (: enter_desc , me, env :) );
	return 1;
}




/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
