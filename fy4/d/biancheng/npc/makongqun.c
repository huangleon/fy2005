#include <ansi.h>
inherit SMART_NPC;

int do_answer(string arg);

void create()
{
    	set_name("���Ⱥ",({"ma kongqun","ma"}));
	set("title",HIR"������ ����"NOR);
   	set("long","
���˶������������������������û�б��˵�ʱ�����������ù��ؾأ�
���Ӻ���Ȼ�п����������ɻ���ͦ�ñ�ֱ��ֱ����һ���˹¹µ�����������
�����ÿ���˶���ôңԶ�����·��ѽ��Լ���ȫ�����쳾�⣬û�л��֣�
û�����ܡ�\n");

     	set("gender","����");
    	set("age",62);
    	 	
    	set("combat_exp",10000000);  
    	set("attitude", "friendly");

    	set("reward_npc",1);
    	set("difficulty",30);
    	    	
  		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    
        
       	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
        set("smartnpc_busy",1);
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );    	    	
    	
    	
		auto_npc_setup("wang",350,200,0,"/obj/weapon/","fighter_w","shenji-blade",2);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": HIC"��������"NOR,
    						"long": "һ���������ۡ�\n",
    						 ]))->wear();     
    	carry_object("/obj/weapon/blade/blade_ma")->wield();
}

/*
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_answer","answer");
}*/


