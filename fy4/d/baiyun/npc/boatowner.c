//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit NPC;
#include <ansi.h>

int do_boat();
int do_raft();

void create()
{
	set_name("���ƹ�", ({ "old zhanggui", "zhanggui" }) );
	set("gender", "����" );
	set("age", 69);
	set("long","��λ���е����ƹ�����æ������ž�������������ˡ�\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("inquiry",([
		"ľ��": (:do_raft():),
		"raft": (:do_raft():),
		"С��": (:do_boat():),
		"boat": (:do_boat():),
	]));	
				
	set("NO_KILL","ɱ����������ôȥ���Ƶ��أ�\n");
	set_skill("unarmed",200);
	set_skill("dodge",200);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

int do_raft(){
	object who;
	int price;
	object paper;
	string msg;
	
	who = this_player();
	
	if (!who->query("env/e_money")) {
		ccommand("say ������͹��ƺ�û���ĺ��𿨣�С���޷����˰���");
		return 1;
	}
	
	price = 100;
	
	if (who->query("deposit")< price) {
		command("say ������͹ٺ����������е���ת������");
		return 1;
	}
	
	MONEY_D->charge_him(who,price);
	
	paper = new(__DIR__"obj/contract");
   	paper->set("shiptype", price/500);
	
	paper->set("employer",who->query("name"));	
	paper->move(who);	
	
	command("say ��л��λ" + RANK_D->query_respect(who) +
	     "��˱����У�����������Լ����ͷ���Ϻ��ꡣ\n");
	
	msg = CYN"���ƹ��˿�$N��̾����˵�����������⺣�Ϸ���˼�����λ�͹ٿ���û�����Ƶ��͡���������\n"NOR;
	
	if (paper->query("shiptype") == 0 && who->query_skill("dodge",1)< 60)
	{	
		message_vision(msg, who);
		tell_object(who,"����60����Ծ����֮����������\n");	
	} else if (paper->query("shiptype") == 1 && who->query_skill("dodge",1) < 30)
	{
		message_vision(msg, who);
		tell_object(who,"����30����Ծ����֮����������\n");	
	}	
	    
	return 1;
	
}

int do_boat(){
	object who;
	int price;
	object paper;
	string msg;
	
	who = this_player();
	
	if (!who->query("env/e_money")) {
		ccommand("say ������͹��ƺ�û���ĺ��𿨣�С���޷����˰���");
		return 1;
	}
	
	price = 500;
	
	if (who->query("deposit")< price) {
		command("say ������͹ٺ����������е���ת������");
		return 1;
	}
	
	MONEY_D->charge_him(who,price);
	
	paper = new(__DIR__"obj/contract");
   	paper->set("shiptype", price/500);
	
	paper->set("employer",who->query("name"));	
	paper->move(who);	
	
	command("say ��л��λ" + RANK_D->query_respect(who) +
	     "��˱����У�����������Լ����ͷ���Ϻ��ꡣ\n");
	
	msg = CYN"���ƹ��˿�$N��̾����˵�����������⺣�Ϸ���˼�����λ�͹ٿ���û�����Ƶ��͡���������\n"NOR;
	
	if (paper->query("shiptype") == 0 && who->query_skill("dodge",1)< 60)
	{	
		message_vision(msg, who);
		tell_object(who,"����60����Ծ����֮����������\n");	
	} else if (paper->query("shiptype") == 1 && who->query_skill("dodge",1) < 30)
	{
		message_vision(msg, who);
		tell_object(who,"����30����Ծ����֮����������\n");	
	}	
	    
	return 1;
	
}

void init()
{       
	object ob;
	::init();
	if ( interactive(ob = this_player()) && !is_fighting() ) 
	   {
	     remove_call_out("greeting");
	     call_out("greeting", 1, ob);
	   }
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) 
	      {
		case 0:
		message_vision("$N�������ϻ��ۿ���$nһ�ۣ�˵������ӭ��λ"+RANK_D->query_respect(ob)+
			       "���ٱ����У�\n",this_object(),ob);
		break;
		
		case 1:
		message_vision("$N���ᴷ�˴�����ļ��˵������λ"+RANK_D->query_respect(ob)+
			       "��Ҫ��ʲô��ʽ�Ĵ���\n",this_object(),ob);
 		break;
 		
        case 2:
		message_vision("$N˵������Ҫѯ���⴬�ļ۸���ο�����ļ۸��ƣ�����\n",this_object(),ob);
	      }
}

int accept_object(object who, object ob)
{
	int val;
	object paper;
	string msg;
	
//	message_vision(CYN"$N˵������̫�󣬺�����ͣ��\n"NOR,this_object());
//	return 0;
	val = ob->value();
    if ( val < 100 ) 
	{
		message_vision("$N������üͷ������λ�͹٣�Ǯ��������\n",this_object());
		return 0;
	}
	
	if (val > 1000 )
	{
		  message_vision("$N��Ц�����󺣴��Դ����ϴ��Ǹ�����üë��ү�����󣬾���Ҳû��������������\n",this_object());
			return 0;
	}	
	
	paper = new(__DIR__"obj/contract");
    if ( val>=100 && val < 500 ) 
    	paper->set("shiptype", 0);
    else if ( val >= 500 && val < 10000 ) 
    	paper->set("shiptype", 1);
    else if ( val >=10000) 
    	paper->set("shiptype", 2);
	
	paper->set("employer",who->query("name"));	
	paper->move(who);	
	
	command("say ��л��λ" + RANK_D->query_respect(who) +
	     "��˱����У�����������Լ����ͷ���Ϻ��ꡣ\n");
	
	msg = CYN"���ƹ��˿�$N��̾����˵�����������⺣�Ϸ���˼�����λ�͹ٿ���û�����Ƶ��͡���������\n"NOR;
	
	if (paper->query("shiptype") == 0 && who->query_skill("dodge",1)< 60)
	{	
		message_vision(msg, who);
		tell_object(who,"����60����Ծ����֮����������\n");	
	} else if (paper->query("shiptype") == 1 && who->query_skill("dodge",1) < 30)
	{
		message_vision(msg, who);
		tell_object(who,"����30����Ծ����֮����������\n");	
	}	
	    
	return 1;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
