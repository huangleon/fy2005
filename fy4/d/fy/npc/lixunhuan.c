inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int afei();
int tower();

void create()
{
        set_name("��Ѱ��", ({ "li xunhuan", "li" }) );
        set("nickname", RED"С��ɵ�"NOR);
        set("gender", "����" );
        set("age", 44);
		set("class","npc");
		set("reward_npc", 1);
        set("difficulty", 40);
		set("attitude","friendly");
        set("rank_info/respect", "��̽��");
        set("long",
"��Ѱ�������̽�������н����º�С��ɵ���һ�ַɵ��������ڰ�������
�����������е������������ѣ������鷢��\n");
        
        create_family("����һ��", 2, "�˽�");
	set("student_title","�˽�");
        set("combat_exp", 40000000);
        
        set("score", 200000);
        
        set("inquiry", ([
	         "afei" : (: afei :),
	         "����" : (: afei :),
	         "�ƽ���": (: tower :),
	        ]) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��Ѱ����ͣ���ڿȣ��������һ˿��Ѫ��\n",
                "��Ѱ������ɫԽ���԰��ˡ�\n",
		"��Ѱ��̾���������������������ľ��\n",
        }) );
        
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
	set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);
       	map_skill("throwing", "feidao");
        
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
}


object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}


void heart_beat()
{
	object feidao;
	object target;
	if(!query_temp("weapon") && is_fighting())
	{
		feidao = new(__DIR__"obj/xlfd_knife");
		feidao->move(this_object());
		command("wield flying blade");
        	target = offensive_target(this_object());
        	if(target)
        	(CLASS_D("traveller") + "/feidao/xiaoli-feidao")->kill_him(this_object(),target);
		feidao->throw_weapon(this_object(),target,0);
		return;
	}
	else
	return ::heart_beat();
}

void	init(){
	object ob;
	::init();
	
	if( interactive(ob = this_player()) && !is_fighting() ) {
                if (ob->query_temp("maze/see_li")==1) {
                        call_out("event1", 1, ob);
                        add_action("do_answer","decide");
                }
                if (ob->query_temp("maze/see_li")==2) {
                        call_out("event2", 1, ob);
                        add_action("do_answer","decide");
                }
        }

}

