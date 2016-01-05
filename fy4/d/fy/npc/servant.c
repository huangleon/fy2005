/*	����������Թ����� by Sinny-Silencer 

�Թ�Ѫ��
Easy boss, hard maze NPCs.
�����һ����,����boss����Ҫ����սʤ��

*/


#include <ansi.h>
inherit NPC;

int 	meihuadao();
int 	shajin();

void create()
{
	set_name("������", ({ "royal servant","servant" }) );
	set("gender", "����" );
    	set("title", "����" );
	set("age", 42);
	set("per",10);
	
	set("long","
���������ڣ�Ŀ������ӥ������������С��ɵ�������Ӷ�ˣ�
��������̽����Ӱ���롣\n");
	
	set("combat_exp", 9000000);
	set("class","lama");
	set("attitude", "friendly");
        set("difficulty",25);
        set("reward_npc",1);
	set_skill("iron-cloth", 200);
	set_skill("jin-gang",250);
	set_skill("unarmed", 300);
	set_skill("bloodystrike", 200);
	set_skill("dodge",300);
	set_skill("move",300);
	set_skill("sky-steps",160);
	
	map_skill("dodge","sky-steps");
	map_skill("move","sky-steps");
	map_skill("unarmed", "bloodystrike");
	map_skill("iron-cloth", "jin-gang");
        
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.fofawubian" :),
        }) );
	
	set("inquiry", ([
      		"��̽��":  "С��ɵ��������鷢������",  
      		"��Ѱ��": "С��ɵ��������鷢������",  	
        	"÷����" : (: meihuadao() :),
        	"meihuadao" : (: meihuadao() :),
        	"���˷�":	"�������������幬�����֣��ݴ��ѵ��������֮���衣\n",
        	"������":	"�������������幬�����֣��ݴ��ѵ��������֮���衣\n",
        	"�Ϲٽ��":	"�Ϲ��ǽ�Ǯ��������������������ڶ���\n",
        	"��Ǯ��":	"��Ǯ���ǽ����������ϵĵ�һ�������Ϲٽ���ڷ��Ƴ��ｨ����̳��\n",
   		"������":	"ֻ֪�����ڽ�Ǯ���У�������Ҳ�������\n",
   		"��Ų���":	"��Ų��̾��ڷ��������⡣\n",
   		"�һ���":	"���һ������һ�����һ�ֿ��µĶ���������С�ġ�\n",
   		"ɴ��":		(: shajin() :),
   		"shajin":	(: shajin() :),
        ]));
		
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:	message_vision("$Nһ��ͷ������һ���Ҿơ�\n",this_object());
			break;
		case 1:	message_vision("$N�����˵�����ɨ��$nһ�ۣ��ƺ������л������ĳ\n",this_object(),ob);
			break;
		case 2:	message_vision("$N�þ�����������´�����$n��������ɨ��һ��ǽ�ϵĺ첼������\n",this_object(),ob);
			break;
	}
}


