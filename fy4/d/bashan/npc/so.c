#include <ansi.h>
inherit NPC;
int lotto();
int listx();
int start=0;

string *lottoo=({"��͢","ؤ��","��Ǯ��","������","������","�˹���","�䵱","��ɽ","��ɽ","������","�����","���Ƴ�","ħ��","���ʮ��","���幬","��ˮ��","��¹�","��÷ɽׯ","��ѩɽׯ","��ɽׯ","����ɽׯ","�仨���",});

void create()
{
    set_name("��ܰ", ({"su"}) );
    set("gender", "Ů��" );
    set("attitude", "friendly");
    set("age",32);
    set("NO_KILL",1);

    setup();
}

int do_look(string arg)
{
    if (!arg)
	return 0;
    if (present(arg,environment()) != this_object())
	return 0;
    write(CYN"
��ܰ΢Ц������������͸���ʵ�"+(ANNIE_D->lotto_get_roll_round()+1)+"�ڡ�
��ܰ΢Ц������һ��"+ANNIE_D->lotto_get_roll_result()+"��\n\n"NOR);
	write(CYN"��ܰ΢Ц���������������ʹ������ָ�
lottolist ��ѯ���Ѿ�����Ĳ�ȯ
purchase <��Ŀ>һ��֧��һ��Ǯ������Ϊ��������ȡһЩ��ȯ
checkout ������һ�ڵĲʽ�\n\n"NOR);
	write("��������Լʮ���ꡣ
��"HIG"���Ľ��ޣ���������ɢ����������ջ�"NOR"
��"CYN"��̬��ӯ"NOR"���书����������"BLU"��ѧէ��"NOR"�������ƺ����ᡣ
��"HIG"�������ϲ���˿���˺ۡ�"NOR"
�����������(Cloth)��\n");
	return 1;
}

int checkout()
{
	object me = this_player();
	mapping data;
	int i,j;
	int r1,r2,r3,r4,r5;

	int l1=1000,l2=200,l3=50,l4=20,l5=5;

/*
// L2����gold�ˡ�-- ��Щ��������һ�Ȱ�
	string *l2_reward = ({
"/obj/specials/annie/seal",
"/obj/specials/annie/peach",
"/obj/specials/annie/magicfan",
"/obj/specials/annie/evileye",
	}) ;
*/
	int b;

	string arg;
	object obj;

	if (time()-query("last_work") < 2)
		return notify_fail(CYN"��ܰ΢Ц����ܰ������busy�У��͹����Դ�Ƭ�̡�\n"NOR);
	set("last_work",time());

	if (ANNIE_D->lotto_get_roll_round() == me->query("lotto_roll"))
		return notify_fail(CYN"��ܰ΢Ц������λ�͹٣����Ѿ��һ������ڵĲ�ȯ�ˡ�\n"NOR);
	me->set("lotto_roll",ANNIE_D->lotto_get_roll_round());

	data=ANNIE_D->lotto_checkout(me->query("id"));
	r1=data["r1"];
	r2=data["r2"];
	r3=data["r3"];
	r4=data["r4"];
	r5=data["r5"];
	arg=CYN"�������صȽ�"+r1+"ע���õ��ƽ�"+r1*l1+"����\n";
	arg += "һ�Ƚ�"+r2+"ע���õ��ƽ�"+r2*l2+"����\n";

/*	arg += "һ�Ƚ�"+r2+"ע���õ�";
	if (r2 == 0)
		arg += "�ƽ�0��";
	else
	for (i=0;i<r2 ;i++ )
	{
		obj = new(l2_reward[random(sizeof(l2_reward))]);
		obj->move(me);
		arg += obj->name()+CYN"һ"+obj->query("unit");
		if (i < r2-1)
			arg += "��";
	}
	arg += "��\n";*/
	arg += "���Ƚ�"+r3+"ע���õ��ƽ�"+r3*l3+"����\n���Ƚ�"+r4+"ע���õ��ƽ�"+r4*l4+"����\n��ο��"+r5+"ע���õ��ƽ�"+r5*l5+"����";
	b=r1*l1+r2*l2+r3*l3+r4*l4+r5*l5;
	arg += "���ƻƽ�"+chinese_number(b)+"����\n\n"NOR;
	ANNIE_D->lotto_pay_money(b);
	tell_object(me,arg);
	me->add("deposit",b*10000);
	// timer: ÿ��countֻ��ִ��һ��(��Դռ�ô�)
	return 1;
}

int listx()
{
	object me = this_player();
	mapping data;
	mapping player_data;
	int i,left;
	string outp;
	string *mterm;
	int nnr;

	if (time()-query("last_work") < 2) {
		tell_object(CYN"��ܰ��æ�����Դ�Ƭ�̡�\n"NOR);
		return 1;
	}
	set("last_work",time());


	left = find_call_out("do_process");
	if (left>0)
		tell_object(me,"��ܰ˵��ÿ��Сʱ����һ�Σ����´λ���"+ chinese_number(left/60)+"���ӡ�\n");
	
	data = ANNIE_D->lotto_getlist(me->query("id"));
   	set_eval_limit(1); 
	if(!mapp(data) || !sizeof(data))
	{
		tell_object(me,"��û�й����κε���͸��ȯ��\n");
		return 1;
	}
	else
	{
		tell_object(me,CYN"�㹺�����͸��ȯ�У�\n"NOR);

		mterm = keys(data);
		nnr=sizeof(mterm);
		if (nnr>20)
			nnr=20;

		for(i=0;i<nnr;i++)
		{
	    	reset_eval_cost();
			outp=data[mterm[i]];
			player_data=ANNIE_D->lotto_get_player_data(outp);
			
			tell_object(me,sprintf(HIR BLK"��"HIY"%d"NOR HIR BLK"�ڣ�"NOR WHT"%s��%s��%s��%s��%s\n"NOR,player_data["round"],lottoo[player_data["num1"]-1],lottoo[player_data["num2"]-1],lottoo[player_data["num3"]-1],lottoo[player_data["num4"]-1],lottoo[player_data["num5"]-1]));
		}       
		if (nnr == 20)
			tell_object(me,"��������ȯ̫�࣬δ��һ��������\n");

		return 1;
	}
}

int lotto()
{
	object me = this_player();
	string file;
	if (me->query("deposit") < 10000)
	{
		tell_object(me,CYN"��ܰ΢Ц������ȷ�������Ϲ������㹻��ÿעһ���ƽ�\n"NOR);
		return 1;
	}
	write(CLR);
	file = "/doc/lotto";
	write(read_file(file));
	me->delete_temp("lotto");
	tell_object(me,"��ѡ���һ�����ɣ�");
	input_to("selete_main",me,file,1);
	me->add_temp("block_msg/all",1);
	return 1;
}

int buyx(string arg)
{
	object me = this_player();
	string file;
	int amount,range=22,i;
	int i1,i2,i3,i4,i5;

	if (time()-query("last_work") < 2){
		tell_object(me,CYN"��ܰ����æ�أ����Դ�Ƭ�̡�\n"NOR);
		return 1;
	}
	
	set("last_work",time());
	if (!arg){
		tell_object(me,"���������������ٱʲ�ȯ��\n");
		return 1;
	}
	
	amount=atoi(arg);
	if (amount + "" != arg){
		tell_object(me,"���������������ٱʲ�ȯ��\n");
		return 1;
	}
	
	if (amount < 0) {
		tell_object(me,"�����������е�Ҳ�Ǹ�����\n");
		return 1;
	}
		
	if (amount > 100) {
		tell_object(me,"��һ�����ֻ�ܹ���һ�ٱʡ�\n");
		return 1;
	}
	
	if (me->query("deposit") < amount*10000)
	{
		tell_object(me,CYN"��ܰ΢Ц������ȷ�������Ϲ������㹻��ÿעһ���ƽ�\n"NOR);
		return 1;
	}
	
   	set_eval_limit(1); 
	for (i=0; i<amount; i++)
	{
    	reset_eval_cost();
		i1=random(range)+1;
		i2 = random(range)+1;
		i3 = random(range)+1;
		i4 = random(range)+1;
		i5 = random(range)+1;
		while (i1 == i2)
			i2 = random(range)+1;
		while (i1 == i3 || i2 == i3)
			i3 = random(range)+1;
		while (i1 == i4 || i2 == i4 || i3 == i4)
			i4 = random(range)+1;
		while (i1 == i5 || i2 == i5 || i3 == i5 || i4 == i5)
			i5 = random(range)+1;
		arg=i1+"-"+i2+"-"+i3+"-"+i4+"-"+i5;
		ANNIE_D->lotto_swarm_add(this_player(),arg);
	}
	ANNIE_D->lotto_prog();
	me->add("deposit",-amount*10000);
	tell_object(me,CYN"��ܰ΢Ц�������Ѿ�������"+chinese_number(amount)+"ע��ȯ������lottolistָ��鿴��\n"NOR);
	return 1;
}

void sel(object me)
{
	int i,j,flag=0;
	string msg;
	string arg="";
	for (i=1;i<=5 ; i++)
		for (j=i+1;j<=5 ;j++ )
			if (me->query_temp("lotto/"+i) == me->query_temp("lotto/"+j))
				flag=1;
	if (flag == 1)
	{
		tell_object(me,HIW"���ܶ��ѡ����ͬ�����ɣ�\n"NOR);
		return;
	}
	if (me->query("deposit") < 10000)
	{
		tell_object(me,CYN"��ܰ΢Ц������ȷ�������Ϲ������㹻��ÿעһ���ƽ�\n"NOR);
		return ;
	}
	me->add("deposit",-10000);
	for (i=1;i<5 ; i++)
		arg+=me->query_temp("lotto/"+i)+"-";
	arg += me->query_temp("lotto/5");
	msg=WHT"������һ��д�š�"HIM;
	for (i=1;i<5 ; i++)
		msg+=lottoo[atoi(me->query_temp("lotto/"+i))-1]+NOR WHT"��"HIM;
	msg += lottoo[atoi(me->query_temp("lotto/5"))-1]+NOR WHT"������͸��ȯ��\n"NOR;
	tell_object(me,msg);
	ANNIE_D->lotto_add(this_player(),arg);
	return;
}
	
void selete_main (string num, object me, string file,int count)
{
	if (!num || atoi(num)<1 || atoi(num) > 22 || atoi(num)+"" != num)
	{
		input_to("selete_main",me,file,count);
		return ;
	}
	me->set_temp("lotto/"+count,num);
	count++;
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
	if (count >= 6)
	{
		sel(me);
		return ;
	}
	tell_object(me,"��ѡ���"+chinese_number(count)+"�����ɣ�");
	me->add_temp("block_msg/all",1);
	input_to("selete_main",me,file,count);
	return ;
}

int init()
{
	add_action("do_look","look");
//	add_action("do_bet","bet");
//	add_action("do_bett","bett");
	add_action("do_next","next");
//	add_action("lotto","choose");	--- BUGGED
	add_action("listx","lottolist");
	add_action("buyx","purchase");
	add_action("checkout","checkout");
	if (environment() && !start) {
		call_out("do_promote",10200,this_object());
		call_out("do_process",10800,this_object());
		start = 1;
	}	
}

int do_bet(string arg)
{
	ANNIE_D->lotto_add(this_player(),arg);
	write("Ok.\n");
	return 1;
}

int do_bett(string arg)
{
	int i;
   	set_eval_limit(1); 
	for (i=0; i<1000; i++)
	{
    	reset_eval_cost();
		this_player()->ccommand("bet 1-2-3-4-5");
		this_player()->ccommand("next");
	}
	return 1;
}

int do_promote(object ob){
	CHANNEL_D->do_channel(this_object(),"announce","���Ʋ�ȯ����ʮ���Ӿ�Ҫ�����ˣ���ӭ���ӻԾ����");
	call_out("do_promote", 10800, ob);
	return 1;
}

int do_process(object ob){
	
	ANNIE_D->lotto_roll(ob);
	call_out("do_process",10800,ob);	
	return 1;
}


int do_next()
{
	if (!wizardp(this_player()))	
		return 0;
	remove_call_out("do_process");
	do_process(this_object());	
	return 1;
}

/*
fengyun-
�ƾ����մ���ˮ���껪��ʶ���Էɡ���
dancing_faery@hotmail.com
annie.01.01.2004
*/

// update here;update /adm/daemons/annied;update /d/bashan/npc/so;clone;
