inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��������", ({ "travel lama","lama" }) );
        set("title","�����ķ���");
        set("gender", "����" );
        set("class", "lama");
        set("age", 32);
          
        set("long", "���������Ÿ�Ъ�ŵ����΢�յı������ϲ�����ɳ����\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������̾�˿������������ȡ�\n",
                "��������˵������˵�Ϸ�������������������֪��˭�ܰ������ˡ���\n",  
                "��������˵�������䲻��������ͷһ���գ���\n",                
                }) );	
                
        set("combat_exp", 500000);
        set("attitude", "friendly");
        
        set("inquiry", ([
                "����" : 	"��˵�ڻ���������һ���һ�������\n",
                "�һ�����" : "���һ������ڻ����м���ؾ����������滤���Ƿ����ܵ���\n",
                "����" : 	"������Ƿ����಻����Ѱ����������Ψ���Զ�������\n",
                "�Զ�����" : "���ôֻ���ҵĲ²���ˣ���Ȼ���ǲ���ȥ�Եġ�\n",
				"����":		"������ǳ���������Ļ����������ޱȣ���ȥ�޻أ�ʮ��ǰ
���ֿ��Ŵ�ʦ���䵱���˹��������µ���ʮ��ɮ�������У��ܻ��Ż�����ֻ��
һ���˹��ĺ��У������Ƕ������������ġ�\n",
				"�˹��ĺ���": "�ϻ����˹��ĺ�����Ȼ�����˹��ˡ�\n",
	]));
                
        set_skill("dodge",100);
        set_skill("move",100);
        set_skill("unarmed",100);
        set_skill("parry",100);
        set_skill("bloodystrike",50);
        
        set_skill("force",170);
        
        map_skill("unarmed","bloodystrike");
        
        set("skill_public",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init() {
	object ob;
	::init();
	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob) {
	if(!ob || environment(ob) != environment()) {
		return;
	}
	switch( random(6)){
		case 0:
			say("��������̾�˿������������ȡ�\n");
			break;
		case 1:
			say( "��������˵�������䲻��������ͷһ���գ���\n");
			break;
		case 2:
			say( "��������˵������˵�Ϸ�������������������֪��˭�ܰ������ˡ���\n");
			break;
	}
}


int recognize_apprentice(object ob)
{
	if(ob->query("free_learn/force"))
	return 1;
        else {
                if (!random(3)) {
                command ("say ����ֻ�ύӢ�ۺú���\n");
                } 
		return 0;
	}
}


int accept_object(object who, object ob)
{	
	if (ob->query("name")==HIR "������Ƥ" NOR)
	{
		message_vision("$N���۷ų���������������Ƥ����������ɱ������������\n\n",this_object(),this_player());		
		if( who->query("m_success/��ɱ����")) 
		{ 
			command("praise"+who->query("id"));
			message_vision(HIR"$Nһ���֣���Ӣ���������������¶�һ�����ɷ��ſ���Ӣ�۷�����\n"NOR,this_object(),this_player());
			who->set("free_learn/force",1);
			return 1;
		}
		else {
			message_vision(HIW"$N�ٺ���Ц�˼�����\n"NOR,this_object(),this_player());
			message_vision(HIW"$N˵����������Ҳ��������ĳ���֮����\n"NOR,this_object(),this_player());
			message_vision(HIW"��������Ƥ�����ˣ��㣬�������ˡ���\n"NOR,this_object(),this_player());
		return 1;
		}	
	}

	else {
		message_vision("$Nɨ��һ��$n���еĶ���˵�������ֶ�����ʲô�á���\n",this_object(),this_player());
		return 0;
		}
}

int prevent_learn(object me, string skill)
{
  	if (skill != "force")
  	{
      		command("shake");
      		command("say �ҿ�ֻ��Ӧ��������ڹ�����");
      		return 1;
  	}
  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/force")	&& skill == "force")
		return 0;
	
	return 1;
}