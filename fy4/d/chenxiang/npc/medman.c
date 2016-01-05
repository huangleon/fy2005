#include <ansi.h>
inherit SMART_NPC;

int init_quest();

void create()
{
	set_name("��ҩ���ϰ�", ({ "medman" }) );
	set("gender", "����" );
	set("age", 75);
	set("long","һ����æ�ò��ɿ�������ҩ���ϰ壬������������\n");
	set("combat_exp", 5000000);
	set("attitude", "friendly");
	set("per",1);
    set("inquiry", ([
        "���鲹Ѫ����" : "�����Ҫ�򣺱��Σ���ɽ�����Σ���ӣ��͵��飮\n",
		"soup" : "�����Ҫ�򣺱��Σ���ɽ�����Σ���ӣ��͵��飮\n",
        "���ɢ":	(: init_quest :),
        "ͷ��":		"���ֻ�����Լ���취�ˡ�\n",
        "����":		"��˵������������ˣ��۾������軹��Բ����������Ҫȥ������
�����ȥ�����ף�����С���ѱ�����\n",
        "����":		"��ҹ����������ǰ�����߽��ڴ˵أ�����Ĵ��鿴��\n",
        "����":	"��˵����Ķ�������˭�أ�\n",
        "����":		"�������ҵ�Զ��ֶ�ӡ�\n",
        "����":		"���¾�������������Ҳ�������Ķ��ˡ�\n",
        "�����":	"���¾�������������Ҳ�������Ķ��ˡ�\n",
     ]));

	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
        
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","taiji",1);
	setup();
	carry_object("/obj/armor/cloth",([	"name": "�׹�",
    						"long": "һ���״�ӡ�\n",
    						 ]))->wear();    
}

void init(){
	
	::init();
	add_action("do_answer","answer");
}


string *material_names=({ "����","ͷ��","����" });

int accept_object(object me, object ob)
{
	string ob_name;
	int i,success,makeup_ok;
	object drug;
		
	if(ob->query("marks") == "special_coin")
 	{
  		message_vision("$N����$nһ�ۣ�ָ��һ��С��¯��\n",this_object(),me);
  		message_vision("$N��ԥ��һ�£������ϵ�һ��Ǯ����С��¯�С�\n",me);
  		message_vision("ͭǮ�ϵ��Ѻ���ð��һ�����̣�������ͭǮȾ�ɱ��̣�\n",me);
  		ob->set("marks","special_green_coin");
  		ob->set("long","����һö���̵�ͭǮ��ͭǮ����һ��ǳǳ���Ѻۡ�\n");
  		return 0;
 	}
	
	if (REWARD_D->riddle_check(me,"���ȵ��")!=9
		&& REWARD_D->riddle_check(me,"���ȵ��")!=10)
		return 0;	
			
	ob_name=ob->query("name");
	success=1;
	makeup_ok=0;
	for(i=0;i<3;i++)
	{
		if(ob_name==material_names[i])
		{
			if(me->query_temp("medman/"+ob_name))
			{
				command("say ��ԭ�����Ѿ��������ˣ���\n");
				return 0;
			}
			me->set_temp("medman/"+ob_name,1);
			command("say �ã������������¡�");
			makeup_ok=1;
		}
		success=success*me->query_temp("medman/"+material_names[i]);
	}
	if(!success) return makeup_ok; 
	
	tell_object(me,CYN"��ҩ���ϰ������˵��ԭ�϶����ˣ��Ժ�Ƭ�̡�
	
��ҩ���ϰ�ת����á�

Ƭ�̣���ҩ���ϰ��߹�����һ���������ĵ�������˵�����󹦸�ɣ���\n"NOR);

	message_vision(YEL"\n$n��$Nа���Ц�ţ�һ��������������ӡ�\n",me,this_object());
	me->delete_temp("medman");
	drug = new(__DIR__"obj/yj_drug");
	if(!drug->move(me))
		drug->move(environment(me));
	REWARD_D->riddle_set(me,"���ȵ��", 10);
	
	if (REWARD_D->riddle_check(me,"���о�")==1)
		tell_object(me,WHT"\n���⻷�����ף���Ȼ�ֻص���ԭ�أ���Ȼ��ˣ��������Ӧ�䣬�跨"YEL"����"WHT"Ԭ���źã�\n"NOR);
		
	return 1;
}


int	do_answer(string arg){
	
	object me=this_player();
	
	if (!me->query_temp("marks/ask_medman"))	return 0;
	
	if (arg != "dai yin" && arg != "����" )	
	{
		command("shake");
		return 1;
	}
	
	me->delete_temp("marks/ask_medman");
	
	message_vision(YEL"$N��Ȼ¶����Ȼ��������顣\n"NOR, this_object());
	tell_object(me,CYN"
��ҩ���ϰ�������Ц��˵���Զԣ����ɢ�����������ɢ��Ŷ���������ҵ����ɢ��
û�뵽ؤ��Ĵ�����ҲҪ���ɢ��\n"NOR);

	message_vision(YEL"\n$n��$Nа���Ц�ţ�һ��������������ӡ�\n",me,this_object());
	
tell_object(me,CYN"
��ҩ���ϰ�˵��ֻ�Ǵ�ҩ���Ʋ��ף���Ҫ"WHT"����"CYN"ĥ�ɵķۣ�"WHT"����"CYN"�Ŀǣ��Լ�����ȥ
Ů�ӵ�һ��"WHT"ͷ��"CYN"�������Щ�������˸��ң���������"YEL"���ɢ"CYN"�����ˡ�\n"NOR);

	REWARD_D->riddle_set(me,"���ȵ��",9);
	return 1;
}

			
	

int	init_quest(){
	object me= this_player();
	
	if(REWARD_D->riddle_check(me,"���ȵ��")!=8
		&& REWARD_D->riddle_check(me,"���ȵ��")!=9
		&& REWARD_D->riddle_check(me,"���ȵ��")!=10)		return 0;
		
	if(!me->query_temp("marks/ask_medman")){
		command("?");
		command("say ���ɢ����Ҫ�����������˭�������ģ�");
		me->set_temp("marks/ask_medman",1);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"���ȵ��")==9
		|| REWARD_D->riddle_check(me,"���ȵ��")==10)
	{
		command("say ����˵�İѶ������������ˡ�");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"���ȵ��")==8)
	{
		command("say ���ɢ����Ҫ�����������˭�������ģ�");
		me->set_temp("marks/ask_medman",1);
		return 1;
	}
	
	return 0;
}
	
	
		
	