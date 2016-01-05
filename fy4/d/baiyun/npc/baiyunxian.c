inherit NPC;
#include <ansi.h>

void create()
{
        set_name("��������", ({ "old man", "man"}) );
        set("title", HIB"�׺�һ��"NOR);
		set("gender", "����" );
		set("age", 244);
		set("per", 65);
		set("int",28);
		set("attitude","friendly");
		
		set("max_force", 1000);
		set("force", 1000);
		set("force_factor",50);

		set("long",HIW"
һ�����¶��ҵİ׺������ߣ���ɫ����������ף�ͯ�պ׷����������ͼ
���е���������һ�㡣������ϥ��Ŀ����������ŭ����\n"NOR
	);
		set("inquiry",([
			"*":	"action�������̱�Ŀ����������һ�\n",
		]));
	
		set("chat_chance", 1);
		set("chat_msg", ({
	        name()+"��ʯ����ں����������˿��������Ȼ������\n",
	        }) );
		
	    set("combat_exp", 40000000);
		
		set_skill("move", 200);
		set_skill("dodge", 200);
		set_skill("force", 160);
		set_skill("unarmed",200);
	    set_skill("changquan",200);
		set_skill("parry",200);
		
	    map_skill("unarmed", "changquan");
		
		set("NO_KILL","���ƺ�������һ����ǽ�������޷�ǰ����֡�\n");
		setup();
        carry_object(__DIR__"obj/douli")->wear();
        carry_object(__DIR__"obj/suoyi")->wear();
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
	object reward;
	if (!ob || environment(ob)!= environment()) return;
		
	if (REWARD_D->riddle_check(ob,"��ͼһ��") ==13)
	{	
		if (ob->query_temp("is_unconcious")){
			ob->revive();
			tell_object(ob,"�㻺�����˹�����\n��ǰ���Ŵ�����������Ƶ����˵��������еĿ����㡣\n");
		}
		message_vision(CYN"
�������̳�Цһ�������������ú��ӣ����²���������ñܴ˽٣�ʵ���԰���

������������ŭ������̾һ�����������³ǰ��³ǣ���ͼ��ҵ��ת�۳ɿգ�
��Ϊ���������������أ���Ҳ�࣬��Ҳ�࣬��Ҳ�գ���Ҳ�ա�\n "NOR, ob);


		message_vision(WHT"
�������̳���һ������Ȼ�ٿ�̤����ȥ��

�����ã�����ŭ��������������ʧ��������\n\n"NOR, ob);
		REWARD_D->riddle_set(ob,"��ͼһ��",14);
//		destruct(this_object());		so 2nd one entering won't get confused 
	}
}

