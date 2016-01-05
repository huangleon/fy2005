#include <ansi.h>
inherit NPC;
void smart_fight();

int stone();
int stone1();
int stone2();
int stone3();
int stone4();
int stone5();

void create()
{
        set_name("��СС", ({ "bad kid" }) );
        set("title",WHT"����ͯ��"NOR);
        set("gender", "����" );
        set("age", 1+ random(10));
        set("long", "���ͯ����İ�С��ȴ����һ�ų��˵���������������֮����\n");
        set("combat_exp", 3500000);
        set("class","shenshui");
        set("reward_npc", 1);
    	set("difficulty", 5);
		set("no_busy",8);      
        set("inquiry", ([
        	"stone" : (: stone :),
        	"�����ʯ" : (: stone :),
        	"�������" : (: stone1:),
        	"�̺�����" : (: stone2:),
        	"��ڤ�Ͼ�" : (: stone3:),
        	"�����൤" : (: stone4:),
        	"��¶��ʯ" : (: stone5:),
        	"��֮��" : (: stone1:),
        	"��֮��" : (: stone2:),
        	"��֮��" : (: stone3:),
        	"ɳ֮��" : (: stone4:),
        	"��֮��" : (: stone5:),
        ]));
        
        set("chat_chance", 1);
       	set("chat_msg", ({
			"��СС˵��������֪�������ʯ����ô���ҿ��Ը����㣬���ұ���ɱ���㡣��\n",
		}) );
                         
        set_skill("unarmed", 180);
        set_skill("force", 180);
        set_skill("longlife-force", 140);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("move", 180);
        set_skill("literate",120);
        set_skill("nine-moon-steps", 200);
        set_skill("nine-moon-claw", 180);
        set_skill("perception", 100);
		set_skill("kwan-yin-spells",130);
        set_skill("spells", 150);

		map_skill("move","nine-moon-steps");
        map_skill("spells","kwan-yin-spells");       
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "longlife-force");
                
		setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/hesan");
}

int stone(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
		message_vision(YEL"$N˵����������ɡ�������Ȼ����������\n"NOR,ob);
		return 1;
	}
	message_vision(YEL"$N˵����̫��ʱ������ײ������Ĳ���ɽ��Ů��������ʯ�Բ����죬��
������������֮�ġ���֮�ǡ���֮�ơ�ɳ֮�ס���֮�۸����ռ�����ɫ��ʯ��
�������ʯ�ֱ��ǣ�������䡢�̺����ġ���ڤ�Ͼ��������൤����¶��ʯ��
��˵�κ�������ܵõ����е�һ�֣����ܴ��еõ������������������ \n"NOR,ob);
	message_vision(YEL"$N˵�����������д�������װס�������\n",ob);
	command("heihei");
	me->delete_temp("badkid/bribe");
	return 1;
}

int stone1(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
		message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
		return 1;
	}
	tell_object(me,HIG"
��СС���˸���������������ڴ�֮�ۣ����������ǰ������֪���ˡ�������
���²�ɣ���ڹ����ˣ�������л�ˣ��̺���Ҳ��͵�ˡ�������

��СС˵����˭͵���ҿɲ�֪�����ҿ�û�ӵ����ǡ�\n\n"NOR);
	me->delete_temp("badkid/bribe");
	return 1;
}

int stone2(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
		message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
		return 1;
	}
	tell_object(me,HIB"
��СС˵�����̺������ں�֮�ǣ�������������� 
��СС��������˭֪ʮ�������ᣬ�������黯Ѫ�ۡ�����������߻����ˣ�
	      
	      һ�����ˡ�
	      
	      ���������������ˣ�
	      ���˲�������ɱ�ģ����������۵ģ�
	      ���۶������������Ҳ�Ȳ����Ƕ��˵�һЦ��
    	      ֻ��Ц��������������ġ�
    	      ���Ե��㶮���������Ӧ��������Ľ�����ЦһЦ!

	      ���������˺ͳ�˹֣�Ҳ������ôһ�ߵľ��롣��
	
��СС��������ļ��˵���ϵܣ���ʱ��Ϳ���Ķ�������ˡ�
	
	"NOR);      	
	
	me->delete_temp("badkid/bribe");
	return 1;
}

int stone3(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
		message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
		return 1;
	}
	tell_object(me,HIM"
��СС˵����ڤ�Ͼ��ڷ�֮�ƣ���֮�ƾ��Ƿ��Ƴǡ�������������Խ����
�Խ�ҾͲ��ɡ�ǰЩ�컨��ʮ���������˸������ˣ�û�뵽������ǲ��ɡ�

��СС����һ���£��·�������������������ˡ�\n\n"NOR);
	me->delete_temp("badkid/bribe");
	command("sigh");
	return 1;
}

int stone4(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
		message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
		return 1;
	}
	tell_object(me,RED"
��СС˵�������ߵ��˶��죬��Ҫ���ڵ���һ����������ɳ֮�ס�

	��һ�μ��������ѣ���һ��ɱ�����ѣ���Ϊ�������������ˡ�
		
	���еĶ��ֶ��������㣬��ʹ����Ҳ�����⡣
		
	�Ȿ�Ǹ��ܼ򵥵ĵ������Ǻܶ��˶������ף�����˵����м
	��ȥ���ף����������׵�ʱ�������Ѿ��������ˡ�
		
	����Ҳ�ܹ�˵�����������Ȼ������������Ҳ�������ˡ�

\n"NOR);
	me->delete_temp("badkid/bribe");
	return 1;
}

int stone5(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
		message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
		return 1;
	}
	tell_object(me,YEL"
��СС˵��������¶��ʯ��ʵ�Ǹ��ܼ򵥵��գ�
	    ��ɽ�Ĳ�ʯ��������ȥ�ĵط�������ٴ��Ͼ�صĹ��ߡ�
	    һ��ϡ�����䱦�����Ѿ�����ָ���˷��򣬻��б�������׵���ô��
	   
	   ������ʹ��֪����������ܣ�
	   ����СС��Ȼ������СС����Ѱ����Ȼ������Ѱ����
	   
	   ����һ��������ʮ������ˣ����Ȼ����һ���м��ĺ������
	   ��������Щ��������������Ϊ����������ڷܶ��ı䡣
	   	   
	   ���������������Ż����������������
	   \n"NOR);
	me->delete_temp("badkid/bribe");
	return 1;
}


int accept_object(object who, object ob)
{
	if (ob->value()>=1000) {
		command("giggle");
		command("say ��������ʰɡ�");
		who->set_temp("badkid/bribe",1);
		return 1;
	} 
	
	command("say ��ô�㡣������Ц�ɡ�");	
	return 0;
	
} 