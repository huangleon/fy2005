inherit NPC;
#include <ansi.h>
int kill_him();

void create()
{
    set_name("ʯ����", ({ "shi guanyin","guanyin" }) );
    set("nickname", HIG"������פ"NOR );
    set("gender", "Ů��" );
    set("age", 25);
    set("int", 30);
    set("per", 30);
    set("agi",100);

    set("force_factor", 400);

    set("long","
ʯ�����������������ǽ��˲�������ģ���Ϊ����������ȫ��ռ��������
�����������кܶ��˶����á�������������Ů�ӵ����������ǹ���������
��˫�۾������������ᡣ�кܶ��˶����á���ɽ����������Ů��ü������
���������ʵĴ�ɽҲ��������ü����Լ��\n");
    	
    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        		"ʯ������������......�㲻�����ϣ���\n",
            		"ʯ����Ц��Ц���ֵ��������֪��������ʲô�ط�����\n",
            		"ʯ�����۹�ͻȻ���ʣ��������������֪����Ϊ�λ�����������\n",
        }) );

    	set("chat_chance_combat", 90);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.yaozhan" :),
        }) );
    	set("combat_exp", 99999999);
    	set("inquiry", ([
        	"�޻�" : 	(: kill_him :),
        	"�����" : 	(: kill_him :),
        	"���" : 	(: kill_him :),
        	"���ʮ����" : 	(: kill_him :),
        	"�Ϲ���" : 	(: kill_him :),
        	"����֮��": 	"����֮���ǹ������ı����˵�������һ�������ܡ�\n",
        	"������": 	"��������������ȹ��Ĺ�����\n",
        ]));
    	set_skill("unarmed", 200);
    	set_skill("blade", 250);
    	set_skill("charm", 200);
    	set_skill("force", 200);
    	set_skill("parry", 200);
    	set_skill("literate", 200);
    	set_skill("dodge", 200);
    	set_skill("kongshoudao", 200);
    	set_skill("wind-blade", 180);
    	set_skill("ghosty-force", 300);
    	set_skill("ghosty-steps", 100);

    	map_skill("unarmed", "kongshoudao");
    	map_skill("blade", "wind-blade");
    	map_skill("force", "ghosty-force");
    	map_skill("parry", "wind-blade");
    	map_skill("dodge", "ghosty-steps");

    	setup();
    	carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/guyuehan")->wield();
}


void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}

int kill_him()
{
        object me;
        me = this_player();
        command("say �������Ѿ�֪���ҵ������ˣ��� \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
}


int accept_object(object who, object ob)
{
	
	object item;
	if (ob->query("guizi")) {
		if (who->query_temp("zangbei/����_������")) {
			message_vision(CYN"
ʯ����΢΢һЦ�������⻬�������һ�㣬ū�Ҳ�����ѡ�����֮�ǡ�����������ô����\n"NOR,who);
			return 0;
		}
		
  if (ob->query("item_owner")!=who) {
			message_vision(CYN"
ʯ����΢΢һЦ�������⻬�������һ�㣬��"+RANK_D->query_respect(who)+"һ·���࣬ū��ԭӦ�ó�
������֮�ǡ���ֻ�Ǽ�����������������أ���\n"NOR,who);
			return 0;
		}
			
		message_vision(CYN"
ʯ����΢΢һЦ�������⻬�������һ�㣬��"+RANK_D->query_respect(who)+"һ·���࣬�⡺����֮�ǡ�
���������������Ѿã�������ԭ���������ɰ����ˡ���\n"NOR,who);
		item = new(__DIR__"obj/gem");
		item->move(who);
		item->set("item_owner",who);
		who->set_temp("zangbei/����_������",1);
		message_vision(CYN"$N�ݸ�$nһ��"+item->name()+CYN"��\n"NOR,this_object(),who);
		return 1;
	}
		
	if(ob->query("name")=="���ʳ���") {	// we let ppl get this saki again if lost.
		if (REWARD_D->riddle_check( who,"���˵ı���")!= 3 
			&& REWARD_D->riddle_check( who,"���˵ı���")!= 4 )
//		if(!who->query("���_quest3"))
		{
			message_vision("ʯ����������ü������ѵ����������ġ�������\n",who);
			return 0;
		}
		message_vision("ʯ������������������������Σ���ɫ��ò�ͣ���ƺ���������ࡣ����\n",who);
		call_out("give_saki",5,who);
		who->perform_busy(3);
		return 1;
	}
	
	return 0;
}


int give_saki(object who)
{
	object saki;
		
	if(!who || environment(who)!=environment()) return 0;
    
    message_vision(HIY"ʯ����ͻȻ��ȻһЦ����һҹ���ް��ն����������ͷ���λ"+ RANK_D->query_respect(who) +"����ƿ���
������������ū�ұ��������ˡ�\n\n"NOR,who);
	saki=new(__DIR__"obj/saki");
	if (!saki->move(who))
		saki->move(environment());
	REWARD_D->riddle_set( who, "���˵ı���",4);
	who->stop_busy();
//	who->set("���_quest4","�ɹ�");
	return 1;
}