int	meihuadao(){
	object me, ob;
	int n;
	ob = this_object();
	me = this_player();
	if (!ob->query("in_meihuadao"))
	{
		message_vision(WHT"\n����������÷�����������֣�üͷͻȻ���壬һ�Բ�����\n"NOR,me);
		return 1;
	} 	
		
	message_vision(YEL"
���������˿ڴ�Ѫ����ĭ������������÷�����ⲻ�в�Ů�Ķ������޻�
�Ҽ���ү��ǧ�����Ҳ��Ϊ������\n"NOR,me);		
	
	if (REWARD_D->check_m_success(me, "�һ���̽��"))
	{
		message_vision(YEL"
$N˵����л�����Ҽ���үϴȥԩ�����Ժ���ʲô���¶��������Ұɡ�\n"NOR,ob);
		return 1;
	}
		
	if (me->query("combat_exp")<= 100000) 			// Need exp > 100k
	{
		message_vision(CYN"
���������´�����һ���㣬̾��������Ĺ���̫�����������������������\n"NOR,me);
		return 1;
	}
	if ( n = REWARD_D->riddle_check(me,"�һ���̽��"))			// ALready in progress
	{
		if (n==1)
			message_vision(CYN"
������˵����÷������˵���һ���һ����û����\n"NOR,me);
		else if (n==2)
			message_vision(CYN"
������˵����÷�������ˣ������ҵ�ʲô��������\n"NOR,me);
		return 1;
	}	
	
	if (me->query("combat_exp")<= 2000000) {	
		message_vision(YEL"
���������´�����һ���㣬�޵��������Ҽ���ү����Ҳ�ǳ������������������£�
�����˵�־���ķ���Ҳ�ã��������ҵ�÷�������ټ�������ĳ�˵�л�������\n"NOR,me);
		REWARD_D->riddle_set(me, "�һ���̽��",1);		
		//me->set_temp("maze/��̽�һ���",1);	
	} else 
	{		
		message_vision(YEL"
�����׺���һ����������ƽʱ��������������֫�Ͼ��������Դ���Ҳ��ϡ�������� 
Щ��������Ĵ����ļٴȱ�������ô���¹ؽ�Ҫ����Ϊ�����������õ�÷�������� 
ȻҲ����\n"NOR,me);
		REWARD_D->riddle_set(me, "�һ���̽��",1);		
		//me->set_temp("maze/��̽�һ���",2);	
	}
	
	return 1;
}


int 	shajin()
{
	object me, ob, cloth;
	int n;
	
	ob = this_object();
	me = this_player();
			
	if (!REWARD_D->check_m_success(me,"�һ���̽��"))
	{
		message_vision(YEL"
$Nһ��ü��$n˵��ɴ��ʲôɴ��Ī��������÷������ͬ�����ɣ�\n"NOR, ob, me);
		return 1;
	}
		
	if (REWARD_D->check_m_success(me, "��̽��Ǯ"))
	{
		message_vision(YEL"
$N˵��ɴ��֮�£�����ˮ��ʯ����û�뵽��÷������Ȼ�����Ǯ����Ⱦ��\n"NOR,ob);
		return 1;	
	}
	
	if (!REWARD_D->riddle_check(me,"��̽��Ǯ"))
	{
		if (me->query("timer/maze_shajin")+900> time())
		{
			tell_object(me,"������˵�������������ģ����������ɡ�\n");
			return 1;	
		}
		
		message_vision(YEL"
�����׳����������ҽ����ɴ���պã���������÷�����ټ���Ψһ������ 
\n�������������ȥ��ʱ��Ų��̵���λ���ʸ��ŵ�����������Ů����֣�
���Ѿ��ܾ�û���ڷ��Ƴ�����������Ϣ�ˡ� 
\n�����װ���һ��̾�˿������ݸ���һ��ɴ��\n\n"NOR,me);	
		cloth = new("/d/maze/npc/obj/ty-meihua_ribbon");
		cloth->set("real2",1);
		if (cloth)
		{
			if (!cloth ->move(me))
				destruct(cloth);
		}
		me->set("timer/maze_shajin",time());
		return 1;	
	}
}

int	accept_object( object who, object what) {
	
	object cloth;
	mapping data;
	
	if (what->query("name") == HIG"׺��÷����ɴ��"NOR) 
	{
		 // We want people do this riddle by himself in one game session.
		if (!what->query("real") 
			|| (REWARD_D->riddle_check(who,"�һ���̽��") != 2))
		{
			message_vision(GRN"
������������ͷ����������֣������ʵص�ɴ���ܾ��ú����죬
����������������أ�\n\n"NOR,who);
			return 0;
		}
		// Reward time.
		message_vision(YEL"
��������ϸ�ؿ���׺��÷����ɴ������ʧ���ص����ѵ�÷��������ֻ��β��
��ô������׽�������������� \n\n"NOR,who);
		
		message_vision(HIR"
������ת��ͷ������$N�����еص����Թ�Ӣ�۳����꣬������ֻ����¶������
β��Ҳ��Ϊ���ס� \n"NOR, who);		
					
		if (!REWARD_D->check_m_success(who,"�һ���̽��"))
		{
			REWARD_D->riddle_done(who, "�һ���̽��",100, 1);
		
			data = ([
				"name":		"�ƽ������һ���̽��",
				"target":	who,
				"att_1":	"agi",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);
		}
		
		message_vision(YEL"\n\n
�������ֵ�����ɴ���￴�����ò�С��������ϸ���롣������\n\n"NOR, who);	
		return 1;
		
	}
	
	if (what->query("name")=="մ����Ѫ�����") {
		// Here, if ppl lose spear, we allow them to reget it		
		if ((REWARD_D->riddle_check(who,"��̽��Ǯ")!=2
			&& REWARD_D->riddle_check(who,"��̽��Ǯ")!=3) 
			|| !what->query("lu_spear")) {
				message_vision(BLU"
��������ϸ���˿�մ����Ѫ����ꪣ�����Ƭ�̣����ε�ҡ��ҡͷ������\n"NOR,who);
				return 0;
		}
		tell_object(who,WHT"
����������ؿ��ŷ��ڰ����ϵ�մ����Ѫ����ꪣ�üͷԽ��Խ��������ֿ־�֮ɫ��

�����״�����̧��ͷ�����������⡣����÷�������������򵥣���Ѫ��Ĳ�����ͨ��
ҩ�������Ѿ��������������ͽ������������˽�����Ƶġ������ҡ����ݴ���ҩ����
�˾���ʮ����ħ�����䣬����������������������Լ������Լ���ǧͯӤ��Ѫ���Ƴɣ�
���ɢ�˿�ȥ������ͬ�������������һ�㡣����

���������ϵĿ־�֮ɫ�������أ��૵���������ǰ������λ��ɽ�����������ѷ���
���������⣬�⡺�����ҡ���������ֽ����� 


�������ڷ��Ƹ��������������Ų���ͻȻͣ�¶���˵���²����ˣ������ٽ��������
���幬���˷��棬����̡������ҡ�һ�£�\n\n\n"NOR); 
		what->set("lu_spear",2);
		REWARD_D->riddle_set(who,"��̽��Ǯ",3);
//		who->set("maze/�����",1);
	}
		return 0;
}