void greeting(object me)
{
	object ob;
	ob= this_object();
	if( !me || environment(me) != environment() ) return;
	
//	this happens in �鷿 only
	
	
	if (environment(ob)->query("wanma_discussion") && !me->query("marks/wanma/ɱ����_ma")) {
		message_vision(YEL"$N�������ϵľƱ�������һ���ַ��£�Ȼ�󻺻���˵��\n"NOR,ob);	
		call_out("event1",1,me,0);
		return;
	}
	
	if (environment(ob)->query("wanma_discussion") && me->query("marks/wanma/ɱ����_ma")
		&& me->query_temp("marks/wanma/ɱ������_ma") && me->query_temp("marks/wanma/ɱ������_ma")
		&& !me->query("marks/wanma/׼��ɱͬ��_ma")) {
		message_vision(CYN"
������ã����Ⱥ������˵�������ѣ��ֵܣ�һת�۾ͳ����뺦����ˣ�
�Ҳ������ǣ�����������ǣ���Ҳ����ô�������������������¶����Ҳ
������Թ���������������úܺã��Ӵˣ��������ã�һ���������ˡ���\n\n"NOR,ob);	
		message_vision(CYN"
���Ⱥ�����۾���һ���ֵ�����������Ĺ¶������ǻ���֪����˭������
�ĳ�ޣ������ǷǱ����ɵģ���Ҳһ������������ʲô�������ܣ�������
����֪����������������һ����û��ץס��ʵ��֤�ݣ���֤���������µ�
�֡����ԣ�����֪��������ܵ��ˣ�����Ӧ���ٻ��ţ��㿴������ֽƬ��
��֪������ô�졣��������\n\n"NOR,ob);	
	message_vision(CYN"
���Ⱥ�����������Ҿ�����������������ȴ����������ֽ����侲��һ
���������ؽ��ŵ�����ֻ�еȣ�����Զ�����ģ�һ����ֻҪ�����ͣ���
�ȣ������ܻ�ȵõ�����ģ���\n\n"NOR,ob);	
		me->set("marks/wanma/׼��ɱͬ��_ma",1);
		return;
	}
	
	if (environment(ob)->query("wanma_discussion") && me->query("wanma/׼��ɱͬ��_ma")
		&& me->query_temp("marks/wanma/�״�_ma") && me->query_temp("marks/wanma/Ѧ��_ma")
		&& me->query_temp("marks/wanma/�һ�����_ma") && me->query_temp("marks/wanma/������_ma")
		&& me->query_temp("marks/wanma/����_ma") 
		&& !me->query("marks/wanma/׼��ɱ����_ma")) {
		call_out("event2",1,me,0);
		return;
	}

	if (environment(ob)->query("wanma_discussion") && me->query("marks/wanma/׼��ɱ����_ma")
		&& me->query_temp("marks/wanma/���׷�_ma") && me->query_temp("marks/wanma/����ѩ_ma")
		&& me->query_temp("marks/wanma/Ҷ��_ma"))	{
		message_vision(YEL"���ȺһԾ���𣬴�Ц����������һ�ۣ��������������֡���\n"NOR,ob);
		message_vision(CYN"����ʲô�һ�û��ã�sorry��\n"NOR,ob);
		me->set("marks/wanma/�վ����Ⱥ",1);
		return;
	}
		
	if (!me->query("marks/wanma/ӭ��")) return;
	
	if (me->query("marks/wanma/��¥")) return;
	
	if (me->query("marks/wanma/ɱ����") && me->query_temp("marks/wanma/ɱ����a")
		&& me->query_temp("marks/wanma/ɱ����b") && me->query_temp("marks/wanma/ɱ����c")
		&& !me->query("marks/wanma/��¥")) {
		message_vision(CYN"
���Ⱥ˵�����ã������ǰ;�������þ���Ҫ���������˲ţ������Ը�⣬
�Ժ�����������Ⱥ�����ѡ���������һ������Ҫ���㣬���������Ѷ�
�϶��У�ר����裬����������Ը�������£���᲻�ᱳ������\n",ob);
		tell_object(me,HIY"���������򡡣���󣯣� \n"NOR);
		me->set_temp("marks/wanma/answer_ma",2);
		return;
	} 	
	
	if (me->query("marks/wanma/׼��ɱ�̿�_ma") && me->query_temp("marks/wanma/�����嶾a")
		&& me->query_temp("marks/wanma/�����嶾b") && me->query_temp("marks/wanma/�����嶾c")
		&& me->query_temp("marks/wanma/�����嶾d") && me->query_temp("marks/wanma/�����嶾e")
		&& !me->query("marks/wanma/ɱ����")) {
		message_vision(CYN"
���Ⱥ���������͵�˵������Ȼû�����㣬���°�úܺã������嶾���
��ӯ����ȷ���������������������ҵ�ʲô��Ҫ�Ķ������ɸ���һ������\n"NOR,ob);
		me->set_temp("marks/wanma/give_paper",1);
		return;
	}
	
	if (me->query("marks/wanma/׼��ɱ�̿�_ma")) {
		command("say ��Ҫ��׷�������������ô��");
		return;
	}
	
	message_vision(YEL"$N��Ŀ��������Զ������ÿ������ǰ��ͣ���˺ܾã�����������$n��\n"NOR,ob,me);
	message_vision(CYN"$N������˵���������������������Ǵӵ����ϵ����ģ��������ֶ�������
�֣���ǵ����������о�������Ҳ����û�з���֤���ģ�����һ������������
���ˣ���ʱ�ڱ������п������������Ǹ�����������ϵ���Ϊ���Ѿ���˵�ˣ�
���Ƿ�Ը���������ð�һ���£�һ����Ҫ�����������£�\n"NOR,ob);
	tell_object(me,HIY"���������򡡣���󣯣� \n"NOR);
	me->set_temp("marks/wanma/answer_ma",1);
	return;
}



int do_answer(string arg)
{
	object me,ob;
	
	me=this_player();
	ob=this_object();	
	
	if(me->query_temp("marks/wanma/answer_ma")==1) {
		if(arg=="yes") {
			message_vision("\n$N�ᶨ�ص��˵�ͷ˵�������������£��������µ��¡���\n"NOR,me);
			message_vision(CYN"$N˵�����ã���һ·ǰ������������������֮������\n",ob);
			message_vision(CYN"������ش�$N����ȥ˵���������˼ң����м�Ȯ���߳���֮�У���ô
��û��������Թ���ֻ��˼����ʮ������Ȯ�����پ�ʮ��ֻ����������һҹ
֮�䣬���øɸɾ���----����һ�������˲��ӣ������촦��������Ȯ��������
��ɱ���������󻼡������ö����ֶΡ�\n"NOR,ob);
			message_vision(CYN"    �����½�����������ˣ���������ȥ�쿴���ҳ�����֮�����õ�֤�ݺ���
�����ҡ��㲻�������õ��ˣ��������������ֵ����ģ�������Ҳ��С�Ľ�������\n\n"NOR,ob);
			message_vision(YEL"˵�꣬���Ⱥ���ٿ��㣬��һ�������������˳�˼��\n\n"NOR,ob);
			me->delete_temp("marks/wanma/answer_ma");
			me->set("marks/wanma/׼��ɱ�̿�_ma",1);
			return 1;	
		}
		if(arg=="no"){
			message_vision("\n$N�Ͻ�ҡ��ҡͷ˵�����������յ�΢���㻹����������ɡ���\n"NOR,me);
			message_vision(CYN"$N΢΢һЦ˵������������ͽ���������Ϳͣ���\n"NOR,ob);
			me->delete_temp("marks/wanma/answer_ma");
			return 1;
		}
		tell_object(me,"��ֻ�ܻش�������\n");
		return 1;
	}
	if(me->query_temp("marks/wanma/answer_ma")==2) {
		if (arg=="yes" || arg =="no") {
			if(arg=="yes") {
				message_vision("\n$N������˵��������������Ȼ�Ͳ����ҵ������ˡ���\n"NOR,me);
			}else if (arg=="no") {
				message_vision("\n$Nҡ��ҡͷ˵����������������Ǻû��ǻ���ֻҪ����������ѣ���
�Ͳ����ڱ������һ������\n"NOR,me);
			}
			me->delete_temp("marks/wanma/answer_ma");
			me->set("marks/wanma/��¥",1);
			message_vision(YEL"\n$N���ÿɷ��һЦ�����˴���Ŀ�ڶ࣬�������ʱ�����鷿�������а��š���\n"NOR,ob);
			message_vision(YEL"$Nת����ȥ������˵����\n"NOR,ob);
			return 1;
		}	
		tell_object(me,"��ֻ�ܻش�������\n");
		return 1;
	}
	
	return 0;
}


int accept_object(object who, object ob)
{
	if (ob->query("name")=="ֽƬ"){
		if (!who->query_temp("marks/wanma/give_paper")) {
			message_vision(CYN"$N˵�������ֲ���׽Ӱ�Ķ���Ҳ�ɵ��棿��\n"NOR,this_object());
			return 0;
		} else {
			message_vision(CYN"
���Ⱥ�ù�ֽ���˿�����ζ���ɨ����һ�ۡ���ɫ������������αĪ�棬
�������Ρ���ҹʮ��λ��ʦ�����˰��㣬�����촦�������ý䱸ɭ�ϣ���
�˼��ѽ��롣���ֱ�Ȼ�����������ļ�λ����֮һ���ܿ��ܾ������Ǻ���
�ϵĽ����嶾���⹴�ᣬ�����������������Ҳһ����ȥ����\n\n"NOR,this_object());
			tell_object(who,WHT"��Ȼ������ů����ģ�һ�ɺ������ס�����ĵ�����\n\n"NOR);
			message_vision("$N������һ�£�����ԥԥ��˵�������ɱ���ˣ���ô�죿��\n\n"NOR,who);
			message_vision(CYN"$N΢΢һЦ����ɱ���ˣ�������ɱ����\n"NOR,this_object());
			message_vision(YEL"\n$Nת����ȥ������˵����\n"NOR,this_object());
			who->set("marks/wanma/ɱ����",1);
		}
		return 1;
	}	
	return 0;
} 

string *event1_msg=	({
	CYN"
���˲�˵������ʮ����ǰ�Ҵ�ɱ��������Ǽ��£���ȷ���ò����������䣬
���������ٻص�ʮ����ǰ���һ��ǻὫͬ����������һ�Σ���Ϊ������ʵ
�ѽ��ұƵ���·���ߣ����ǵ�Ҫ�Ҽ����������ã���Ҫ�ҽ��Ҳ�ȫ����
�׸����ã�����֤һ���������������¡����ҵ�ʱ��ֻ�����������µ�
һ�����ܶ��ѣ���Ȼ������������ʲô�á������𲢲��Ǹ�����С�ˣ���
��ȷ�Ǹ�Ӣ�ۣ����ղž��ޣ�����Ӣ�����书֮�ߣ��Ѿ�����������Ϲ�
���֮�¡����ǽӽ�����֮�󣬾�Ҫ��ȫ����ָ��֧�䣬�͵���ȫ��������
�������Ⱥ�����Ǽ�������֮��������ָ����ɣ��ͷ�ɱ�������ɣ���\n"NOR,
		
CYN"ʮ�����ˣ�û�뵽�������ĺ��ˣ�Ҳ���ǰ������ħ�̹�����˽���Ӿ�Ȼ
�����ţ���������в�������������ͷһ��������������"NOR,

	CYN"
���Ⱥ����һת���������������ڶ�������в���������������������
���ڲ�������ɱ�Ľ����嶾���Լ��Ļ��ϲ��Ľ��������ˣ������ǰ���
��ĺ������ͣ������������ε��ֵܣ�������ͻ���¥�����ġ��������
�˻��Ὣ�Ҹϳ�������ȡ����֮����\n"NOR,

CYN"���Ⱥ��̾һ�������ҵĸ��������������Ҫ���ߣ���Ҳ���������ԣ�
����˭�����ң�����������\n"NOR,

CYN"���������ܹ����ҳ�ȥ���ǣ��Ժ�����������õĸ���������\n"NOR,

CYN"�������������õ����������������Գ���֮�⣬�Ҳ������κ���֪����
˭�µ��֣��мǡ���\n"NOR,

YEL"���Ⱥ�ӻ��֣��������ˣ����߰ɡ�������º��������ҡ���\n"NOR,	
	
});


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		message_vision(YEL"���Ⱥת�����ٿ��㡣\n\n"NOR,this_object(),me);
		me->set("marks/wanma/ɱ����_ma",1);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


string *event2_msg=	({
	YEL"
���Ⱥ���Ŵ��⣬û��˵һ�仰����ã���á�������\n"NOR,

YEL"���⣬ɽ��ǰһƬ���ԭ�������ű��졣�紵���ݣ����纣���еĲ��ˡ�\n"NOR,

CYN"���˺ܾã����Ⱥ�Ż��������������㿴������ʲô����\n"NOR,

CYN"��ش��������ԭ����ء���\n"NOR,

CYN"���Ⱥ�������������ü����صıߣ���\n"NOR,

CYN"�����������������\n"NOR,

CYN"���Ⱥ��������һ�鿴�����߼ʵĴ�أ������ҵģ�������ɫ��Ȼ������
�������ŵ�������������е����������еĲƲ���Ҳȫ�������ң��ҵĸ�
�ѳ����������\n"NOR,

CYN"�ֹ��˺ܾã����Ⱥ�ļ����Ž���ƽϢ����̾����������˭Ҫӵ����һƬ
��أ������Ǽ������¡���֪����֪������һ��������ô�������ģ���\n"NOR,

CYN"���ȺͻȻ˺�����½�¶������������ţ����������ٿ�������ʲô����\n"NOR,

WHT"�㿴���������ţ�����������ͣ�١���δ����һ���˵������ϣ�����˶�
���ˣ���˶ལ�ۣ�\n"NOR,

CYN"���Ⱥ����ͻ�ּ������۾��﷢�Ź⣬����������������Ҹ����Ĵ��ۣ�
��һ�ж������ҵ�Ѫ���ҵĺ��������������ֵܵ����������ģ���������
ʲô�ˣ������뽫��һ�д����������ߡ�������ʲô�˶����У���\n"NOR,

CYN"�����ԣ�ʮ����ǰ�������������������ڣ����Ĺ¶����������������
�ұ��������������Ѫ��һ��Ҫ�������Ѿ�����Щ�˵��������ȷʵ����
���¶�����Ѱ���ĵ��ӣ������������ϣ��Ǹ�ħ�̹������׷��������
������Χ������ϸ����һ�����ҵ������ڸ���ѩ���ǻ��׷��ó�޸�����
����Ҳ�����ٻ���ȥ����\n"NOR,

CYN"���Ⱥ�����ض�����˵����ֻ����Щ�˶��������ˣ������ò�����Զ������
���Ҳ�����Զ���������������������һ��ʹ�����Ӵˣ��ҵľ�����ģ�
�ҵ�һ������Ҳ���������㡣��\n"NOR,
	
});


void event2(object me, int count)
{
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	tell_object(me,event2_msg[count]+"\n");
	if(++count==sizeof(event2_msg))
	{
		message_vision(YEL"�����Ѿ�û���κ�����ѡ���ˣ���ϣ�����������������˵�꣬���Ⱥ
�㲻�ٿ��㡣��\n\n"NOR,this_object(),me);
		me->set("marks/wanma/׼��ɱ����_ma",1);
		return;
	}
	else call_out("event2",1,me,count);
	return ;
}