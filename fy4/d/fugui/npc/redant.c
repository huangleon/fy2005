#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"������"NOR, ({ "red ant", "ant" }) );
        set("long","
�����ż�����ĺ��·�����ϸ�ĵط������֣����ֵĵط������ݣ�һ
�Ŷ˶������Ĺ�������ü��Զɽ��Ŀ�紺ˮ��Ц������ģ���Ũ�Ļ�
������ֻҪ�����ٷŴ�һ�������Ǹ���ɫ�����ˡ�\n");
        set("chat_chance",2);
		set("chat_msg",	({
		"������ҧ���촽��������ü����������ɽƧ������ô��Щ��֬���۶�\nû�У����ͷ����������ʵ��û������ѽ����\n",
		"������üĿ���Σ����������������˵��Ʒ����Ů�����ܹ����գ���Ӧ�����ԡ���\n"
		})  );

		set("gender","Ů��");
		set("age",22);
	        set("combat_exp", 300000);
	
		set("int",30);
		set("cor",30);
		
		set_skill("throwing",200);
		set_skill("feidao",100);
		set_skill("dodge",150);
		set_skill("move",150);
		map_skill("throwing","feidao");
		
		setup();
	        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/jinhua")->wield();

}

int accept_object(object who, object ob)
{	
	object jinlian;
	if (ob->query("name")==HIR "��֬"NOR) {		//10s
	 	command("thank "+this_player()->query("id"));
	 	this_player()->set_temp("marks/redant",1);
	 	message_vision("��������$N���˸����ۣ�������Ц����ͣ��\n", this_player());
    	return 1;
	}
	if (ob->query("name")=="���߹�" 
			&& ob->query("liquid/name")=="��ƷŮ����" 
			&& ob->query("liquid/remaining")>10 ){			// 10g
		command("thank "+this_player()->query("id"));
	 	REWARD_D->riddle_set( this_player(),"�ɹ�����/������",1);
	 	message_vision("�����ϸ��˵��̲�ס��������$Nһ�£�������Ц����ͣ��\n", this_player());
    	if (mapp (this_player()->query("riddle/�ɹ�����")))
		if (sizeof(this_player()->query("riddle/�ɹ�����"))==4)
			REWARD_D->riddle_done( this_player(),"�ɹ�����",50,1);	
    		
    	return 1;
    	}
	message_vision("�����϶���$NƲ��ƲС��������ⶫ������ʲô�ã���\n", this_player());
	return 0;
}
