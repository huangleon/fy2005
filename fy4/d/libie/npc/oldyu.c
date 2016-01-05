#include <ansi.h>
inherit NPC;

int lian();
int yang();

void create()
{
        set_name("����ͷ", ({ "old yu", "yu" }) );
        set("gender", "����" );
        set("age", 65);
        set("per", 10);
        set("long", "һ���׷��ԲԵ����ߣ������������㣬�ƺ��л�Ҫ˵��\n");
        set("attitude", "peaceful");
        set("combat_exp", 100000);
        set("chat_chance", 1);
        set("no_arrest", 1);
        set("chat_msg", ({
		"����ͷ��������������ʯ�������ţ�����һ����Ʈ�䣬�ճյ���
С�����ɵû��Ż��������������޶����������ڵ��㰡������\n"
        }) );
        set("inquiry", ([
                "����" : (: lian :),
                "lian gu" : (: lian :),
                "С�" : (: yang :),
                "���" : (: yang :),
                "yang" : (: yang :),
                "yang zheng" : (: yang :),
                "���³���":	"С�϶��и�ֶ��Ů���������³������ġ�\n",
                "di qinglin" : "����������С��ү����ͽ�������֡�\n",
                "������" : 	"����������С��ү����ͽ�������֡�\n",
        ]));
        set("��",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}



int accept_fight(object me)
{
        command("say ��ͷ�����������Ķ��֣�");
        return 0;
}
 
int lian()
{
    	object me=this_player();
    	if (REWARD_D->riddle_check(me,"���")==4)
    	{
    		message_vision("����ͷ�����ݺ��˵�������ھ�Ȫ֮��Ҳ�����Ŀ�ˣ�\n", me);
    		return 1;
    	}
    	
    	if (REWARD_D->riddle_check(me,"���")==3 || me->query_temp("libie/di_1"))
    	{
    		message_vision("����ͷ���ĵ�˵�������������˺������ҵ����ã���һ��Ҫ�������𰡣�\n", me);
    		return 1;
    	} 
    	
    	if (REWARD_D->riddle_check(me,"���")==2)
    	{
    	if (me->query_temp("libie/lian_corpse"))
    	{
    		message_vision("����ͷʹ�޵����������ĺòң���һ��Ҫ�ҳ����ְ���\n", me);
    		return 1;
    	}else
    	{
    		message_vision("����ͷ������˵������ʧ�ټ����ˣ�������취�ɡ�\n",me);
    		return 1;	
    		
    	}
	}
	
    	message_vision("����ͷŤ��ͷȥ�������ڻ����ֵ��������ţ������˲�ˮ�����д���λ" + RANK_D->query_respect(me) + "��\n", me);
    	message_vision(CYN"����ͷҡҡͷ˵���⺢�ӣ���������Ͳ�����Ӱ�ˡ�\n"NOR, this_object());
    	return 1;
}

int yang()
{
    	string msg;	
	object me = this_player();;
	
	if (!environment()->query("yu_home"))
	{
		message_vision("����ͷãȻ�ؿ����㣬����û����$N���ʻ���\n"NOR, me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me, "���"))
	{
		message_vision("����ͷ˵��лл���������ţ�С͸û����˰ɡ�\n",me);
		return 1;
	}
	
	if (me->query("timer/libie_letter") + 86400 > time())
	{
		message_vision("����ͷ˵���Ų��ǲŸ�����ô����ô��ô��������ˣ�\n"NOR, me);
		return 1;	
	}	
	
	if (me->query("timer/libie_refuse") + 1800 > time())
	{
		message_vision("����ͷ˵���㷽�Ż����Ǵ���ʿ����ô��ô��ͱ������⣿�ٺú�����ɡ�\n"NOR, me);
		return 1;	
	}
		
    	if(me->query_temp("libie/���_����"))
    	{
        	message_vision("����ͷãȻ��˵�����Ų��Ǹ��������ѵ����ϴ����ˣ�\n"NOR,me);
    		return 1;
    	}
    	
    set("chat_chance", 0);
	msg = "
����ͷ���Ǻǡ�ɵЦ�������������Ҽ�С�����ǰ�����ȥ�참�ˡ���˵
�Ǹ��󰸣�һ�ٰ�ʮ���������������ﱻ�˽��ˣ���ͷ��ͷ���˺ö࣬����
������Ҳ�����˸�ʲôС��ү��\n"NOR;
	if (query("��"))
	{
	       	msg += "\n����ͷ������ͷ˵�����ˣ������ﻹ��С��ŵ�һ���š�˵�Ǹ�һλ����
ʿ����" + RANK_D->query_respect(me) + "��ô��\n"NOR;
	       	add_action("do_answer", "answer");
	       	me->set_temp("libie/answer_yu",1);
	}
	message_vision(msg,me);	
	return 1;
}

int do_answer(string arg)
{
    	object me = this_player();
    	string name = RANK_D->query_self(me);
    	
    	if (!me->query_temp("libie/answer_yu"))	return 0;
    	    	
    	if( arg == "no" )
    	{
        	message_vision(MAG"$Nɦ��ɦͷС������" + name + "���������У��θ�����ʿ�Ծӡ�\n"NOR, me);
        	message_vision(MAG"����ͷĿ��ͣ�ͣ�����̾�˿�����תͷ���\n"NOR, me);
			me->delete_temp("libie/answer_yu");
			me->set("timer/libie_refuse",time());
        	return 1;
    	}
    	else if( arg == "yes" )
    	{
        	message_vision(CYN"
$N�����������һ���ִ����" + name + "���䲻�ţ��������Σ�������ұ�����֮�£�\n"NOR, me);
		me->delete_temp("libie/answer_yu");
		if (F_LEVEL->get_level(me->query("combat_exp"))< 30) {
			message_vision(CYN"����ͷ�ֿ��˿�$N��̾�˿���˵���������㣬�Ҳ����ġ���\n"NOR,me);
			tell_object(me,"����������辭��ȼ���ʮ���ϣ�\n");
			return 1;
		}
		message_vision("
����ͷ��ʱϲЦ�տ�����������ʿ���������ҽ������ž������棬�Ҽ�С�
����ʱ˵��������¶��������Ĳ��£����¿ɺ��ˡ���\n
"YEL"����ͷת��������ݡ�\n"NOR,me);
        	me->set_temp("libie/���_ȡ��",1);
        	this_object()->move("/d/libie/neishi");
        	return 1;
    	}
    	else
    		return 0;
}

int give_letter(object me)
{	object letter;
	
	if(!present(me,environment())) return 0;
    	message_vision(YEL"����ͷ��ΡΡ�ĵݸ�$Nһ���ţ�ת����������ȥ��\n"NOR,me);
	this_object()->move("/d/libie/yard");
	letter=new(__DIR__"obj/letter");
	if (!letter->move(me))
		letter->move(environment(me));
	letter->set("������",me);
	this_object()->delete("��");
	set("chat_chance", 1);
	me->delete_temp("libie/���_ȡ��");
	me->set_temp("libie/���_����",1);
	return 1;
}	


void reset()
{
	set("��",1);
	
}