#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name(HIW"������"NOR, ({ "white ant", "ant" }) );
        set("long","
һ������ѩ�����ѵ��ˣ������ֿ��ֳ�����������ֻ�����ȴ����
��С�����������߰룬����һ�ߣ����Ƿ��ڳ��ϳ�һ�ӣ��������
һֻ�����ض��١�\n");
    	set("chat_chance",2);
		set("chat_msg",	({
				"�����ϰ�Ȼ��Ƴ����һ�ۣ����ֶ���������������������£�������
�ȼ������ɵ��Ṧ���������ۣ����������ҡ�̣ѩ�޺۰����ϡ���
�ﶼ�ǲ�ֵһ�ᡣ��\n",
"�����ϵ����������Ṧ���Ϸ���ϲ���Դ���ͬ���·�����˵�����Ƴ�
�������ʲô������ӣ������п�ȥ��һ����\n"
				})  );

        set("combat_exp", 400000);
	
		set_skill("dodge",150);
		set_skill("move",150);
		set_skill("unarmed",100);
		set_skill("shenji-steps",100);
		set_skill("nine-moon-steps",100);
		set_skill("nine-moon-claw",60);
		
		map_skill("unarmed","nine-moon-claw");
		map_skill("dodge","shenji-steps");
		map_skill("move","nine-moon-steps");
	
		set("perform_busy_u", "bat/dodge/shenji-steps/shenjimiaosuan");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

		setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{	
	object jinlian;
	if (ob->query("name")=="��粽������") 
	{
	 	REWARD_D->riddle_set( this_player(),"�ɹ�����/������",1);
	 	write("�����ϲ�м�ķ��˷������������¿���������ɫ���أ��Ȼ��̾����
�������Ҷ����Ȼ�����鴫�������µ�һ��Ȼ���Ǵ��ġ���\n");
    		command("thank "+this_player()->query("id"));
		if (mapp (this_player()->query("riddle/�ɹ�����")))
		if (sizeof(this_player()->query("riddle/�ɹ�����"))==4)
			REWARD_D->riddle_done( this_player(),"�ɹ�����",50,1);    		
    	return 1;
	}
	if (ob->query("name")=="�������") 
	{
		command("spank "+this_player()->query("id"));
	 	this_player()->set_temp("marks/whiteant",1);
	 	write("����������Ц���������˽��ң����˽��ҡ���\n");
    		return 1;
	}
	write("������������������ֵ��С���������ۡ���\n");
	return 0;
}