void event1(object me) {
	
	mapping data;
	
	if (!me || environment(me)!= environment(this_object())) {
//		command("say stop");
		return;
	}
	if (me->query_temp("is_unconcious")) {
//		command("say ok wait");
		call_out("event1",2,me);
		return;
	}
	tell_object(me,HIC"
��Ѱ������̾�˿�����΢Ц�Ŷ�����������Ʋ��ᣬ���������Ϣһ�� 

��Ѱ����Ȼ���صؿ�����������������Ц������ϧ���������鲢�Ƿ��ˣ���
��һ�������������ѣ������˻û��޷�����������Ԫ�����ڡ����� "NOR+HIY"

��Ѱ��ҡ��ҡͷ��Ц�����ҵ�С�Ѱ���������������������һ������޺��ã�
����߽�Ǯ��Σ��һ�����������������ܽ�����Ϊ�������ж�ã�

\n\n"NOR);
		if (REWARD_D->riddle_check( me, "�ٴ���Ǯ")==4)	
		if (!REWARD_D->check_m_success(me,"�ٴ���Ǯ"))
		{
			REWARD_D->riddle_done(me, "�ٴ���Ǯ",100, 1);
		
			data = ([
				"name":		"�ƽ������ٴ���Ǯ",
				"target":	me,
				"att_1":	"int",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);
		}
	
	REWARD_D->riddle_set(me,"��������",1);
	me->delete_temp("maze/see_li");
	return;
}

void event2(object me) {
	if (!me || environment(me)!= environment(this_object())) {
//		command("say stop");
		return;
	}
	if (me->query_temp("is_unconcious")) {
//		command("say ok wait");
		call_out("event2",2,me);
		return;
	}
	tell_object(me,YEL"
��Ѱ������Ǹ��Ŀ����㣬��Ц��������������ɣ��Һ��Һʹ��׼�ʱ�ϵ���
�Ҵ��˰��������ļ�֮������ı�������ֱ���ǰ�ӡ����򡣡� 

��Ѱ����Ȼ��Ȼ�����������������õ����޼�ľ֮�����������Ʋ����ң�
�ҵ��ٲ���ֹ�����¡��� "NOR+HIC"

��Ѱ��Ц��Ц������������ǰ��ø����ɣ���������������ƽ���֮ս����
����ǰ�� 

��Ѱ������������λ"+RANK_D->query_respect(me)+"�����ոߵ���ʵΪ��ս�ȷ�Ĳ�����ѡ�� 


�������ô��(decide yes or no) \n\n\n"NOR);
//	REWARD_D->riddle_set(me,"��ս�ƽ���",1);
//	me->set("maze/С���ٳ���",1);
	me->delete_temp("maze/see_li");
	me->set_temp("maze/xiaoli_ask",1);
	return;
}

int afei(){
	object me;
	
	me = this_player();
	
	message_vision(YEL"
��Ѱ��ҡ��ҡͷ��Ц�����ҵ�С�Ѱ���������������������һ������޺��ã�
����߽�Ǯ��Σ��һ�����������������ܽ�����Ϊ�������ж�ã�\n\n"NOR,me);
	
	if (REWARD_D->riddle_check( me, "��������")!=1)	
		return 1;
	
	tell_object(me,HIC"
����ͷһ�����������������С��̽��һ��֮��������ר�ĶԸ���Ǯ�����ı��
һǻ��Ѫ�������ڻ��������ұ�Ӧ��֮�£� "NOR+HIY"

�������ô����decide yes or no��

"NOR);
	me->set_temp("maze/xiaoli_ask",1);
	add_action("do_answer","decide");
	return 1;
}

int tower(){
	object me;
	
	me = this_player();

	if (REWARD_D->check_m_success(me,"��ս�ƽ���"))
	{	
		message_vision("too tired to write now, SINNY, what should be here?\n", me);
		return 1;
	}
		
	message_vision(CYN"
��Ѱ�����������õ����޼�ľ֮�����������Ʋ����ң��ҵ��ٲ���ֹ�����¡��� 
����ǰ��ø����ɣ���������������ƽ������ǳ���Ĳ���֮����\n\n"NOR,me);
	
	if (!REWARD_D->check_m_success(me,"��������"))
		return 1;
	
	tell_object(me, HIY"

��Ѱ������������λ"+RANK_D->query_respect(me)+"�����ոߵ���ʵΪ��ս�ȷ�Ĳ�����ѡ�� 


�������ô��(decide yes or no) \n\n\n"NOR);
	add_action("do_answer","decide");
	me->set_temp("maze/xiaoli_ask",1);
	return 1;
}
 
int do_answer(string arg){
	
	object me;
	
	me = this_player();
	if (!me->query_temp("maze/xiaoli_ask")) return 0;
		
	if (!arg)
		return notify_fail("�������ô��\n");
	
	if (arg!= "yes" && arg!= "no")
		return notify_fail("��ʽdecide yes��decide no��\n");
	
	if (REWARD_D->check_m_success(me,"��������")) {	
		if (arg == "no") {
			message_vision("$N����ͷ���������������׼��һ�¡� \n"NOR,me);
			me ->delete_temp("maze/xiaoli_ask");
			return 1;
		}
		
		message_vision(HIR"$N��Цһ������Ȼ����Ȼ����ս�ȷ棬������˭��  \n"NOR,me);
		me->delete_temp("maze/xiaoli_ask");
		REWARD_D->riddle_set(me,"��ս�ƽ���",1);
	} else {
		if (arg == "no") {
			tell_object(me, WHT"����ϸ�����룬����¶�̫Σ���ˣ����Ҳ�������Ϊ�ס�\n"NOR);
			me ->delete_temp("maze/xiaoli_ask");
			return 1;
		}
		message_vision(HIC"$N�¶����ģ��������С��̽���������䲻�ţ�Ը�����ִ�Ȱ��ɡ� \n"NOR,me);
		command("ah");
		message_vision(CYN"$N΢΢Ц�����ã��Ǿ��������ˡ� \n"NOR,this_object());
		me->delete_temp("maze/xiaoli_ask");
		REWARD_D->riddle_set(me,"��������",2);
	}
	return 1;
}

void attempt_apprentice (object ob) {
	
	command("smile");
	command("waggle");
	return 0;	
}

/*
void attempt_apprentice(object ob)
{
	if(time()-(int) ob->query("last_time_app_master_li") < 3600)
	{
	         message_vision("$NЦ��������ô��ô���ֻ����ˣ�����\n",this_object());
        return;
        }
	if((int) ob->query("force_factor") < 1200)
	{
	 	message_vision("$NЦ��������书���˽⻹����������\n", this_object());
	return;

	}
	if( random(500) || ((int)ob->query("kar")) <  250 || query("already"))
	{
		message_vision("$N����������˵������Ҫ����Ц���ҿɲ��������ӵܡ�\n",this_object());
		ob->set("last_time_app_master_li",time());
                return;
        }
        	command("sigh");
        	command("say �ܺã�" + RANK_D->query_respect(ob) + "�����в���Ϊ��������\n");
        	command("recruit " + ob->query("id") );
		ob->delete("betrayer");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "traveller");
	set("already",1);
}

void reset()
{
	set("already",0);
} 
*/