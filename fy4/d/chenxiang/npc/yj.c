// (C)1998-2000 Tie Yu
#include <ansi.h>
inherit NPC;
int tell_him();
int wakeup(object me);
int warning();

void create()
{
    	set_name("Ԭ��", ({ "queen yuanji","yuanji" }) );
    	set("gender", "Ů��" );
    	set("long","Ԭ�����׹�����Ѳʱ�����ѡ����Ů�����ձ�Ҫ���빬�С�\n");
    	set("age", 25);
    	set("combat_exp", 7000);
    	set("attitude", "friendly");
    	set("per",30);
    	set("chat_chance", 1);
    	set("chat_msg", ({
        		"Ԭ��������꣬�����̾�˿��������������ƺ��л������ĳ\n",
        		"Ԭ����Ȼ�������ӣ�ֻ�������ټ��ˡ�\n",
        }) );
    	set("inquiry", ([
        	"�岨����" : (: tell_him :),
        	"����" :  	(: tell_him :),
        	"qingbo" : 	(: tell_him :),
        	"����":		(: warning :),
        	"����":		"����������Һ��岨�����žۣ���������ǵĴ���ˡ�\n",
        	"�����":	"����������Һ��岨�����žۣ���������ǵĴ���ˡ�\n",
        ]));

    	setup();
    	carry_object(__DIR__"obj/scloth")->wear();
}

