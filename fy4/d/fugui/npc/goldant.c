#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"������"NOR, ({ "gold ant", "ant" }) );
        set("long","
�����ϴ��ż�����������·����������������ź��룬�۽��������ƣ�
����˭���Ὣ�����ɸ��������С���ӡ�\n");
    	set("chat_chance",2);
	set("chat_msg",	({
		"������¶��һ���ĳ���������ɫ���૵������Թű�������Ӣ�ۣ���
���Ͻ��ݺ����¶��꣬ȴ���ǰѲ���֮�����޷��õ���ʵ���ǲ����İ�����\n",
		"�������૵�������ɽ����̫���ӻ���ʲô����ֻ���Ҳ���������ı�������\n"
	})  );

        set("combat_exp", 1000000);
	
	set_skill("unarmed",100);
	set_skill("kongshoudao",100);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("ghosty-steps",100);
	
	map_skill("dodge","ghosty-steps");
	map_skill("unarmed","kongshoudao");
	
	set("chat_chance_combat",25);
	set("chat_msg_combat",	({
			(:perform_action,"unarmed.yaozhan":),
		}));
	
	setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{	
	int combat_exp,pot,score;
	if (ob->query("name")==HIG "������"NOR) 
	{
		REWARD_D->riddle_set( this_player(),"�ɹ�����/������",1);
		write("���������쳤Ц�������úúã���Ȼ����������ر����������������أ���\n");
		
		if (mapp (this_player()->query("riddle/�ɹ�����")))
		if (sizeof(this_player()->query("riddle/�ɹ�����"))==4)
			REWARD_D->riddle_done( this_player(),"�ɹ�����",50,1);
		return 1;		
	}
	if (ob->query("name")==HIG "���̽�"NOR) 
	{
		command("thank "+this_player()->query("id"));
		this_player()->set_temp("marks/goldant",1);
		write("�����ϺǺ�Ц����������������ر����ҾͲ��������ˡ���\n");
    		return 1;
	}
	write("������ҡ��ҡͷ���ٺ�һЦ������������ͭ������������Ҷ���һ��𡣡�\n");
	return 0;
}


				
