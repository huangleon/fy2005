#include <ansi.h>
inherit NPC;
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
	set_name("���꾫", ({ "foxgirl" }) );
	set("gender", "Ů��" );
	set("class","huashan");
	set("age", 29);
	set("title", "���ǵ��� �ϰ���");
	set("long","
���꾫����ĸ���꣬��Ȼ���Ϻ���ķ��ˣ��Ϻ�������ţ�
�����ѵ�Ȼ����ĸ���������ӵ������һ������ò������
һ������Ӱ��û����֪���������������뷨����ͺ��꾫����
�ˣ������书��ߣ�����һȥ��������һ�㣬��һ
���ĺ��꾫�������˲������ĺ��꾫��\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",30);
	set("no_arrest",1);
	set_skill("unarmed",600);
	set("richness",100000);
	set_skill("dodge",200);
	set_skill("zhaixin-claw",50);
	map_skill("unarmed","zhaixin-claw");
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.zhaixin" :),
        }) );
	
	setup();
	carry_object("/obj/armor/skirt", 
			([	"name" 	:	HIY "��" + HIR "��"NOR + "����ȹ",
				"long"	: 	"һ�����˿��ɵĽ���ȹ\n",
				"armor_prop/armor" : 	3  ])	
			)->wear();
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
    add_action("do_answer", "answer");
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
	add_action("do_sell", "sell");
	add_action("do_redeem", "redeem");
	add_action("do_vendor_list","list");
}

int do_answer(string arg)
{
	object me = this_object();
	object ob = this_player();
	string a1;
	int a2;
	

	if (!arg)
		return 0;

	if (!ob->query_temp("annie/baiyun_1_2_3") || REWARD_D->riddle_check(ob,"����") != 2)
		return 0;
	
	if (ob->query_temp("annie/baiyun_1_2_3") == 1)
	{
		a1 = arg[0..7];
		if (crypt(a1,"jBsRnh8nhUvA6") != "jBsRnh8nhUvA6")
		{
			command("heihei");
			return 1;
		}
		a1=arg[8..];
		if (crypt(a1,"eN/NQj5KBYxXk") != "eN/NQj5KBYxXk")
		{
			command("heihei");
			return 1;
		}
		tell_object(ob,CYN"��˵����"+arg+"\n"NOR);
		ccommand("hmm");
		ob->set_temp("annie/baiyun_1_2_3",2);
		ccommand("say �ĸ�������");
		return 1;
	}
	if (crypt(arg,"BkxpD7mnSS3p.") != "BkxpD7mnSS3p." && crypt(arg,"UkMcu7/.un9HU") != "UkMcu7/.un9HU" )
	{
		command("heihei");
		return 1;
	}
	tell_object(ob,CYN"��˵����"+arg+"\n"NOR);
	ccommand("emote ����ͷ�����ʣ����Ȱ������Ƕ�����û�У�");
	ccommand("emote ���һ�����⣬�������޵ع���һĨǳЦ��");
    REWARD_D->riddle_set(ob,"����",3);
	return 1;
}

void greeting(object ob)
{
	if ( !ob || environment(ob) != environment() ) return;
	if (REWARD_D->riddle_check(ob,"����") == 2)
	{
		message_vision("$N����$n���˽�������ɫһ�䣬������$n��������������\n",this_object(),ob);
		ob->set_temp("annie/baiyun_1_2_3",1);
		return;
	}


	if ( ob->query("gender") == "����")
	   {
	     switch( random(3) ) 
		{
		  case 0:
		  message_vision("$N����������˵�������������ϣ�������λ"+RANK_D->query_respect(ob)+
"������䵱Щʲô������Ʒ��\n",this_object(),ob);	
		  break;

		  case 1:
		  message_vision("$N��ǰ��ס$n���֣�Ц�����˵������λ"+RANK_D->query_respect(ob)+
"����������ϴ������ʱ���ߴ����ͣ�Ӣ�������ˣ���\n",this_object(),ob);
		  break;
		  
		}
	   }
	else
	   {
	     switch( random(3) ) 
		{
		  case 0:
		  message_vision("$N��ǰ�ḧ$n�ķ�����˵������λ"+RANK_D->query_respect(ob)+
"����������£����������ˣ�\n",this_object(),ob);
		  break;
		  
		  case 1:
		  message_vision("$N��ǰ��ס$n���֣�Ц�����˵������λ"+RANK_D->query_respect(ob)+
"������䵱Щʲô������Ʒ��\n",this_object(),ob);
		  break;
                }
	   }		
}