int warning(){
	
	object me= this_player();
	object dai;
	
	
	if (query("drugged")){
		message_vision(CYN"Ԭ���ճյؿ���$N��ЦЦ���ƺ���֪������˵Щʲô��\n"NOR, this_player());
		return 1;
	}
	
	if (REWARD_D->check_m_success(me,"���ȵ��")
		|| REWARD_D->riddle_check(me,"���ȵ��")!=10
		|| REWARD_D->riddle_check(me,"���о�")!= 1)
	{
		command("doubt");
		return 1;
	}
	
	command("doubt");
	
	tell_object(me,YEL"��Ȼ����������������ú���һ�������Ǳ�����Ѩ�����������á�\n"NOR);
	me->start_busy(10);		// ����
	
	dai = new(__DIR__"gaibang3");
	if (dai) dai ->move(environment());
	
	message_vision("\n�������˹�����\n",dai);
	message_vision("\n�������ĵذ����ɢ����Ԭ�����С�
	
Ԭ���м��ؿ��˴���һ�ۣ�һ�ڽ�ҩ��������ȥ��\n\n",dai);

	
	message_vision(CYN"Ԭ�������ؽ���һ�������ӣ����������ˣ�
	
Ԭ��һͷ�Ե��������ˡ�\n"NOR, me);

	if (dai)	destruct(dai);
	set("NO_KILL","��˳���������Ů�ӣ�����ô�µ����֣�\n");
	set("drugged",1);
	set_temp("is_unconcious",1);
	disable_player(" <������>");
	set("disable_type",HIG "<������>" NOR);
	call_out("wakeup", 10, me);
	
	tell_object(me,WHT"\n�������п��ȴһ����Ҳ�²���������\n\n"NOR);
	return 1;
	
	
}


int tell_him(){
	
	if (!query("drugged"))
	{
		command("say ���ӣ�ֻ�������ټ��ˡ�");
		return 1;
	}
	
	message_vision(CYN"Ԭ���ճյؿ���$N��ЦЦ���ƺ���֪������˵Щʲô��\n"NOR, this_player());
	return 1;
}

int accept_object(object me, object ob) {
	
	if (is_fighting())	return 0;
		
	if (REWARD_D->check_m_success(me,"���ȵ��"))
	{
		command("doubt");
		return 0;
	}	
	
	if (query("drugged"))
	{
		message_vision("Ԭ���ճյس�$NЦ��Ц˵���Ҿ�Ҫ�����ˣ�����ʲô���С�\n",me);	
		return 0;
	}
	
	if (REWARD_D->riddle_check(me,"���ȵ��") == 9)
	{
		command("pei");
		command("say �������׹����İ���ô�����������ӣ��Ҳ���Ҫ�κζ�����");
		return 0;
	}	
	
	if (REWARD_D->riddle_check(me,"���ȵ��")!= 10)	return 0;
	
	if (ob->query("name")!= "���ɢ" || ob->query("real")!=2) return 0;
		
	tell_object(me,YEL"����˲�ע�⣬���ĵذ����ɢ����Ԭ�����С�
	
Ԭ���м��ؿ�����һ�ۣ�һ�ڽ�ҩ��������ȥ��\n\n"NOR);

	
	message_vision(CYN"Ԭ�������ؽ���һ�������ӣ����������ˣ�
	
Ԭ��һͷ�Ե��������ˡ�\n"NOR, me);

	set("NO_KILL","��˳���������Ů�ӣ�����ô�µ����֣�\n");
	set("drugged",1);
	set_temp("is_unconcious",1);
	disable_player(" <������>");
	set("disable_type",HIG "<������>" NOR);
	call_out("wakeup", 10, me);
	me->start_busy(10);		// ����
	tell_object(me,WHT"\n�����д�ϲ�����ڴ󹦸���ˣ�\n"NOR);
	return 1;
}
	
int wakeup(object me){
	
	object mi, gold;
	
	mi = present("mi gonggong");
	
	message_vision("Ԭ������һ���������شӵ�������������������\n\n", this_object());
	delete_temp("is_uncooncious");
	delete("disable_type");
	
	if (!me || environment(me) != environment())	{
		delete("NO_KILL");
		return 1;
	}
	
	if (!REWARD_D->riddle_check(me,"���о�")) {	
		tell_object(me,WHT"������һ��������������е㲻̫��ͷ��ҩ�Թ�ȥҲ̫���ˣ�\n"NOR);
	}
	
	message_vision(CYN"
ֻ���Ա�ؽؽؽ������Ц���׹������������˹�����
	
�׹���˵��Ԭ���ʱ���ѵ������Ǹý����ˣ��Ӵ��ٻ��������ò�����

Ԭ���ƺ���Щ��Ϳ������������˭���������ǣ�

�׹������Ƶ�����"YEL"����ɢ"CYN"��Ȼ�����鴫��С�ӣ��������ˣ�\n\n",me);


	if (REWARD_D->riddle_check(me,"���о�")==1) {
		message_vision("�׹����Դ���˵�������ƽ���ʮ�����������ͷ��\n"NOR, me);
	}
	else
	{
		message_vision("�׹�����$N˵�������ƽ���ʮ�����������ͷ��\n"NOR, me);
		gold= new("/obj/money/gold");
		gold->set_amount(50);
		if (!gold->move(me))
		gold->move(environment());
	}		
	
	message_vision(YEL"\n\n�׹�����ָ�ų�һֻ��ɫ���Ÿ룬����һ��������Ԭ���Ͻηɳ۶�ȥ��\n\n", me);
	
	if (REWARD_D->riddle_check(me,"���о�")==1) {
		
		tell_object(me,CYN"������������������Թ�ң�Ԭ����ȴ��ȥ�������ڼ���δ�ز��ǽ��ѡ�
�������壬���Ǻڰ׷���֮�¡�˵�գ��Ŀ����Ѩ����������ȥ��\n\n"NOR);
		
		REWARD_D->riddle_done(me,"���ȵ��", 0, 2);
		REWARD_D->riddle_set(me,"���о�",2);
				
		tell_object(me,WHT"\n�µ�������Ȼ"YEL"��"WHT"�����δȻ��еĺ��塣\n\n"NOR);
		
		
	} else 
	{
		tell_object(me,WHT"���Ȼ���ף�ԭ�����ͷ���׾���һ���֣������������е�һ���壡
	
�����д�ڣ����ǣ��Ѿ��޷�����ˡ���������\n"NOR);
		REWARD_D->riddle_done(me,"���ȵ��", 50, 1);
	}
		
	destruct(mi);
	destruct(this_object());
}

	
	



	

	